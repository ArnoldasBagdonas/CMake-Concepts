Requirements
============================================
- Definition: A statement that specifies a product or system capability, constraint, or condition that must be met.
- ISO 26262 Perspective: Requirements in the context of ISO 26262 are related to functional safety, aiming to ensure that safety goals are achieved.

Minimum Viable Product (MVP)
--------------------------------------------
- **Purpose**: The purpose of a Minimum Viable Product (MVP) is to deliver a version of a product
  with the minimum features necessary to meet the needs of early users and gather feedback for future
  development. The key goals of an MVP are:

  - **Fast Market Entry**: Quickly introduce the product to the market to gauge user interest and potential
    adoption.
  - **Feedback Collection**: Obtain feedback from early users to understand their needs, preferences, and
    pain points.
  - **Risk Mitigation**: Minimize development risks by validating assumptions and testing the product concept
    in the real market environment.
  - **Cost Efficiency**: Focus on essential features to reduce development costs and resource investment initially.

- **Scope**: The scope of an MVP is intentionally limited, focusing on delivering core features that address
  the primary user needs. It typically includes:

  - **Key Features**: Only essential features that provide value to users and solve a specific problem.
  - **Basic Functionality**: The product should perform its core functions effectively without unnecessary complexities.
  - **User Experience**: Provide a simple and intuitive user experience to encourage user engagement.
  - **Iterative Development**: The scope allows for iterative development based on user feedback and evolving requirements.

- **Important Points**: Key considerations and important points when developing an MVP include:

  - **Customer-Centric Approach**: Understand and prioritize user needs to deliver a product that resonates
    with the target audience.
  - **Rapid Development**: Focus on quick development cycles to bring the product to market promptly.
  - **Feedback Loops**: Establish mechanisms for collecting, analyzing, and acting upon user feedback continuously.
  - **Measurable Goals**: Define measurable objectives to assess the success of the MVP, such as user adoption
    rates, feedback response, and key performance indicators.
  - **Iterative Enhancements**: Plan for successive iterations based on user feedback and evolving market conditions
    to improve and expand the product.
  - **Resource Efficiency**: Allocate resources judiciously, emphasizing the most critical features for the initial release.
  - **Market Testing**: Deploy the MVP in the real market to test its viability and gather insights into user behavior
    and preferences.
  - **Pivot or Persevere**: Be prepared to pivot the product direction based on feedback or persevere with the existing
    plan, depending on market response.
  - **Scalability Considerations**: Design the MVP with scalability in mind to accommodate future growth and feature expansion.

.. needtable::
   :tags: mvp
   :style: table

Functional Requirements
--------------------------------------------
Functional requirements describe the specific features and functionalities that
a system must provide. These requirements outline the interactions and behaviors
the system must exhibit to meet the needs of its users.

User Interface (UI)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Description: Describes how users interact with the system.
- Example: The system shall provide a user-friendly web interface allowing users to log in, navigate through different modules, and submit forms.

Data Management
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Specifies how the system handles data.
- Example: The system shall store user profiles in a secure database, allowing users to update their information and retrieve it when needed.

Business Logic
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Defines the core functionalities and rules of the system.
- Example: The system shall calculate and display the total cost of a shopping cart based on the items selected and any applicable discounts.

Authentication and Authorization
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Outlines how the system manages user access and permissions.
- Example: Users shall be required to log in with a valid username and password, and administrators shall have elevated privileges to manage user accounts.

Reporting
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Specifies the generation and presentation of reports.
- Example: The system shall generate monthly sales reports, displaying graphs and tables summarizing key performance indicators.


.. req:: User Authentication
   :id: FR_001
   :status: open
   
   Users must authenticate to access the system


.. req:: Add Book
   :id: FR_002
   :status: closed

   Users can add new books to the library catalog


.. req:: Borrow Book
   :id: FR_003
   :tags: mvp
   :status: closed

   Users can borrow books from the library


.. req:: Return Book
   :id: FR_004
   :tags: mvp
   :status: open

   Users can return borrowed books to the library


.. req:: Search Books
   :id: FR_005
   :status: open

   Users can search for books in the library catalog


Non-Functional Requirements
--------------------------------------------
Non-functional requirements specify the qualities or attributes that define how
the system performs its functions. These requirements focus on aspects such as
performance, security, usability, and reliability.

Performance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Addresses how the system performs under certain conditions.
- Example: The system shall load the homepage within 3 seconds, even under peak usage, to ensure a responsive user experience.

Reliability
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Focuses on the system's ability to perform consistently and reliably.
- Example: The system shall have a 99.9% uptime, ensuring that it is available to users except during scheduled maintenance.

Security
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Describes measures to protect the system from unauthorized access and data breaches.
- Example: All user passwords shall be encrypted, and the system shall implement role-based access control to ensure data confidentiality.

Scalability
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Specifies how well the system can handle increased loads or growing data.
- Example: The system shall be able to scale horizontally to accommodate a 20% increase in concurrent user connections without a significant decrease in performance.

Usability
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Addresses how easy and intuitive the system is for users.
- Example: The system shall comply with WCAG 2.0 accessibility standards, ensuring that it is usable by people with disabilities.

Maintainability
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Description: Focuses on how easily the system can be maintained and updated.
- Example: The system shall be developed using modular code, allowing for easy updates to individual components without affecting the entire system.

.. req:: Performance
   :id: NFR_001
   :status: open
   
   The system must respond to user actions within 2 seconds


.. req:: Security
   :id: NFR_002
   :status: open

   User passwords must be stored securely using hashing and salting


.. req:: Medium
   :id: NFR_003
   :status: open

   The system should be able to handle at least 1000 concurrent users


.. req:: Accessibility
   :id: NFR_004
   :status: open

   The system's user interface must be accessible to users with disabilities


.. req:: Backup and Recovery
   :id: NFR_005
   :status: open

   The system must have daily automated backups and the ability to restore data