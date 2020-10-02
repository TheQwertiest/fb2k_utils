#!/usr/bin/env python3

import argparse
import json
import os
import subprocess
from pathlib import Path
from typing import Union

import call_wrapper

PathLike = Union[str, Path]

def generate(repo_dir: PathLike):
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
    
    print('')
    if fixed_enhancements:
        print('### Added')
        for i in fixed_enhancements:
            print(f'- {i["title"]} (#{i["number"]})')
        print('')
    if fixed_bugs:
        print('### Fixed')
        for i in fixed_bugs:
            print(f'- {i["title"]} (#{i["number"]})')
        print('')

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

