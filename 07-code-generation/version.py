import os
import sys
import socket
from subprocess import Popen, PIPE
import argparse

scriptfilename = str(os.path.basename(__file__))
parser = argparse.ArgumentParser(scriptfilename)

parser.add_argument(
  '--print-dependencies',
  action='store_true',
  help='Print semicolon separated lists of dependency files', 
)

parser.add_argument(
  '--print-outputs',
  action='store_true',
  help='Print semicolon separated lists of output files',
)

parser.add_argument(
  '--genpattern',
  type=str,
  help='Generator output script template', 
)

parser.add_argument(
  '--output',
  type=str,
  default= "version.h",
  help='Output file', 
)

parser.add_argument(
  '--dir',
  type=str,
  help='Output directory',
)

parser.add_argument(
  '--name',
  type=str,
  default= "",
  help='Project name',
)

parser.add_argument(
  '--major',
  type=str,
  default= "",
  help='Project version major',
)

parser.add_argument(
  '--minor',
  type=str,
  default= "",
  help='Project version minor',
)

parser.add_argument(
  '--patch',
  type=str,
  default= "",
  help='Project version patch',
)

parser.add_argument(
  '--keep-old',
  action='store_true',
  help='Do not create file if already exists and content is the same'
)

parser.add_argument(
  '--check-changes',
  action='store_true',
  help='Check that some of the files really change'
)

args = parser.parse_args()

change = False
def create(foldername, filename, content):
  print("create '{filename}' in '{foldername}'".format(**locals()))
  if (not foldername == "") and (not os.path.exists(foldername)):
    os.makedirs(foldername, exist_ok=True)
  file = os.path.join(foldername, filename)
  if os.path.exists(file) and args.keep_old:
    old_content = open(file, 'r').read()
    if old_content == content:
      return
  global change
  change = True
  open(file, 'w').write(content)

def git_id(working_dir):
    try:
        # Work around an apparent bug in git:
        # http://comments.gmane.org/gmane.comp.version-control.git/178169
        p = Popen(['git', 'status'], cwd=working_dir, stdout=PIPE, stderr=PIPE)
        p.stderr.close()
        p.stdout.close()

        command = ['git', 'describe', '--abbrev=0', '--match="__"', '--dirty', '--always']
        p = Popen(command, cwd=working_dir, stdout=PIPE, stderr=PIPE)
        line = p.stdout.readline().strip()
        p.stderr.close()
        p.stdout.close()
        return line.decode(sys.stdout.encoding)

    except Exception as e:
        return "Failed"

def git_url(working_dir):
    try:
        command = ['git', 'config', '--get', 'remote.origin.url']
        p = Popen(command, cwd=working_dir, stdout=PIPE, stderr=PIPE)
        line = p.stdout.readline().strip()
        p.stderr.close()
        p.stdout.close()
        return line.decode(sys.stdout.encoding)
    except Exception as e:
        return "Failed"

if args.print_dependencies:
  dependencies = []
  #add phyton script
  dependencies.append(__file__)
  #add genpattern
  if args.genpattern:
    dependencies.append(args.genpattern)
  #add hard-coded files (including full path!!!)
  #dependencies.append(infilename1)
  # . . .
  #dependencies.append(infilenameN)
  #format dependency list
  sys.stdout.write(';'.join(dependencies))
  sys.exit(0)

elif args.print_outputs:
  output_items = []
  #add output file
  if args.output:
    output_items.append(args.output)
  #add hard-coded files
  #output_items.append(outfilename1)
  # . . .
  #output_items.append(outfilenameN)
  #add full path (dir)
  outputs = output_items
  if args.dir:
      outputs = []
      for item in output_items:
        outputs.append(str(os.path.join(args.dir, item)))
  #format outputs list
  sys.stdout.write(';'.join(outputs))
  sys.exit(0)

else:
  print("{scriptfilename} ({args.genpattern}, {args.output}, {args.dir})".format(**globals()))
  # CreaDefine variables used in genpattern
  PROJECT_NAME = args.name
  PROJECT_VERSION_MAJOR = args.major
  PROJECT_VERSION_MINOR = args.minor
  PROJECT_VERSION_PATCH = args.patch
  #PROJECT_GIT_COMMIT_ID = git_describe( os.getcwd() )
  PROJECT_GIT_COMMIT_ID = git_id( args.dir )
  PROJECT_GIT_REPOSITORY_URL = git_url( args.dir )
  PROJECT_BUILD_MACHINE = socket.gethostname()
  # Create default pattern
  pattern = """
#include "version.hpp"

// Major version number
const int PROJECT_VERSION_MAJOR={PROJECT_VERSION_MAJOR};

// Minor version number
const int PROJECT_VERSION_MINOR={PROJECT_VERSION_MINOR};

// Patch level. Patch level is incremented on maintenance branch releases and reset to 0 for each new major.minor release.
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
    with open(args.genpattern, 'r') as file:
      pattern = file.read()
  
  content = pattern.format(**globals())

  create(args.dir, args.output, content)

  # Check changes
  if (not change) and args.check_changes:
    sys.exit('No changes!')

