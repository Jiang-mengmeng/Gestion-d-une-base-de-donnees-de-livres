#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>

class Book {
    private:
        std::string title;
        std::string author;
        int year;

    public:
        Book(std::string title, std::string author, int year);
        std::string getTitle() const;
        std::string getAuthor() const;
        int getYear() const;
        void setTitle(const std::string& title);
        void setAuthor(const std::string& author);
        void setYear(int year);
};

#endif