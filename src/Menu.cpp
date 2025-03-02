#include "Menu.hpp"

Menu::Menu(Library& library) : library(library) {}

void Menu::displayMenu() {
    std::cout << "Bienvenue dans le gestionnaire de bibliothèque" << std::endl;
    std::cout << "1. Ajouter un livre" << std::endl;
    std::cout << "2. Supprimer un livre" << std::endl;
    std::cout << "3. Rechercher un livre" << std::endl;
    std::cout << "4. Trier les livres" << std::endl;
    std::cout << "5. Afficher les livres" << std::endl;
    std::cout << "6. Quitter" << std::endl; 
}

int Menu::handleUserInput() {
    int choice;
    std::cout << "Veuillez entrer votre choix: ";
    std::cin >> choice;
    return choice;
}

void Menu::addBook() {
    std::string title, author;
    int year;
    std::cout << "Veuillez entrer le titre du livre: ";
    std::cin >> title;
    std::cout << "Veuillez entrer l'auteur du livre: ";
    std::cin >> author;
    std::cout << "Veuillez entrer l'année de publication du livre: ";
    std::cin >> year;
    library.addBook(Book(title, author, year));
}

void Menu::removeBook() {
    std::string title;
    std::cout << "Veuillez entrer le titre du livre à supprimer: ";
    std::cin >> title;
    library.removeBook(title);
}

void Menu::searchBook() {
    std::string title;
    std::cout << "Veuillez entrer le titre du livre à rechercher: ";
    std::cin >> title;
    library.searchBook(title);
}

void Menu::sortBooks() {
    library.sortBooks();
}

void Menu::displayBooks() {
    library.displayBooks();
}   