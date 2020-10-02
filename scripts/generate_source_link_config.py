#!/usr/bin/env python3

import argparse
import json
import subprocess
import os
from pathlib import Path
from pathlib import PureWindowsPath
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

def generate_config_custom( repo_dir: PathLike,
                            output_dir: PathLike,
                            repo: str,
                            commit_hash: str = ""):
    if (not commit_hash):
        commit_hash = subprocess.check_output("git rev-parse --short HEAD", shell=True).decode('ascii').strip()

    repo_dir = Path(repo_dir).resolve()
    assert(repo_dir.exists() and repo_dir.is_dir())

    output_dir = Path(output_dir).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)

    output_file = output_dir/'source_link.json'
    output_file.unlink(missing_ok=True)

    data = {}
    data['documents'] = { f'{PureWindowsPath(repo_dir)}*': f'https://raw.githubusercontent.com/{repo}/{commit_hash}/*' }

    with open(output_file, 'w') as output:
        json.dump(data, output)

    print(f"Generated file: {output_file}")

if __name__ == '__main__':
    repo_dir = get_cwd_repo_root()
    output_dir = repo_dir/"_result"/"AllPlatforms"/"generated"

    parser = argparse.ArgumentParser(description='Generate source link configuration file')
    parser.add_argument('--output_dir', default=output_dir)
    parser.add_argument('--repo')
    parser.add_argument('--commit_hash', default="")

    args = parser.parse_args()

    call_wrapper.final_call_decorator(
        "Generating source link configuration file",
        "Source link configuration file was successfully generated!",
        "Source link configuration file failed!"
    )(
    generate_config_custom
    )(
        repo_dir,
        args.output_dir,
        args.repo,
        args.commit_hash
    )
