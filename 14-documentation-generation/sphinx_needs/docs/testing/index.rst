Testing
============================================
- Definition: A set of conditions or variables under which a tester will determine
  whether a system under test satisfies requirements or works correctly.

Static Code Analysis
--------------------------------------------
- **Purpose**:

  - **Code Quality Improvement**: The primary purpose of static code analysis is to
    improve the overall quality of code by identifying potential issues, vulnerabilities,
    and areas for improvement without executing the code.
  - **Early Issue Detection**: It helps catch coding issues early in the development process,
    reducing the likelihood of defects and security vulnerabilities making their way into the
    final product.
  - **Coding Standards Compliance**: Static code analysis checks code against predefined coding
    standards, ensuring that the codebase adheres to consistent and agreed-upon coding practices.

- **Scope**:

  - **Entire Codebase**: Static code analysis covers the entire codebase or specific portions of
    it, depending on the configuration and focus of the analysis.
  - **Code Structure**: It examines the structure, syntax, and organization of the code to identify
    issues related to readability, maintainability, and potential bugs.

- **Important Points**:

  - **Continuous Integration (CI)**: Static code analysis is often integrated into CI/CD
    pipelines to automate the analysis process whenever there are code changes. This ensures
    that issues are caught early in the development lifecycle.
  - **Risk Mitigation**: Static code analysis contributes to risk mitigation by identifying
    potential issues before the code is executed, reducing the likelihood of critical defects
    in production.
  - **Efficiency**: It offers an efficient way to scan large codebases quickly, providing insights
    into code quality without the need for manual code review of every line.
  - **Developer Feedback**: Static code analysis tools provide feedback to developers directly
    within their development environment, allowing them to address issues promptly.
  - **Code Review Support**: Static code analysis complements code reviews by automatically
    identifying certain types of issues, leaving more time for reviewers to focus on higher-level
    concerns.
  - **Educational Tool**: Static code analysis can serve as an educational tool for developers,
    helping them understand and adopt best practices.


Unit Tests
--------------------------------------------
- **Purpose**:

  - **Isolation of Units**: The primary purpose of unit testing is to verify that
    individual units or components of a software system function as designed in isolation.
  - **Early Error Detection**: It helps identify and address defects or errors in the
    smallest units of code early in the development process.
  - **Code Quality**: Unit testing contributes to code quality by ensuring that each unit
    performs its specific functionality correctly.

- **Scope**:

  - **Smallest Testable Units**: Unit testing focuses on the smallest testable parts of
    the software, which can include functions, methods, or classes.
  - **Internal Logic**: It assesses the internal logic, data structures, and the flow of
    control within individual units.

- **Important Points**:

  - **Test Scenarios**: Test cases are created based on the expected behavior of the unit,
    often derived from the unit's specifications or requirements.
  - **Positive and Negative Testing**: Unit tests include positive testing to validate
    correct behavior and negative testing to verify that the unit handles erroneous
    conditions appropriately.
  - **Test-Driven Development (TDD)**: TDD is a development practice where developers write
    unit tests before implementing the corresponding code. The goal is to guide the
    development process and ensure that the code meets the specified requirements.
  - **Integration with CI/CD**: Unit tests are often integrated into continuous integration
    (CI) pipelines to ensure that they are executed automatically whenever there are code
    changes. This helps catch issues early in the development process.
  - **Modular Code**: Unit testing encourages the development of modular and maintainable
    code by validating the correctness of individual units.
  - **Facilitates Refactoring**: With a comprehensive suite of unit tests, developers can
    refactor code confidently, knowing that the tests will catch regressions.
  - **Fast Execution**: Unit tests are designed to execute quickly, allowing developers to
    receive rapid feedback on the correctness of their code.


.. test:: User Authentication Positive Test
  :id: UT_001
  :status: open
  :links: IMPL_001

  - **Input**: Valid username and password.
  - **Expected Outcome**: Authentication successful.


