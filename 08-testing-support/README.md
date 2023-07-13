# Example Project: External testing frameworks

This project demonstrates best practices for testing support using external testing frameworks in CMake.

## What is Test-Driven Development (TDD)?

Test-Driven Development is a software development approach where tests are written before implementing the code. The TDD cycle typically involves the following steps:

1. **Write a Test**: Create a test case that describes the desired behavior or functionality.
2. **Run the Test**: Execute the test and verify that it fails as expected.
3. **Write the Code**: Implement the minimum code necessary to pass the test.
4. **Run the Test Again**: Execute the test suite to ensure the new test passes and existing tests remain passing.
5. **Refactor**: Optimize and improve the code while keeping all tests passing.
6. **Repeat**: Iterate through the cycle for additional features or enhancements.

## Writing Tests
To write tests using the chosen testing framework, follow these guidelines:

1. Keep your test code separate from your main source code. Place all test files in the tests directory.

2. Organize your tests into test cases. A test case is a logical grouping of related tests. Use the macros provided by the testing framework to define test cases and individual tests within them.

3. Use appropriate assertions provided by the testing framework to validate the expected behavior of your code. These assertions typically compare the actual output with the expected output.

4. Follow the test naming conventions recommended by the testing framework to ensure proper test discovery and execution.

## Continuous Integration (CI)

To ensure continuous testing, it's recommended to integrate testing into your CI pipeline. This ensures that tests are automatically executed whenever changes are made to your codebase. Tools like Jenkins, Travis CI, or GitLab CI/CD can be used for this purpose.

## Test Coverage

Consider measuring the code coverage of your tests. Code coverage indicates the percentage of your code that is exercised by tests. Tools like gcov or LLVM's Code Coverage can provide insights into your test coverage.

## Benefits of Using Google Test (gtest) and Catch2

### Google Test (gtest)

- **Mature Framework**: Google Test is a well-established and widely-used testing framework with a rich feature set.
- **Detailed Test Output**: gtest provides detailed test output and failure messages, aiding in troubleshooting and debugging.
- **Test Fixtures**: It supports test fixtures, allowing you to share common setup and teardown code among multiple tests.
- **Assertions**: gtest provides a variety of assertion macros to validate expected behavior and compare values.
- **Parameterized Tests**: It supports parameterized tests to run the same test logic with different input values.
- **Mocking and Test Doubles**: gtest has built-in support for mocking and test doubles, facilitating unit testing.

### Catch2

- **Simplicity**: Catch2 is known for its simplicity and minimalistic setup, making it easy to get started with.
- **Expressiveness**: It provides a clean and expressive syntax for writing tests, enhancing readability and maintainability.
- **BDD-Style Testing**: Catch2 supports Behavior-Driven Development (BDD) style testing, allowing tests to be written in a more human-readable format.
- **Powerful Test Matchers**: Catch2 offers a wide range of built-in test matchers to validate various conditions and data types.
- **Tagging and Filtering**: It enables tagging and filtering of tests, allowing selective test execution based on specific criteria.

## Getting Started

To get started with the examples, follow these steps:

1. Clone this repository: `git clone https://github.com/bagdoportfolio/cmake-concepts-examples.git`
2. Navigate to the desired example folder: `cd cmake-concepts-examples/<example-folder>`
3. Follow the instructions provided in the example's README to build and run the example.

Make sure you have Docker installed and properly configured on your system.


## Contributing

Contributions to this repository are welcome! If you have additional examples, improvements, or bug fixes, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on contributing.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.
