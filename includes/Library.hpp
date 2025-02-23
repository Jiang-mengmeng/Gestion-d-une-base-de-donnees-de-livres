#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include <vector>

class Library {
    private:
        std::vector<Book> books;
    public:
        Library();
        void addBook(const Book& book);
        void removeBook(const std::string& title);
        void searchBook(const std::string& title);
        void sortBooks();
        void displayBooks();
};


#endif // LIBRARY_HPP