.. test:: User Authentication Negative Test - Incorrect Password
  :id: UT_002
  :status: open
  :links: IMPL_001
   
  - **Input**: Valid username with an incorrect password.
  - **Expected Outcome**: Authentication fails.


.. test:: User Authentication Negative Test - User Not Found
  :id: UT_003
  :status: open
  :links: IMPL_001
   
  - **Input**: Invalid username.
  - **Expected Outcome**: Authentication fails.


.. test:: Add Book Positive Test
  :id: UT_004
  :status: open
  :links: IMPL_002
   
  - **Input**: Valid book details.
  - **Expected Outcome**: Book is successfully added to the library catalog.


.. test:: Add Book Negative Test - Duplicate Book
  :id: UT_005
  :status: open
  :links: IMPL_002
   
  - **Input**: Attempt to add a book that already exists.
  - **Expected Outcome**: Book addition fails with a duplicate entry error.


.. test:: Borrow Book Positive Test
  :id: UT_006
  :tags: mvp
  :status: open
  :links: IMPL_003
   
  - **Input**: Valid user and book details.
  - **Expected Outcome**: User successfully borrows the book.


.. test:: Borrow Book Negative Test - Book Not Available
  :id: UT_007
  :tags: mvp
  :status: open
  :links: IMPL_003
   
  - **Input**: Attempt to borrow a book that is not available.
  - **Expected Outcome**: Borrowing fails with an "unavailable" status.


.. test:: Return Book Positive Test
  :id: UT_008
  :tags: mvp
  :status: open
  :links: IMPL_004
   
  - **Input**: Valid user and book details for a borrowed book.
  - **Expected Outcome**: User successfully returns the book.


.. test:: Return Book Negative Test - Invalid Book
  :id: UT_009
  :tags: mvp
  :status: open
  :links: IMPL_004
   
  - **Input**: Attempt to return a book that the user did not borrow.
  - **Expected Outcome**: Return fails with an "invalid return" status.


.. test:: Search Books Positive Test - Exact Match
  :id: UT_010
  :status: open
   
  - **Input**: Valid search query matching a book exactly.
  - **Expected Outcome**: System returns the book in the search results.


.. test:: Search Books Positive Test - Partial Match
  :id: UT_011
  :status: open
   
  - **Input**: Valid search query with partial book details.
  - **Expected Outcome**: System returns relevant books in the search results.
  

.. test:: Search Books Negative Test - No Match
  :id: UT_012
  :status: open
   
  - **Input**: Search query with no matching books.
  - **Expected Outcome**: System returns an empty result set.


Functional Tests
--------------------------------------------
- **Purpose**:

  - **Verification of Requirements**: Functional testing aims to verify that the
    software system functions according to the specified requirements and functional
    specifications.
  - **Validation of Features**: It ensures that all features and functionalities
    work as intended and meet the user's expectations.
  - **End-User Perspective**: The primary focus is on evaluating the system from
    an end-user perspective, validating user interfaces, interactions, and overall
    user experience.

- **Scope**:

  - **Entire System**: Functional testing covers the entire system or application,
    including all integrated components, to ensure that the software as a whole
    performs its intended functions.
  - **Business Processes**: It assesses whether the software supports and executes
    the business processes it is designed for, including data processing, input
    validation, and output generation.
  - **Integration Points**: Functional testing includes testing the integration
    points between different modules or components to ensure seamless communication
    and data flow.

- **Important Points**:

  - **User Expectations**: Functional testing is crucial for ensuring that the
    software aligns with user expectations and business requirements.
  - **Test Scenarios**: Test cases are derived from functional specifications
    and user requirements, often in the form of test scenarios that mimic
    real-world usage of the software.
  - **Positive and Negative Testing**: Test cases cover positive scenarios to
    verify that the software behaves as expected under normal conditions, as
    well as negative scenarios to identify potential issues and error-handling
    capabilities.
  - **Bug Identification**: It helps identify functional defects, inconsistencies,
    or deviations from the specified requirements.
  - **Validation of Use Cases**: Functional testing validates that the software
    handles various use cases correctly and reliably.
  - **Coverage**: Testers strive to achieve comprehensive test coverage to ensure
    that all aspects of the system's functionality are examined.
  - **Test Automation Tools**: Functional testing can involve the use of test
    automation tools to automate repetitive test cases, especially for regression
    testing.
  - **Manual Testing**: Manual testing is also common in functional testing,
    especially for exploratory testing and usability evaluation.

