#ifndef MENU_HPP
#define MENU_HPP

#include "Library.hpp"

class Menu {
    
    private:
        Library library;
    public:
        Menu(Library& library);
        void displayMenu();
        int handleUserInput();
        void addBook();
        void removeBook();
        void searchBook();
        void sortBooks();
        void displayBooks();
};
#endif // MENU_HPP