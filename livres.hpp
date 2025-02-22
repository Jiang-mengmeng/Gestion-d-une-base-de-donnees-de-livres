#ifndef LIVRES_HPP
#define LIVRES_HPP

#include <iostream>
#include <cstring>

using namespace std;

class Livres{
public :
    int taille;
    bool ud = 1;

    struct Livre{
        char titre[50];
        char auteur[50];
        int annee; 
    };

    typedef struct node{
        Livre l;
        struct node* next;
    }* list;

    list p;
    char title[50];
    char author[50];
    int year;

    /* [Constructeur] Initialiser une liste de livres avec n(taille) livres */
    Livres(const int& taille, const bool& ud);

    /* [Destructeur] Quitter le programme en libérant toute la mémoire allouée */
    ~Livres();

    /* Afficher la liste des livres (titre, auteur, année) */
    void affi_livres();

    /* Ajouter un livre au début de la liste des livres */
    void head_ajoute_livre();

    /* Ajouter un livre à la fin de la liste des livres */
    void tail_ajoute_livre();

    /* Supprimer un livre par titre */
    void supprimer_livres_par_titre();

    /* Supprimer un livre par auteur */
    void supprimer_livres_par_auteur();

    /* Supprimer un livre par année */
    void supprimer_livres_par_annee();

    /* Rechercher un livre par titre */
    void rechercher_livres_par_titre();

    /* Rechercher un livre par auteur */
    void rechercher_livres_par_auteur();

    /* Rechercher un livre par année */
    void rechercher_livres_par_annee();
    
    /* Trier les livres par titre */
    void trier_livres_par_titre();

    /* Trier les livres par auteur */
    void trier_livres_par_auteur();
    
    /* Trier les livres par année */
    void trier_livres_par_annee();
};

#endif