.. test:: User Authentication Positive Scenario - Successful Login
  :id: FT_001
  :status: open
  :links: IMPL_001

  - **Steps**:

    1. Open the application and navigate to the login screen.
    2. Enter valid user credentials (username and password).
    3. Click on the login button.

  - **Expected Outcome**: Verify that the system allows access to the user's
    account dashboard.


.. test:: User Authentication Negative Scenario - Invalid Credentials
  :id: FT_002
  :status: open
  :links: IMPL_001

  - **Steps**:

    1. Open the application and navigate to the login screen.
    2. Enter invalid user credentials.
    3. Click on the login button.
    
  - **Expected Outcome**: Verify that the system displays an appropriate error message.


.. test:: User Authentication Negative Scenario - Account Lockout
  :id: FT_003
  :status: open
  :links: IMPL_001

  - **Steps**: Attempt to log in with incorrect credentials multiple times.
    
  - **Expected Outcome**: Verify that the system locks the account after a predefined
    number of unsuccessful login attempts.


.. test:: Add Book Positive Scenario - Adding a New Book
  :id: FT_004
  :status: open

  - **Steps**:

    1. Log in as an administrator.
    2. Navigate to the library catalog section.
    3. Click on the "Add New Book" button.
    4. Fill in all the required information for a new book.
    5. Click on the "Save" button.
    
  - **Expected Outcome**: Verify that the new book is successfully added to the library catalog.


.. test:: Add Book Negative Scenario - Incomplete Book Information
  :id: FT_005
  :status: open

  - **Steps**:

    1. Log in as an administrator.
    2. Navigate to the library catalog section.
    3. Click on the "Add New Book" button.
    4. Enter incomplete information for a new book.
    5. Attempt to save the book.
    
  - **Expected Outcome**: Verify that the system prevents saving with incomplete information.


.. test:: Borrow Book Positive Scenario - Successful Borrowing
  :id: FT_006
  :tags: mvp
  :status: open
  :links: IMPL_003

  - **Steps**:

    1. Log in as a registered user.
    2. Search for an available book in the library catalog.
    3. Click on the "Borrow" button for the selected book.
    
  - **Expected Outcome**: Verify that the system confirms the successful borrowing of the book.


.. test:: Borrow Book Negative Scenario - Unavailable Book
  :id: FT_007
  :tags: mvp
  :status: open
  :links: IMPL_003

  - **Steps**:

    1. Log in as a registered user.
    2. Search for a book that is already checked out or unavailable.
    3. Attempt to borrow the unavailable book.
    
  - **Expected Outcome**: Verify that the system provides a clear message indicating the unavailability.


.. test:: Return Book Positive Scenario - Successful Return
  :id: FT_008
  :tags: mvp
  :status: open
  :links: IMPL_004

  - **Steps**:

    1. Log in as a registered user.
    2. Navigate to the user's account section showing borrowed books.
    3. Click on the "Return" button for a borrowed book.
    
  - **Expected Outcome**: Verify that the system confirms the successful return of the book.


.. test:: Return Book Negative Scenario - Returning Unborrowed Book
  :id: FT_009
  :tags: mvp
  :status: open
  :links: IMPL_004

  - **Steps**:

    1. Log in as a registered user.
    2. Navigate to the user's account section showing borrowed books.
    3. Attempt to return a book that was not borrowed.
    
  - **Expected Outcome**: Verify that the system prevents the return and provides an appropriate message.


