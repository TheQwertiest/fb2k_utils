#!/usr/bin/env python3

import subprocess
from pathlib import Path

import call_wrapper

def patch(root_dir):
    cur_dir = Path(__file__).parent.absolute()
    if not root_dir:
        root_dir = cur_dir.parent
    patches = [cur_dir/"patches"/p for p in ["foobar2000.patch", "pfc.patch"]]
    for p in patches:
        assert(p.exists() and p.is_file())

    subprocess.check_call(f"git apply --ignore-whitespace {' '.join(str(p) for p in patches)}", cwd=root_dir, shell=True)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Patch fb2k submodules')
    parser.add_argument('--root_dir', default=Path(os.getcwd()).absolute())

    args = parser.parse_args()

    call_wrapper.final_call_decorator(
        "Patching submodules",
        "Patching submodules: success",
        "Patching submodules: failure!"
    )(patch)(args.root_dir)
