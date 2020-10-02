#!/usr/bin/env python3

import argparse
import json
import os
import subprocess
from pathlib import Path
from typing import Union

import call_wrapper

PathLike = Union[str, Path]

def generate(repo_dir: PathLike, output=True):
    if not repo_dir:
        repo_dir = Path(os.getcwd()).absolute()

    cmd_list_issues = ' '.join([
        'gh',
        'api',
        'repos/:owner/:repo/issues',
        '--method=GET',
        '-F', 'labels="fixed in nightly"',
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

    changelog = '# Changelog\n\n'
    if fixed_enhancements:
        changelog += '### Added\n'
        for i in fixed_enhancements:
            changelog += f'- {i["title"]} (#{i["number"]})\n'
        changelog += '\n'
    if fixed_bugs:
        changelog += '### Fixed\n'
        for i in fixed_bugs:
            changelog += f'- {i["title"]} (#{i["number"]})\n'
        changelog += '\n'

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

