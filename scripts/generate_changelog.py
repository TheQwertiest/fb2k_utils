#!/usr/bin/env python3

import argparse
import json
import os
import subprocess
import re
from pathlib import Path
from typing import Union

import call_wrapper

PathLike = Union[str, Path]

def get_current_repo(root_dir: PathLike):
    cmd_git_get_remote = [
        'git',
        'config',
        '--get',
        'remote.origin.url'
    ]
    print('> ' + ' '.join(cmd_git_get_remote))
    url = subprocess.check_output(cmd_git_get_remote, text=True, env=os.environ, cwd=root_dir)
    return url.replace('.git', '').strip()

def generate(repo_dir: PathLike, output=True):
    if not repo_dir:
        repo_dir = Path(os.getcwd()).absolute()
        
    repo = get_current_repo(repo_dir)

    cmd_list_issues = ' '.join([
        'gh',
        'api',
        'repos/:owner/:repo/issues',
        '--method=GET',
        '-F', 'labels="fixed in dev build"',
        '-F', 'state=open'])
    print('> ' + cmd_list_issues)
    json_str = subprocess.check_output(cmd_list_issues, text=True, env=os.environ, cwd=repo_dir)

    issues = json.loads(json_str)
    if not issues:
        print('No relevant issues were found')
        return

    def has_label(labels, name):
        for l in labels:
            if l['name'] == name:
                return True
        return False

    fixed_enhancements = [i for i in issues if has_label(i['labels'], 'enhancement')]
    fixed_bugs = [i for i in issues if has_label(i['labels'], 'bug')]

    changelog = ''
    if fixed_enhancements:
        changelog += '### Added\n'
        for i in fixed_enhancements:
            changelog += f'- {i["title"]} (#{i["number"]}).\n'
        changelog += '\n'
    if fixed_bugs:
        changelog += '### Fixed\n'
        for i in fixed_bugs:
            changelog += f'- {i["title"]} (#{i["number"]}).\n'
        changelog += '\n'

    changelog = re.sub(
        r'#([0-9]+)',
        '[' + r'#\1' + ']' + f'({repo}/issues/' + r'\1' + ')',
        changelog
    )

    if output:
        print(changelog)
    return changelog

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate changelog output')
    parser.add_argument('--repo_dir', default=Path(os.getcwd()).absolute())

    args = parser.parse_args()

    call_wrapper.final_call_decorator(
        "Generating",
        "Generated successfully!",
        "Generation failed!"
    )(
    generate
    )(
        args.repo_dir
    )

