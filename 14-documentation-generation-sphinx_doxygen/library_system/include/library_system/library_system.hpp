//!
//! @file library_system.hpp
//! @brief Definition of Requirement class methods
//!

#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <string>
#include <vector>

/**
 * @brief Enum representing the status of a requirement.
 */
enum RequirementStatus {
    OPEN,       ///< The requirement is open.
    IN_PROGRESS,///< The requirement is in progress.
    CLOSED      ///< The requirement is closed.
};

/**
 * @brief Class representing a functional or non-functional requirement.
 */
class Requirement {
public:
    /**
     * @brief Constructor to initialize a requirement.
     * @param id The ID of the requirement.
     * @param title The title of the requirement.
     * @param description The description of the requirement.
     * @param priority The priority of the requirement.
     * @param status The status of the requirement.
     * @param testCases The number of test cases for the requirement.
     * @param owner The owner or team responsible for the requirement.
     * @param createdDate The date when the requirement was created.
     */
    Requirement(int id, const std::string& title, const std::string& description,
                int priority, RequirementStatus status, int testCases,
                const std::string& owner, const std::string& createdDate);

    /**
     * @brief Get the ID of the requirement.
     * @return The ID of the requirement.
     */
    int getID() const;

    /**
     * @brief Get the title of the requirement.
     * @return The title of the requirement.
     */
    std::string getTitle() const;

    /**
     * @brief Get the description of the requirement.
     * @return The description of the requirement.
     */
    std::string getDescription() const;

    /**
     * @brief Get the priority of the requirement.
     * @return The priority of the requirement.
     */
    int getPriority() const;

    /**
     * @brief Get the status of the requirement.
     * @return The status of the requirement.
     */
    RequirementStatus getStatus() const;

    /**
     * @brief Get the number of test cases for the requirement.
     * @return The number of test cases for the requirement.
     */
    int getTestCases() const;

    /**
     * @brief Get the owner or team responsible for the requirement.
     * @return The owner or team responsible for the requirement.
     */
    std::string getOwner() const;

    /**
     * @brief Get the date when the requirement was created.
     * @return The date when the requirement was created.
     */
    std::string getCreatedDate() const;

private:
    int id_;
    std::string title_;
    std::string description_;
    int priority_;
    RequirementStatus status_;
    int testCases_;
    std::string owner_;
    std::string createdDate_;
};

/**
 * @brief Class representing a library system.
 */
class LibrarySystem {
public:
    /**
     * @brief Constructor to initialize the library system.
     */
    LibrarySystem();

    /**
     * @brief Destructor to clean up resources.
     */
    ~LibrarySystem();

    /**
     * @brief Add a new book to the library catalog.
     * @param title The title of the book.
     * @param author The author of the book.
     * @param isbn The ISBN of the book.
     * @return True if the book was successfully added, false otherwise.
     */
    bool addBook(const std::string& title, const std::string& author, const std::string& isbn);

    /**
     * @brief Borrow a book from the library.
     * @param isbn The ISBN of the book to borrow.
     * @param userId The ID of the user borrowing the book.
     * @return True if the book was successfully borrowed, false otherwise.
     */
    bool borrowBook(const std::string& isbn, int userId);

    /**
     * @brief Return a borrowed book to the library.
     * @param isbn The ISBN of the book to return.
     * @param userId The ID of the user returning the book.
     * @return True if the book was successfully returned, false otherwise.
     */
    bool returnBook(const std::string& isbn, int userId);

    /**
     * @brief Search for books in the library catalog.
     * @param keyword The keyword to search for in book titles and authors.
     * @return A vector of book titles matching the search keyword.
     */
    std::vector<std::string> searchBooks(const std::string& keyword);

private:
    // Private data members and methods can be added as needed.
};

#endif // LIBRARY_SYSTEM_H
