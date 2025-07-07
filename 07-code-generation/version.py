import os
import sys
import socket
from subprocess import Popen, PIPE
import argparse

def create(foldername, filename, content, keep_old):
    print(f"create '{filename}' in '{foldername}'")
    if foldername and not os.path.exists(foldername):
        os.makedirs(foldername, exist_ok=True)

    file_path = os.path.join(foldername, filename)
    if os.path.exists(file_path) and keep_old:
        with open(file_path, 'r') as f:
            old_content = f.read()
        if old_content == content:
            return False  # no change
    with open(file_path, 'w') as f:
        f.write(content)
    return True  # file changed or created

def git_id(working_dir):
    try:
        Popen(['git', 'status'], cwd=working_dir, stdout=PIPE, stderr=PIPE).communicate()
        command = ['git', 'describe', '--abbrev=0', '--match="__"', '--dirty', '--always']
        p = Popen(command, cwd=working_dir, stdout=PIPE, stderr=PIPE)
        line = p.stdout.readline().strip()
        p.stdout.close()
        p.stderr.close()
        result = line.decode(sys.stdout.encoding)
        if not result:
            raise Exception("Empty git id")
        return result
    except Exception as e:
        print(f"ERROR: Failed to get git commit id: {e}", file=sys.stderr)
        sys.exit(1)

def git_url(working_dir):
    try:
        command = ['git', 'config', '--get', 'remote.origin.url']
        p = Popen(command, cwd=working_dir, stdout=PIPE, stderr=PIPE)
        line = p.stdout.readline().strip()
        p.stdout.close()
        p.stderr.close()
        result = line.decode(sys.stdout.encoding)
        if not result:
            raise Exception("Empty git url")
        return result
    except Exception as e:
        print(f"ERROR: Failed to get git repository url: {e}", file=sys.stderr)
        sys.exit(1)

def main():
    scriptfilename = os.path.basename(__file__)
    parser = argparse.ArgumentParser(scriptfilename)

    parser.add_argument('--print-dependencies', action='store_true', help='Print semicolon separated lists of dependency files')
    parser.add_argument('--print-outputs', action='store_true', help='Print semicolon separated lists of output files')
    parser.add_argument('--genpattern', type=str, help='Generator output script template')
    parser.add_argument('--output', type=str, default="version.h", help='Output file')
    parser.add_argument('--dir', type=str, help='Output directory')
    parser.add_argument('--name', type=str, default="", help='Project name')
    parser.add_argument('--major', type=str, default="", help='Project version major')
    parser.add_argument('--minor', type=str, default="", help='Project version minor')
    parser.add_argument('--patch', type=str, default="", help='Project version patch')
    parser.add_argument('--keep-old', action='store_true', help='Do not create file if already exists and content is the same')
    parser.add_argument('--check-changes', action='store_true', help='Check that some of the files really change')

    args = parser.parse_args()

    if len(sys.argv) == 1:
        parser.print_help()
        sys.exit(0)

    if args.print_dependencies:
        dependencies = [__file__]
        if args.genpattern:
            dependencies.append(args.genpattern)
        sys.stdout.write(';'.join(dependencies))
        sys.exit(0)

    if args.print_outputs:
        output_items = [args.output] if args.output else []
        outputs = [os.path.join(args.dir, item) for item in output_items] if args.dir else output_items
        sys.stdout.write(';'.join(outputs))
        sys.exit(0)

    print(f"{scriptfilename} ({args.genpattern}, {args.output}, {args.dir})")

    git_dir = os.path.dirname(os.path.abspath(args.genpattern)) if args.genpattern else os.getcwd()

    format_dict = {
        "PROJECT_NAME": args.name,
        "PROJECT_VERSION_MAJOR": args.major,
        "PROJECT_VERSION_MINOR": args.minor,
        "PROJECT_VERSION_PATCH": args.patch,
        "PROJECT_GIT_COMMIT_ID": git_id(git_dir),
        "PROJECT_GIT_REPOSITORY_URL": git_url(git_dir),
        "PROJECT_BUILD_MACHINE": socket.gethostname(),
    }

    pattern = """
#include "version.hpp"

// Major version number
const int PROJECT_VERSION_MAJOR={PROJECT_VERSION_MAJOR};

// Minor version number
const int PROJECT_VERSION_MINOR={PROJECT_VERSION_MINOR};

// Patch level
const int PROJECT_VERSION_PATCH={PROJECT_VERSION_PATCH};

const char PROJECT_NAME[] =              "{PROJECT_NAME}";
const char PROJECT_GIT_COMMIT_ID[]=      "{PROJECT_GIT_COMMIT_ID}";
const char PROJECT_BUILD_MACHINE[]=      "{PROJECT_BUILD_MACHINE}";
const char PROJECT_GIT_REPOSITORY_URL[]= "{PROJECT_GIT_REPOSITORY_URL}";
const char PROJECT_BUILD_DATE_TIME[] =   __DATE__ " " __TIME__;

// Human-readable version string.
const char PROJECT_VERSION_STRING[]=     "{PROJECT_NAME} v{PROJECT_VERSION_MAJOR}.{PROJECT_VERSION_MINOR}.{PROJECT_VERSION_PATCH}-{PROJECT_GIT_COMMIT_ID}";
"""

    if args.genpattern:
        with open(args.genpattern, 'r') as f:
            pattern = f.read()

    content = pattern.format(**format_dict)
    changed = create(args.dir, args.output, content, args.keep_old)

    if args.check_changes and not changed:
        sys.exit("No changes!")

if __name__ == "__main__":
    main()
