#include "Library.hpp"
#include <algorithm>
Library::Library() : books() {}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(const std::string& title) {
    books.erase(std::remove_if(books.begin(), books.end(), [title](const Book& book) {
        return book.getTitle() == title;
    }), books.end());
}

void Library::searchBook(const std::string& title) {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            std::cout << "Livre trouvé: " << book.getTitle() << " (" << book.getAuthor() << ", " << book.getYear() << ")" << std::endl;
        }
    }
}

void Library::sortBooks() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    });
}

void Library::displayBooks() {
    for (const auto& book : books) {
        std::cout << "Livre: " << book.getTitle() << " (" << book.getAuthor() << ", " << book.getYear() << ")" << std::endl;
    }
}