.. test:: Search Books Positive Scenario - Successful Search
  :id: FT_010
  :status: open

  - **Steps**:

    1. Open the application and navigate to the library catalog.
    2. Enter valid search criteria (title, author, genre) for a known book.
    3. Click on the search button.
    
  - **Expected Outcome**: Verify that the system displays the relevant information for the matching books.


.. test:: Search Books Negative Scenario - No Matching Results
  :id: FT_011
  :status: open

  - **Steps**:

    1. Open the application and navigate to the library catalog.
    2. Enter search criteria that do not match any books.
    3. Click on the search button.
    
  - **Expected Outcome**: Verify that the system displays a message indicating no matching results.




Integration Tests
--------------------------------------------
- **Purpose**:

  - **Interaction Verification**: The primary purpose of integration testing is to
    verify that different components or modules of a software system work together
    as expected when integrated.
  - **Error Detection**: It aims to detect any issues related to the interfaces and
    interactions between components, such as incorrect data exchanges, communication
    problems, or interface mismatches.
  - **Collaboration Validation**: Integration testing ensures that the integrated
    components collaborate seamlessly to perform specific functions or processes.

- **Scope**:

  - **Component Interaction**: Integration testing focuses on testing the interaction
    between individual units or components to uncover defects that may arise when these
    units are combined.
  - **Data Flow**: It evaluates the flow of data between integrated components, checking
    for accuracy, completeness, and proper handling.
  - **Interface Behavior**: Integration testing assesses the behavior of interfaces
    between modules, ensuring that they adhere to specifications and standards.

- **Important Points**:

  - **Scenario-Based Testing**: Test cases are designed based on integration scenarios,
    which represent specific sequences of component interactions.
  - **Positive and Negative Testing**: Like functional testing, integration testing
    includes positive testing to validate expected behavior and negative testing to
    identify potential issues.
  - **Early Error Detection**: Integration testing helps identify and address
    integration-related issues early in the development process.
  - **Incremental Development**: It supports incremental development by validating
    the integration of new components with existing ones as development progresses.
  - **Collaboration with Other Testing Levels**: Integration testing is a bridge between
    unit testing and system testing, ensuring that individual units, when combined,
    function correctly within the larger system.
  - **External Systems**: Integration testing may involve testing the integration points
    between the software system and external systems, such as databases, APIs, or
    third-party services.
  - **Communication Channels**: It includes testing communication channels, protocols,
    and data formats between components.


.. test:: Integration of User Authentication (FR_001) with Security (NFR_002)
  :id: IT_001
  :status: open
  :links: FR_001; NFR_002

  - **Steps**:

    1. Simulate a user authentication process.
    2. Verify that the user authentication module securely stores passwords using hashing and salting.
    
  - **Expected Outcome**: Ensure that the integration between user authentication and security measures
    is seamless and passwords are handled securely.


.. test:: Integration of Add Book (FR_002) with Backup and Recovery (NFR_005)
  :id: IT_002
  :status: open
  :links: FR_002; NFR_005

  - **Steps**:

    1. Add a new book to the library catalog.
    2. Trigger a backup process.
    3. Simulate a data loss scenario.
    4. Initiate a data restoration process.
    
  - **Expected Outcome**: Confirm that the integration between adding a book and the backup system
    allows for successful data recovery in case of a loss.


.. test:: Integration of Borrow Book (FR_003) with Performance (NFR_001)
  :id: IT_003
  :tags: mvp
  :status: open
  :links: FR_003; NFR_001

  - **Steps**:

    1. Simulate multiple users attempting to borrow books concurrently.
    2. Measure the system's response time during the concurrent borrowing process.
    
  - **Expected Outcome**: Verify that the system can handle concurrent borrow requests
    within the specified response time.


.. test:: Integration of Return Book (FR_004) with Accessibility (NFR_004)
  :id: IT_004
  :tags: mvp
  :status: open
  :links: FR_004; NFR_004

  - **Steps**:

    1. Simulate a user returning a book through the user interface.
    2. Test the user interface accessibility for users with disabilities during the return process.
    
  - **Expected Outcome**: Ensure that the return book functionality is accessible to users
    with disabilities, meeting accessibility requirements.


