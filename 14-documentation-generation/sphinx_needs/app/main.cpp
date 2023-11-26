//!
//! @file main.cpp
//! @brief library management application
//!

#include <iostream>
#include <string>
#include "library_system/library_system.hpp"
#include "cxxopts.hpp" // Include the cxxopts library

/**
 * @brief Main function for the library management application.
 *
 * This program provides a command-line interface for interacting with the library system.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return An exit code indicating the success or failure of the program.
 */
int main(int argc, char* argv[]) {
    try {
        cxxopts::Options options("Library Management Application", "A command-line library system");

        // Define command-line options
        options.add_options()
            ("a,add", "Add a new book", cxxopts::value<std::string>())
            ("b,borrow", "Borrow a book", cxxopts::value<std::string>())
            ("r,return", "Return a borrowed book", cxxopts::value<std::string>())
            ("s,search", "Search for books", cxxopts::value<std::string>());

        // Parse command-line arguments
        auto result = options.parse(argc, argv);

        // Create a LibrarySystem instance
        LibrarySystem library;

        // Check the specified options and perform corresponding actions
        if (result.count("add")) {
            std::string title = result["add"].as<std::string>();
            // Call the addBook function from library_system.hpp
            bool added = library.addBook(title, "Unknown Author", "Unknown ISBN");
            if (added) {
                std::cout << "Book '" << title << "' added successfully." << std::endl;
            } else {
                std::cerr << "Failed to add the book." << std::endl;
            }
        } else if (result.count("borrow")) {
            // Implement borrowing logic here
            // ...
        } else if (result.count("return")) {
            // Implement returning logic here
            // ...
        } else if (result.count("search")) {
            // Implement search logic here
            // ...
        } else {
            std::cerr << "No valid options specified. Use -h or --help for usage information." << std::endl;
            return 1;
        }

        return 0;
    } catch (const cxxopts::OptionException& e) {
        std::cerr << "Error parsing command-line options: " << e.what() << std::endl;
        return 1;
    }
}
