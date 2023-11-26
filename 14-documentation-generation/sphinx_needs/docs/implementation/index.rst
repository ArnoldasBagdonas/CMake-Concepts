Implementation
============================================
- Definition: The process of realizing a design or specification in a physical or software form.
- ISO 26262 Perspective: Implementation involves developing the system or software according to
  the specifications and safety requirements outlined in the previous phases. This includes coding,
  hardware design, and integrating safety mechanisms.

Coding Standards
--------------------------------------------
Detailed guidelines and conventions for writing code to ensure consistency, readability,
and maintainability.

Database Schema
--------------------------------------------
Specification of the structure and organization of the database, including tables, relationships,
and constraints.

APIs and Integrations
--------------------------------------------
Documentation of application programming interfaces (APIs) and integration points, defining how
different components or systems interact.
  - Purpose: Design the individual components or modules based on the requirements and specifications.
  - Module/Component Design Documents: Provide detailed design documentation for each
    component or module. Focus on cohesion, low coupling, and reusability. Include
    data structures, algorithms, and interfaces.

.. impl:: User Login
  :id: IMPL_001
  :status: open
  :links: SPEC_001

  .. uml::

    @startuml DetailedActivityDiagram001UserLogin
    skinparam backgroundColor transparent
    |User|
    start
    :Enter username and password;
    if (Credentials valid?) then (yes)
      :Log user in;
      |User|
      :Access system;
    else (no)
      |User|
      :Display login failed message;
      |User|
      stop
    endif
    |User|
    stop
    @enduml


.. impl:: Add Book
  :id: IMPL_002
  :status: open

  .. uml::
  
    @startuml DetailedActivityDiagram002AddBook
    skinparam backgroundColor transparent
    |Librarian|
    start
    :Log in as librarian;
    if (Logged in?) then (yes)
      :Navigate to "Add Book" section;
      :Enter book details (title, author, ISBN, etc.);
      if (Details valid?) then (yes)
        :Add book to catalog;
        |Librarian|
        :Book added successfully;
      else (no)
        |Librarian|
        :Display error message;
        |Librarian|
        stop
      endif
    else (no)
      |Librarian|
      :Unable to log in;
      |Librarian|
      stop
    endif
    |Librarian|
    stop
    @enduml


.. impl:: Borrow Book
  :id: IMPL_003
  :tags: mvp
  :status: open
  :links: SPEC_003

  .. uml::
  
    @startuml DetailedActivityDiagram003BorrowBook
    skinparam backgroundColor transparent
    |Library Member|
    start
    :Search for desired book;
    if (Book found?) then (yes)
      :Select book for borrowing;
      :Request to borrow book;
      |Library System|
      if (Book available and not borrowed?) then (yes)
        :Record borrowing transaction;
        :Update book status;
        |Library Member|
        :Book borrowed successfully;
      else (no)
        |Library System|
        :Display book not available message;
        |Library Member|
        :Unable to borrow book;
      endif
    else (no)
      |Library System|
      :Display book not found message;
      |Library Member|
      :Unable to borrow book;
    endif
    |Library Member|
    stop
    @enduml


.. impl:: Return Book
  :id: IMPL_004
  :tags: mvp
  :status: open
  :links: SPEC_004

  .. uml::
  
    @startuml DetailedActivityDiagram004ReturnBook
    skinparam backgroundColor transparent
    |Library Member|
    start
    :Log in as library member;
    if (Logged in?) then (yes)
      :Navigate to "Return Book" section;
      :Select book to return;
      :Return book to library;
      |Library System|
      :Update book status;
      |Library Member|
      :Book returned successfully;
    else (no)
      |Library Member|
      :Unable to log in;
      |Library Member|
      stop
    endif
    |Library Member|
    stop
    @enduml


.. impl:: Search Books
  :id: IMPL_005
  :status: open

  .. uml::
  
    @startuml DetailedActivityDiagram005SearchBooks
    skinparam backgroundColor transparent
    |User|
    start
    :Log in;
    if (Logged in?) then (yes)
      :Enter keywords or title;
      :Perform search;
      |Library System|
      :Display search results;
      repeat
        :Select book from results;
        :View book details;
      repeat while (Continue searching?);
      |User|
      :Log out;
    else (no)
      |User|
      :Unable to log in;
      |User|
      stop
    endif
    |User|
    stop
    @enduml


Doxgen
--------------------------------------------
.. doxygenindex::
   :allow-dot-graphs:


Deployment Procedures
--------------------------------------------
Procedures and guidelines for deploying the system, including installation, configuration,
and version control.