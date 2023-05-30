#!/usr/bin/env python3

import argparse
import os
import semver
import subprocess
from pathlib import Path
from typing import Union

import call_wrapper

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

def get_version(repo_dir: PathLike):
    version_file = repo_dir/'VERSION'
    if not version_file.exists():
        raise ValueError('Repo is missing VERSION file')
    
    version = ''
    with open(version_file, 'r') as input:
        version = input.read().strip()
        
    return semver.VersionInfo.parse(version)

def generate_props_custom( repo_dir: PathLike,
                           output_dir: PathLike):
    output_dir = Path(output_dir).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)

    output_file = output_dir/'Directory.Build.props'
    output_file.unlink(missing_ok=True)
    
    version = get_version(repo_dir)
    commit_hash = subprocess.check_output("git rev-parse --short HEAD", shell=True, cwd=repo_dir).decode('ascii').strip()

    with open(output_file, 'w') as output:
        output.write(f"<!-- Generated by '{Path(__file__).name}'-->\n")
        output.write("<Project>\n")
        output.write("  <PropertyGroup>\n")
        output.write(f"    <VersionPrefix>{version.major}.{version.minor}.{version.patch}</VersionPrefix>\n")
        if version.prerelease:
            output.write(f"    <VersionSuffix>{version.prerelease}+{commit_hash}</VersionSuffix>\n")
        output.write("  </PropertyGroup>\n")
        output.write("</Project>\n")

    print(f"Generated file: {output_file}")

if __name__ == '__main__':
    repo_dir = get_cwd_repo_root()
    output_dir = repo_dir/"_result"/"AllPlatforms"/"generated"

    parser = argparse.ArgumentParser(description='Generate props file with version')
    parser.add_argument('--output_dir', required=True)

    args = parser.parse_args()

    call_wrapper.final_call_decorator(
        "Generating props file with version",
        "Props file was successfully generated!",
        "Props file generation failed!"
    )(
    generate_props_custom
    )(
        repo_dir,
        args.output_dir
    )