.. test:: Integration of Search Books (FR_005) with Medium (NFR_003)
  :id: IT_005
  :status: open
  :links: FR_005; NFR_003

  - **Steps**:

    1. Perform a search for books in the library catalog with a large dataset.
    2. Simulate additional users searching for books simultaneously.
    
  - **Expected Outcome**: Confirm that the system can handle searching for books
    with a large dataset and concurrent users, meeting medium concurrency requirements.


End-to-End Tests
--------------------------------------------
- **Purpose**: End-to-End (E2E) testing is a software testing methodology that assesses
  the entire application workflow from start to finish. The primary purpose of E2E testing
  is to simulate real user scenarios and ensure that the integrated components of a system
  work together as intended to deliver the expected results.

- **Scope**:

  - **Complete System Testing**: E2E testing involves testing the entire application or
    system, including all interconnected components, databases, external interfaces,
    and dependencies.
  - **User Scenarios**: E2E tests are designed to mimic real-world user interactions with
    the application. This includes navigating through different screens, interacting with
    forms, and validating the system's response.
  - **Business Processes**: E2E testing often covers end-to-end business processes or user
    workflows. It ensures that the application performs correctly in scenarios that reflect
    actual usage.
  - **Integration Points**: E2E testing verifies the integration points between various
    subsystems, ensuring that data flows smoothly and accurately between different
    components.

- **Important Points**:

  - **Realistic Simulation**: E2E tests aim to simulate real user interactions, providing
    a more accurate representation of how the application behaves in a production-like
    environment.
  - **User Interface Testing**: E2E testing includes validating the user interface,
    ensuring that it is responsive, functional, and provides a seamless experience for
    the end user.
  - **Data Integrity**: E2E testing verifies the integrity of data as it moves through
    the entire system. This includes data input, processing, storage, and retrieval.
  - **Identifying System-wide Issues**: E2E tests are effective in uncovering issues
    that may arise from the interactions between different subsystems or components,
    such as communication problems, data inconsistencies, or performance bottlenecks.
  - **Automation**: E2E testing is often automated using tools like Selenium, Cypress,
    or Puppeteer to efficiently execute complex scenarios and provide quick feedback
    on the overall health of the application.
  - **Validation of Business Requirements**: E2E testing ensures that the application
    meets the specified business requirements and delivers the intended value to end
    users.
  - **Regression Testing**: E2E tests are valuable for regression testing, as they
    help identify any unintended side effects of changes in the application, ensuring
    that new features or updates do not break existing functionality.
  - **Black Box Testing**: E2E testing is typically considered a form of black-box testing,
    as testers focus on the application's inputs and outputs without necessarily being concerned
    with its internal code or implementation details.
  - **Complexity**: E2E testing can be more complex and time-consuming compared to unit or
    integration testing due to its broad scope and the need to set up and manage a realistic
    test environment.

.. test:: End-to-End Authentication (FR_001) and Security (NFR_002)
  :id: E2ET_001
  :status: open
  :links: FR_001; NFR_002

  - **Steps**:

    1. Open the application and navigate to the login screen.
    2. Enter valid user credentials.
    3. Verify that the user is successfully authenticated.
    4. Access the system dashboard.
    5. Change the user password.
    6. Log out and attempt to log in with the updated password.
    
  - **Expected Outcome**: Confirm that the end-to-end authentication process works seamlessly,
    and the password is securely updated.


.. test:: End-to-End Adding a Book (FR_002) and Backup/Recovery (NFR_005)
  :id: E2ET_002
  :status: open
  :links: FR_002; NFR_005

  - **Steps**:

    1. Log in as an administrator.
    2. Add a new book to the library catalog.
    3. Trigger a backup process.
    4. Simulate a data loss scenario.
    5. Initiate a data restoration process.
    6. Verify that the added book is restored after data recovery.
    
  - **Expected Outcome**: Ensure that adding a book is successfully backed up and
    restored in case of data loss.


