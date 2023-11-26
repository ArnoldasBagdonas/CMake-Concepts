Specifications
============================================
- Definition: A detailed description of the design, behavior, or other
  aspects of a system or component.
- ISO 26262 Perspective: Specifications in this context would include
  safety requirements, technical safety concepts, and other documentation
  that provides detailed information on how functional safety is achieved
  in the system.

Logical View
--------------------------------------------
- Purpose: Describes the functionality that the system provides to end-users.
  It often corresponds to the high-level design and includes components such
  as classes, modules, and their relationships.
- ISO 26262 Perspective: The Logical View, within the context of ISO 26262,
  serves as a foundation for understanding the functional aspects of the
  automotive system. It provides insights into how the system's components
  and classes contribute to achieving safety goals and meeting specified
  safety requirements.

.. uml::

  @startuml LogicalView
  package "User Management" {
      [User]
      [Authentication]
  }

  package "Catalog Management" {
      [Book]
      [Catalog]
  }

  package "Library System" {
      [Library Member]
      [Borrowing]
      [Returning]
      [Searching]
  }

  [User] --> [Authentication]
  [Library Member] --> [Authentication]
  [Library Member] --> [Borrowing]
  [Library Member] --> [Returning]
  [Library Member] --> [Searching]
  [Book] --> [Catalog]
  [Catalog] --> [Borrowing]
  [Catalog] --> [Searching]
  @enduml


Process View
--------------------------------------------
- Purpose: Focuses on the dynamic aspects of the system, emphasizing the
  processes or tasks that take place. It includes the flow of control, data,
  and the interactions between components.
- ISO 26262 Perspective: The Process View is essential for ISO 26262 compliance,
  emphasizing the dynamic behavior of the automotive system. It aids in understanding
  the processes and tasks that contribute to functional safety, including the flow of
  control and data. This view aligns with the standard's focus on achieving safety
  through effective process management.


.. uml::

  @startuml ProcessView
  |User|
  start
  :Perform User Login;
  if (Login successful?) then (yes)
    :Select desired action (Add Book, Borrow Book, Return Book, Search Books);
    repeat
      :Perform selected action;
    repeat while (Continue performing actions?)
    :Logout;
  else (no)
    |User|
    :Unable to log in;
    stop
  endif
  |User|
  stop
  @enduml


Physical View
--------------------------------------------
- Purpose: Describes the system from a deployment perspective, showing how the software
  components are mapped onto the hardware.
- ISO 26262 Perspective: The Physical View, aligned with ISO 26262, offers insights
  into the deployment aspects of the automotive system. It illustrates how software
  components are mapped onto the hardware, providing a foundation for understanding
  the system's physical architecture and how it contributes to functional safety.

.. uml::

  @startuml PhysicalView
  !define AWSPUML https://raw.githubusercontent.com/awslabs/aws-icons-for-plantuml/v16.0/dist
  !include AWSPUML/AWSCommon.puml
  !define EC2 smallOrange
  !define S3 smallBlue
  !define RDS smallPurple
  !define ELB smallGreen
  !define ASG smallGrey

  !includeurl AWSPUML/AWSCommon.puml
  !define iconsize 80

  !define AWSPUML https://raw.githubusercontent.com/awslabs/aws-icons-for-plantuml/v14.0/dist

  !define iconsize 80

  cloud {
      !define iconsize 100
      [User Device]
  }

  node "Amazon Elastic Load Balancing" as elb {
      [Load Balancer] as elb_lb
  }

  node "Amazon EC2 Auto Scaling" as asg {
      [Auto Scaling Group] as asg_group
      [Auto Scaling Group] as asg_group2
  }

  node "Amazon RDS" as rds {
      [Database] as rds_db
  }

  node "Amazon S3" as s3 {
      [Object Storage] as s3_storage
  }

  cloud {
      !define iconsize 60
      [Amazon CloudFront]
      [Amazon CloudWatch]
      [Amazon Route 53]
  }

  cloud {
      !define iconsize 100
      [User Device]
  }

  [User Device] --> [Load Balancer]

  [Load Balancer] --> [Auto Scaling Group]
  [Load Balancer] --> [Auto Scaling Group]

  [Auto Scaling Group] --> [Database]
  [Auto Scaling Group] --> [Object Storage]

  [Object Storage] --> [Amazon CloudFront]
  [Object Storage] --> [Amazon CloudWatch]
  [Object Storage] --> [Amazon Route 53]
  @enduml


Development View
--------------------------------------------
- Purpose: Describes the system from a developer's perspective, detailing the organization
  of the software into modules and components.
- ISO 26262 Perspective: The Development View holds significance in ISO 26262 as it
  provides insights into how the software is organized into modules and components.
  Understanding the developer's perspective is crucial for ensuring that the software
  architecture and design contribute effectively to functional safety, meeting
  the standard's requirements.

