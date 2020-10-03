#!/usr/bin/env python3

import argparse
import json
import os
import subprocess
from pathlib import Path
from typing import Union

import call_wrapper

PathLike = Union[str, Path]

def close(repo_dir: PathLike):
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

    def get_cmd_remove_label(issue_number):
        return [
            'gh',
            'api',
            f'/repos/:owner/:repo/issues/{str(issue_number)}/labels/fixed%20in%20nightly',
            '--method=DELETE',
            '--silent']
    def get_cmd_close_issue(issue_number):
        return [
            'gh',
            'api',
            f'/repos/:owner/:repo/issues/{str(issue_number)}',
            '--method=PATCH',
            '-Fstate=close',
            '--silent']

    for i in issues:
        cmd_close_issue = get_cmd_close_issue(i['number'])
        cmd_remove_label = get_cmd_remove_label(i['number'])

        print('> ' + ' '.join(cmd_close_issue))
        subprocess.check_call(cmd_close_issue, env=os.environ, cwd=repo_dir)

        print('> ' + ' '.join(cmd_remove_label))
        subprocess.check_call(cmd_remove_label, env=os.environ, cwd=repo_dir)

    print('All issues were closed')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Close all fixed issues')
    parser.add_argument('--repo_dir', default=Path(os.getcwd()).absolute())

    args = parser.parse_args()

    call_wrapper.final_call_decorator(
        "Closing issues",
        "Issues were successfully closed!",
        "Failed to close all issues!"
    )(
    close
    )(
        args.repo_dir
    )