.. test:: End-to-End Borrowing a Book (FR_003) with Performance (NFR_001)
  :id: E2ET_003
  :status: open
  :links: FR_002; NFR_005

  - **Steps**:

    1. Log in as a registered user.
    2. Search for an available book in the library catalog.
    3. Simulate multiple users concurrently borrowing books.
    4. Verify that the system responds within the specified time during concurrent
       borrow operations.
    
  - **Expected Outcome**: Confirm that the end-to-end borrowing process meets performance
    requirements under concurrent user scenarios.


.. test:: End-to-End Returning a Book (FR_004) and Accessibility (NFR_004)
  :id: E2ET_004
  :status: open
  :links: FR_004; NFR_004

  - **Steps**:

    1. Log in as a registered user.
    2. Borrow a book and then return it.
    3. Verify the accessibility of the user interface during the return process, using
       assistive technologies.
    
  - **Expected Outcome**: Ensure that the end-to-end process of borrowing and returning
    a book is accessible to users with disabilities.


.. test:: End-to-End Searching for Books (FR_005) with Medium (NFR_003)
  :id: E2ET_005
  :status: open
  :links: FR_005; NFR_003

  - **Steps**:

    1. Open the application and navigate to the library catalog.
    2. Perform a search for books with a large dataset.
    3. Simulate additional users searching for books simultaneously.
    4. Verify that the system handles searching for books with a large dataset and
       concurrent users.
    
  - **Expected Outcome**: Confirm that the end-to-end search functionality meets medium
    concurrency requirements.


Sanitizers
--------------------------------------------
- **Purpose**:

  - **Error Detection**: The primary purpose of sanitizers is to detect errors and issues
    in the code during runtime. This includes identifying memory errors, undefined behavior,
    and other common programming mistakes.
  - **Security Enhancement**: Sanitizers contribute to enhancing the security of software by
    identifying vulnerabilities such as buffer overflows, use-after-free errors, and other
    memory-related issues that could be exploited by attackers.
  - **Code Quality Improvement**: By identifying and addressing issues early in the development
    process, sanitizers contribute to overall code quality and maintainability.

- **Scope**:

  - **Runtime Analysis**: Sanitizers operate during runtime, analyzing the behavior of the code
    as it executes. This is in contrast to static analyzers, which analyze the code without
    executing it.
  - **AddressSanitizer (ASan)**: Detects memory errors, including out-of-bounds accesses,
    use-after-free, and memory leaks.
  - **MemorySanitizer (MSan)**: Focuses on detecting the use of uninitialized memory.
  - **UndefinedBehaviorSanitizer (UBSan)**: Identifies undefined behavior in the code,
    helping catch issues that might lead to unexpected results.
  - **ThreadSanitizer (TSan)**: Detects data races and other threading-related issues.

- **Important Points**:

  - **Complementary to Testing**: While testing, including unit testing and integration testing,
    is crucial, sanitizers offer an additional layer of defense by dynamically analyzing the
    code during execution.
  - **Continuous Integration (CI)**: Sanitizers are commonly used in CI pipelines to automatically
    check code for issues whenever changes are made. This helps catch problems early and ensures
    that the codebase remains free of common errors.
  - **Security Benefits**: Sanitizers contribute significantly to improving the security
    posture of a software application by identifying potential vulnerabilities.
  - **Early Bug Detection**: Sanitizers help catch bugs and issues early in the development
    process, reducing the likelihood of introducing defects into the codebase.
  - **Overhead**: Using sanitizers may introduce some performance overhead, as the tools
    instrument the code to detect issues. However, the benefits of catching and fixing bugs
    early generally outweigh the performance impact, especially during development and testing phases.


Test Data
--------------------------------------------
- **Definition**: Test data refers to data used during testing to ensure that the system
  processes information correctly under different conditions.

Test Environments
--------------------------------------------
- **Definition**: Test environments involve the specification of the environments in which
  testing will be conducted, including hardware, software, and network configurations.