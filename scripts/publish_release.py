#!/usr/bin/env python3

import argparse
import json
import os
import semver
import subprocess
import shutil
import tempfile
from pathlib import Path
from typing import Union

import call_wrapper
import generate_changelog

PathLike = Union[str, Path]

def get_cwd_repo_root():
    repo_dir = Path(os.getcwd()).absolute()
    cmd_get_root = [
        'git',
        '-C',
        str(repo_dir),
        'rev-parse',
        '--show-toplevel'
    ]

    root = subprocess.check_output(cmd_get_root, text=True, env=os.environ, cwd=repo_dir).strip()
    return Path(root)

def git_push_new_version(repo_dir: PathLike,
                         version_file: PathLike,
                         release_version):
    version = ''
    with open(version_file, 'r') as input:
        version = input.read().strip()

    if version == release_version:
        return

    with open(version_file, 'w') as output:
        output.write(release_version + '\n')

    cmd_git_add = [
        'git',
        'add',
        'VERSION'
    ]
    print('> ' + ' '.join(cmd_git_add))
    subprocess.check_call(cmd_git_add, env=os.environ, cwd=repo_dir)

    cmd_git_commit = [
        'git',
        'commit',
        '-m', f'v{release_version}'
    ]
    print('> ' + ' '.join(cmd_git_commit))
    subprocess.check_call(cmd_git_commit, env=os.environ, cwd=repo_dir)

    cmd_git_push = [
        'git',
        'push'
    ]
    print('> ' + ' '.join(cmd_git_push))
    subprocess.check_call(cmd_git_push, env=os.environ, cwd=repo_dir)

def git_commit_new_beta_version(repo_dir: PathLike,
                                version_file: PathLike,
                                old_version):
    with open(version_file, 'w') as output:
        new_ver = old_version.bump_patch()
        new_ver = new_ver.replace(prerelease='beta')
        output.write(str(new_ver) + '\n')

    cmd_git_add = [
        'git',
        'add',
        'VERSION'
    ]
    print('> ' + ' '.join(cmd_git_add))
    subprocess.check_call(cmd_git_add, env=os.environ, cwd=repo_dir)

    cmd_git_commit = [
        'git',
        'commit',
        '-m', 'Version up'
    ]
    print('> ' + ' '.join(cmd_git_commit))
    subprocess.check_call(cmd_git_commit, env=os.environ, cwd=repo_dir)

def git_publish_release(repo_dir: PathLike,
                        release_version):
    changelog = generate_changelog.generate(repo_dir, output=False)

    temp_dir = ''
    try:
        temp_dir = tempfile.mkdtemp()
        temp_file = Path(temp_dir)/'changelog.md'
        with open(temp_file, 'w') as output:
            output.write(changelog)
        cmd_create_release = [
            'gh',
            'release',
            'create',
            f'v{str(release_version)}',
            '-F', str(temp_file.absolute())]
        print('> ' + ' '.join(cmd_create_release))
        subprocess.check_call(cmd_create_release, env=os.environ, cwd=repo_dir)
    finally:
        if temp_dir:
            shutil.rmtree(temp_dir)

def publish(repo_dir: PathLike,
            release_version):
    if not repo_dir:
        repo_dir = get_cwd_repo_root()
    if not release_version:
        raise ValueError('`release_version` is empty')
    parsed_ver = semver.VersionInfo.parse(release_version)

    version_file = repo_dir/'VERSION'
    if not version_file.exists():
        raise ValueError('Repo is missing VERSION file')

    git_push_new_version(repo_dir, version_file, release_version)
    git_publish_release(repo_dir, release_version)
    git_commit_new_beta_version(repo_dir, version_file, parsed_ver)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Publish GitHub release')
    parser.add_argument('--repo_dir', default=get_cwd_repo_root())
    parser.add_argument('release_version', type=str, help='release version')

    args = parser.parse_args()

    call_wrapper.final_call_decorator(
        "Publishing",
        "Published successfully!",
        "Publishing failed!"
    )(
    publish
    )(
        args.repo_dir,
        args.release_version
    )

