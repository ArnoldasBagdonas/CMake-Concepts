import os
import subprocess
import re

def get_build_directory(script_path):
    # Get the root folder path
    root_folder = os.path.dirname(script_path)

    # Assuming the build folder is named "build" in the root folder
    build_directory = os.path.join(root_folder, "build")

    return build_directory

def run_ctest_and_parse_results(build_dir):
    test_results_string = {}
    try:
        # Run ctest and capture its output
        test_results_string = subprocess.check_output(["ctest"], cwd=build_dir, text=True, stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        print(f"Error while running ctest. Exit code: {e.returncode}")
        #print(f"Captured output:")
        #print(e.output)
        test_results_string = e.output

    # Save the ctest output to a file
    test_results_file = os.path.join(build_dir, "test_results.txt")
    with open(test_results_file, "w") as file:
        file.write(test_results_string)

    # Regular expression pattern
    pattern = r"Test\s+#(\d+):\s+(\S+)\s+(?:.*?\*+|\.+\s+|\.+\*+|.*?)(\S+)\s+\d+\.\d+\s+sec"
    # Find all matches in the string
    matches = re.findall(pattern, test_results_string)
    # Format and print the test results
    for test_number, test_name, test_status in matches:
        formatted_output = f"Test #{test_number};{test_name};{test_status}"
        print(formatted_output)

if __name__ == "__main__":
    # Get the script's location
    script_path = os.path.abspath(__file__)

    # Get the build directory path
    build_directory = get_build_directory(script_path)

    # Call the function to run ctest and parse results
    run_ctest_and_parse_results(build_directory)
