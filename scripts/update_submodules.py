#!/usr/bin/env python3

import subprocess
import os
from pathlib import Path

import call_wrapper

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

def update_submodule(root_dir, submodule_name):
    print(f"Updating {submodule_name}...")
    try:
        subprocess.check_call(f"git submodule update --init --recursive --remote -- submodules/{submodule_name}", cwd=root_dir, shell=True)
    except subprocess.CalledProcessError:
        submodule_path = root_dir/"submodules"/submodule_name
        # Shallow copy does not honour default branch config
        subprocess.check_call("git config --add remote.origin.fetch +refs/heads/*:refs/remotes/origin/*", cwd=submodule_path, shell=True)
        subprocess.check_call("git fetch --all", cwd=submodule_path, shell=True)
        subprocess.check_call(f"git submodule update --init --force --recursive --remote -- submodules/{submodule_name}", cwd=root_dir, shell=True)

def update(root_dir=None):
    if not root_dir:
        root_dir = get_cwd_repo_root()

    subprocess.check_call("git submodule sync", cwd=root_dir, shell=True)

    for subdir in [f for f in (root_dir/"submodules").iterdir() if f.is_dir()]:
        update_submodule(root_dir, subdir.name)

if __name__ == '__main__':
    call_wrapper.final_call_decorator(
        "Updating submodules",
        "Updating submodules: success",
        "Updating submodules: failure!"
    )(update)()