.. uml::

  @startuml DevelopmentView
  [User Interface] --> [Business Logic]
  [Business Logic] --> [Data Access]
  [Business Logic] --> [External Services]
  [Data Access] --> [Database]
  @enduml

Scenarios View
--------------------------------------------
- Purpose: Represents specific scenarios or use cases that illustrate how the system
  behaves in certain situations. This view helps in understanding the system's
  behavior in real-world scenarios.
- ISO 26262 Perspective: The Scenarios View is valuable within ISO 26262 to validate
  the system's behavior in real-world situations. It aids in aligning the system's
  responses with safety requirements and goals, ensuring that the automotive system
  operates safely in diverse scenarios as specified by the standard.

.. spec:: User Login
  :id: SPEC_001
  :status: open
  :links: FR_001

  **Description**
    A user wants to log in to the library system.

  **Actors**
    User

  **Preconditions**
    The user has a registered account.

  **Steps**:
    - The user enters their username and password.
    - The system validates the credentials.
    - If the credentials are valid, the user is granted access.

  **Postconditions**: The user is logged in and can access the system.

  .. uml::

    @startuml UseCase001UserLogin
    skinparam backgroundColor transparent
    actor User
    User -> System: Enter username and password
    System -> Database: Validate credentials
    Database --> System: Valid credentials
    System --> User: Grant access
    @enduml


.. spec:: Add Book
  :id: SPEC_002
  :status: open
  :links: FR_002

  **Description**
    The librarian wants to add a new book to the library catalog.

  **Actors**
    Librarian

  **Preconditions**
    The librarian is logged in and has the necessary permissions.

  **Steps**:
    - The librarian navigates to the "Add Book" section.
    - The librarian enters the book's details (title, author, ISBN, etc.).
    - The system validates the information and adds the book to the catalog.

  **Postconditions**
    The new book is added to the library catalog.

  .. uml::

    @startuml UseCase002AddBook
    skinparam backgroundColor transparent
    actor Librarian
    Librarian -> System: Navigate to "Add Book"
    Librarian -> System: Enter book details
    System -> System: Validate information
    System -> Database: Add book to catalog
    Database --> System: Book added
    System --> Librarian: Book added successfully
    @enduml


.. spec:: Borrow Book
  :id: SPEC_003
  :tags: mvp
  :status: open
  :links: FR_003

  **Description**
    A library member wants to borrow a book from the library.

  **Actors**
    Library Member

  **Preconditions**
    The member is logged in and has no overdue books.

  **Steps**:
    - The member searches for the desired book.
    - The member selects the book and requests to borrow it.
    - The system checks if the book is available and not already borrowed.
    - If available, the system records the borrowing transaction.

  **Postconditions**
    The member has successfully borrowed the book.

  .. uml::

    @startuml UseCase003BorrowBook
    skinparam backgroundColor transparent
    actor LibraryMember
    LibraryMember -> System: Search for desired book
    LibraryMember -> System: Select book for borrowing
    System -> System: Check availability and status
    System -> Database: Record borrowing transaction
    Database --> System: Transaction recorded
    System --> LibraryMember: Book borrowed successfully
    @enduml


.. spec:: Return Book
  :id: SPEC_004
  :tags: mvp
  :status: open
  :links: FR_004

  **Description**
    A library member wants to return a borrowed book.

  **Actors**
    Library Member

  **Preconditions**
    The member is logged in and has borrowed books.

  **Steps**:
    - The member navigates to their borrowed books.
    - The member selects the book to be returned.
    - The system updates the status of the book to "returned."

  **Postconditions**
    The book is returned and removed from the member's borrowed books.

  .. uml::

    @startuml UseCase004ReturnBook
    skinparam backgroundColor transparent
    actor LibraryMember
    LibraryMember -> System: Navigate to borrowed books
    LibraryMember -> System: Select book for return
    System -> System: Update book status to "returned"
    System --> LibraryMember: Book returned successfully
    @enduml


.. spec:: Search Books
  :id: SPEC_005
  :status: open

  **Description**
    A user wants to search for books in the library catalog.

  **Actors**
    User

  **Preconditions**
    The user is logged in.

  **Steps**:
    - The user enters keywords or a book's title in the search bar.
    - The system displays a list of books matching the search criteria.
    - The user selects a book from the search results to view its details.

  **Postconditions**
    The user can view the details of the selected book.

  .. uml::

    @startuml UseCase005SearchBooks
    skinparam backgroundColor transparent
    actor User
    User -> System: Enter keywords or title in search bar
    System -> Database: Retrieve matching books
    Database --> System: List of matching books
    System --> User: Display search results
    User -> System: Select book for details
    System -> Database: Retrieve book details
    Database --> System: Book details
    System --> User: Display book details
    @enduml
