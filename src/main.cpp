#include "Menu.hpp"
#include "Library.hpp"



int main(int argc, char const *argv[])
{
    
    Library library;

    Menu menu(library);
    menu.displayMenu();
    int choice = menu.handleUserInput();
    while (choice != 6) {
        switch (choice) {
            case 1:
                menu.addBook();
                break;
            case 2:
                menu.removeBook();
                break;
            case 3:
                menu.searchBook();
                break;
            case 4:
                menu.sortBooks();
                break;
            default:
                menu.displayBooks();
                break;
        }
        choice = menu.handleUserInput();
    }
    return 0;
}
