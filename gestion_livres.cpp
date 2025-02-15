#include <iostream>
#include <cstring>

using namespace std;

struct Livre{
    char titre[50];
    char auteur[50];
    int annee; 
};

typedef struct node{
    Livre l;
    struct node* next;
}* list;

list init_livres(const int& taille, const bool& ud = 1);
void affi_livres(list p);
void head_ajoute_livre(list& p, int& taille);
void tail_ajoute_livre(list& p, int& taille);
void supprimer_livres_par_titre(list& p, const char* title, int& taille);
void supprimer_livres_par_auteur(list& p, const char* author, int& taille);
void supprimer_livres_par_annee(list& p, int& year, int& taille);
void rechercher_livres_par_titre(list& p, const char* title);
void rechercher_livres_par_auteur(list& p, const char* author);
void rechercher_livres_par_annee(list& p, int& year);
void trier_livres_par_titre(list& p, const int& taille, const bool& ud = 1);
void trier_livres_par_auteur(list& p, const int& taille, const bool& ud = 1);
void trier_livres_par_annee(list& p, const int& taille, const bool& ud = 1);
void quitter_livres(list& p);

int main(void){
    /* Initialisation de la liste */
    int taille = 0;
    int ud = 1;
    cout << "Saisir la taille pour initialiser une liste de livres svp: ";
    cin >> taille;
    if(taille < 0){
        cerr << "Invalide taille!" << endl;
        return EXIT_FAILURE;
    } else{
        cout << "Tapez 1 pour l'initialiser dans l'ordre croissant, 0 dans l'ordre décroissant: ";
        cin >> ud;
        if(ud!=0 && ud!=1){
            cerr << "Invalide parametre!" << endl;
            return EXIT_FAILURE;
        }
    }
    list p = init_livres(taille, ud);
    cout << endl;
    /* Menu de service */
    while(1){
        int serv = 6; // Permettre de quitter au cas où cin dans un état d'erreur
        cout << "*Menu de service*\n" << "1. Afficher la liste de livres.\n" << "2. Ajouter un livre à la liste de livres.\n" << "3. Supprimer un livre de la liste de livres.\n" << "4. Rechercher un livre dans la liste de livres.\n" << "5. Trier les livres dans la liste de livres.\n" << "6. Quitter." << endl;
        cout << "Veuillez taper le numéro correspondant pour choisir un service: ";
        cin >> serv; 
        if(serv > 6 || serv <= 0){
            cout << "Invalide numéro service!\n" << endl;
            continue;
        }
        switch(serv){
            case 1:{ // Afficher la liste de livres
                affi_livres(p);
                cout << endl;
                break;
            }
            case 2:{ // Ajouter un livre à la liste de livres
                int head = 0;
                cout << "Tapez 1 pour l'ajouter au début, 0 à la fin: ";
                cin >> head;
                if(head!=0 && head!=1){
                    cerr << "Invalide parametre!\n" << endl;
                    break;
                } else{
                    if(head) head_ajoute_livre(p, taille);
                    else tail_ajoute_livre(p, taille);
                }
                cout << endl;
                break;
            }
            case 3:{ // Supprimer un livre de la liste de livres
                int y = 0;
                cout << "Tapez 2 pour supprimer un livre par titre, 1 par auteur, et 0 par année: ";
                cin >> y;
                if(y!=2 && y!=1 && y!=0){
                    cerr << "Invalide parametre!\n" << endl;
                    break;
                }
                switch(y){
                    case 2:{
                        char title[50];
                        cout << "Saisir le titre du livre vous souhaitez supprimer svp: ";
                        cin >> title;
                        supprimer_livres_par_titre(p, title, taille);
                        break;
                    }
                    case 1:{
                        char author[50];
                        cout << "Saisir l'auteur du livre vous souhaitez supprimer svp: ";
                        cin >> author;
                        supprimer_livres_par_auteur(p, author, taille);
                        break;
                    }
                    case 0:{
                        int year = 0;
                        cout << "Saisir l'année du livre vous souhaitez supprimer svp: ";
                        cin >> year;
                        supprimer_livres_par_annee(p, year, taille);
                        break;
                    }
                    default:;
                }
                cout << endl;
                break;
            }
            case 4:{ // Rechercher un livre dans la liste de livres
                int y = 0;
                cout << "Tapez 2 pour rechercher un livre par titre, 1 par auteur, et 0 par année: ";
                cin >> y;
                if(y!=2 && y!=1 && y!=0){
                    cerr << "Invalide parametre!\n" << endl;
                    break;
                }
                switch(y){
                    case 2:{
                        char title[50];
                        cout << "Saisir le titre du livre vous souhaitez rechercher svp: ";
                        cin >> title;
                        rechercher_livres_par_titre(p, title);
                        break;
                    }
                    case 1:{
                        char author[50];
                        cout << "Saisir l'auteur du livre vous souhaitez rechercher svp: ";
                        cin >> author;
                        rechercher_livres_par_auteur(p, author);
                        break;
                    }
                    case 0:{
                        int year = 0;
                        cout << "Saisir l'année du livre vous souhaitez rechercher svp: ";
                        cin >> year;
                        rechercher_livres_par_annee(p, year);
                        break;
                    }
                    default:;
                }
                cout << endl;
                break;
            }
            case 5:{ // Trier les livres dans la liste de livres
                int y = 0;
                cout << "Tapez 2 pour trier les livres par titre, 1 par auteur, et 0 par année: ";
                cin >> y;
                if(y!=2 && y!=1 && y!=0){
                    cerr << "Invalide parametre!\n" << endl;
                    break;
                }
                cout << "Tapez 1 pour trier dans l'ordre croissant, 0 dans l'ordre décroissant: ";
                cin >> ud;
                if(ud!=0 && ud!=1){
                    cerr << "Invalide parametre!\n" << endl;
                    break;
                }
                switch(y){
                    case 2:{
                        trier_livres_par_titre(p, taille, ud);
                        break;
                    }
                    case 1:{
                        trier_livres_par_auteur(p, taille, ud);
                        break;
                    }
                    case 0:{
                        trier_livres_par_annee(p, taille, ud);
                        break;
                    }
                    default:;
                }
                cout << endl;
                break;
            }
            case 6:{ // Quitter
                quitter_livres(p);
                return EXIT_SUCCESS;
            }
            default:;
        }
    }
}

/* Initialiser une liste de livres avec n livres */
list init_livres(const int& taille, const bool& ud){
    node* suiv = nullptr;
    for(int i=taille; i>0; i--){
        node* x = new node;
        if(ud){
            sprintf(x->l.titre, "titre%d", i);
            sprintf(x->l.auteur, "auteur%d", i);
            x->l.annee = 2000 + i;
        } else{
            sprintf(x->l.titre, "titre%d", taille+1-i);
            sprintf(x->l.auteur, "auteur%d", taille+1-i);
            x->l.annee = 2000 + (taille+1-i);
        }
        x->next = suiv;
        suiv = x;
    }
    if(ud) cout << "Voici le résultat après avoir initialisé une liste de " << taille << " livres dans l'ordre croissant: " << endl;
    else cout << "Voici le résultat après avoir initialisé une liste de " << taille << " livres dans l'ordre décroissant: " << endl;
    affi_livres(suiv);
    return suiv;
}

/* Afficher la liste des livres (titre, auteur, année) */
void affi_livres(list p){
    while(p != nullptr){
        if(p->next != nullptr){
            cout << p->l.titre << " " << p->l.auteur << " " << p->l.annee << " -> ";
            p = p->next;
        } else{
            cout << p->l.titre << " " << p->l.auteur << " " << p->l.annee << endl;
            p = p->next;
        }
    }
}

/* Ajouter un livre au début de la liste des livres */
void head_ajoute_livre(list& p, int& taille){
    node* head = new node;
    cout << "Saisir le titre, l'auteur et l'année du livre svp: ";
    cin >> head->l.titre >> head->l.auteur >> head->l.annee;
    head->next = p;
    p = head; // restaurer la tête
    taille++; // mettre a jour la taille
    cout << "Voici le résultat après avoir ajouté le livre au début de la liste: " << endl;
    affi_livres(p);
}

/* Ajouter un livre à la fin de la liste des livres */
void tail_ajoute_livre(list& p, int& taille){
    node* tail = new node, *head = p;
    cout << "Saisir le titre, l'auteur et l'année du livre svp: ";
    cin >> tail->l.titre >> tail->l.auteur >> tail->l.annee;
    tail->next = nullptr;
    while(p->next != nullptr) p = p->next;
    p->next = tail;
    p = head; // restaurer la tête
    taille++; // mettre a jour la taille
    cout << "Voici le résultat après avoir ajouté le livre à la fin de la liste: " << endl;
    affi_livres(p);
}

/* Supprimer un livre par titre */
void supprimer_livres_par_titre(list& p, const char* title, int& taille){
    node* head = p, *pre = nullptr/*precedenceur*/;
    while(p != nullptr){
        node* q = nullptr; // le target
        if(strcmp(p->l.titre, title) == 0){ // livre courant corresponde
            q = p;
            if(pre == nullptr) head = p->next; // mettre a jour la tête
            else{
                pre->next = p->next;
                pre = p;
            }
            p = p->next;
            delete[] q; // liberer la memoire allouee
            taille--; // mettre a jour la taille
        } else{ // livre courant ne corresponde pas
            pre = p;
            p = p->next;
        }
    }
    p = move(head); // restaurer la tête
    cout << "Voici le résultat après avoir supprimé un(des) livre(s) avec le titre <<" << title << ">> dans la liste:" << endl;
    affi_livres(p);
}

/* Supprimer un livre par auteur */
void supprimer_livres_par_auteur(list& p, const char* author, int& taille){
    node* head = p, *pre = nullptr/*precedenceur*/;
    while(p != nullptr){
        node* q = nullptr; // le target
        if(strcmp(p->l.auteur, author) == 0){ // livre courant corresponde
            q = p;
            if(pre == nullptr) head = p->next; // mettre a jour la tête
            else{
                pre->next = p->next;
                pre = p;
            }
            p = p->next;
            delete[] q; // liberer la memoire allouee
            taille--; // mettre a jour la taille
        } else{ // livre courant ne corresponde pas
            pre = p;
            p = p->next;
        }
    }
    p = move(head); // restaurer la tête
    cout << "Voici le résultat après avoir supprimé un(des) livre(s) avec l'auteur " << author << " dans la liste:" << endl;
    affi_livres(p);
}

/* Supprimer un livre par année */
void supprimer_livres_par_annee(list& p, int& year, int& taille){
    node* head = p, *pre = nullptr/*precedenceur*/;
    while(p != nullptr){
        node* q = nullptr; // le target
        if(p->l.annee == year){ // livre courant corresponde
            q = p;
            if(pre == nullptr) head = p->next; // mettre a jour la tête
            else{
                pre->next = p->next;
                pre = p;
            }
            p = p->next;
            delete[] q; // liberer la memoire allouee
            taille--; // mettre a jour la taille
        } else{ // livre courant ne corresponde pas
            pre = p;
            p = p->next;
        }
    }
    p = move(head); // restaurer la tête
    cout << "Voici le résultat après avoir supprimé un(des) livre(s) avec l'année " << year << " dans la liste:" << endl;
    affi_livres(p);
}

/* Rechercher un livre par titre */
void rechercher_livres_par_titre(list& p, const char* title){
    node* head = p;
    int res = 0;
    while(p != nullptr){
        if(strcmp(p->l.titre, title) == 0){
            cout << "livre trouvé: auteur: " << p->l.auteur << " année: " << p->l.annee << endl;
            res++;
        }
        p = p->next;
    }
    p = move(head); // restaurer la tête
    if(res) cout << res << " livre(s) avec le titre <<" << title << ">> est(sont) trouvé(s)!" << endl;
    else cout << "Le livre avec le titre <<" << title << ">> n'existe pas!" << endl;
}

/* Rechercher un livre par auteur */
void rechercher_livres_par_auteur(list& p, const char* author){
    node* head = p;
    int res = 0;
    while(p != nullptr){
        if(strcmp(p->l.auteur, author) == 0){
            cout << "livre trouvé: titre: " << p->l.titre << " année: " << p->l.annee << endl;
            res++;
        }
        p = p->next;
    }
    p = move(head); // restaurer la tête
    if(res) cout << res << " livre(s) avec l'auteur " << author << " est(sont) trouvé(s)!" << endl;
    else cout << "Le livre avec l'auteur " << author << " n'existe pas!" << endl;
}

/* Rechercher un livre par année */
void rechercher_livres_par_annee(list& p, int& year){
    node* head = p;
    int res = 0;
    while(p != nullptr){
        if(p->l.annee == year){
            cout << "livre trouvé: titre: " << p->l.titre << " auteur: " << p->l.auteur << endl;
            res++;
        }
        p = p->next;
    }
    p = move(head); // restaurer la tête
    if(res) cout << res << " livre(s) avec l'année " << year << " est(sont) trouvé(s)!" << endl;
    else cout << "Le livre avec l'année " << year << " n'existe pas!" << endl;
}

/* Trier les livres par titre */
void trier_livres_par_titre(list& p, const int& taille, const bool& ud){
    node* head = p;
    for(int i=0; i<taille; i++){
        /* reinitialiser */
        node* m = p, *pre = p, *q = nullptr;
        p = p->next;
        /* chercher m entre les premiers (taille-i) elements dans la liste */
        for(int j=0; j<taille-i-1; j++){
            if(ud){ // m = min
                if(strcmp(m->l.titre, p->l.titre) > 0){
                    m = p;
                    q = pre;
                }
            } else{ // m = max
                if(strcmp(m->l.titre, p->l.titre) < 0){
                m = p;
                q = pre;
            }
            }
            pre = p;
            p = p->next;
        }
        while(p != nullptr){
            pre = p;
            p = p->next;
        }
        if(m != pre){ // deplacement neccessaire
            /* supprimer m entre les premiers (taille-i) elements dans la liste */
            if(q != nullptr) q->next = m->next;
            else head = m->next; 
            /* l'ajouter a la fin */
            pre->next = m;
            m->next = nullptr;
        }
        p = head; // mettre a jour p pour recommencer
        // affi_livres(p); // debug en affichant le processus de tri
    }
    if(ud) cout << "Voici le résultat après avoir trié les livres par titre dans l'ordre croissant: " << endl;
    else cout << "Voici le résultat après avoir trié les livres par titre dans l'ordre décroissant: " << endl;
    affi_livres(p);
}

/* Trier les livres par auteur */
void trier_livres_par_auteur(list& p, const int& taille, const bool& ud){
    node* head = p;
    for(int i=0; i<taille; i++){
        /* reinitialiser */
        node* m = p, *pre = p, *q = nullptr;
        p = p->next;
        /* chercher m entre les premiers (taille-i) elements dans la liste */
        for(int j=0; j<taille-i-1; j++){
            if(ud){ // m = min
                if(strcmp(m->l.auteur, p->l.auteur) > 0){
                    m = p;
                    q = pre;
                }
            } else{ // m = max
                if(strcmp(m->l.auteur, p->l.auteur) < 0){
                m = p;
                q = pre;
            }
            }
            pre = p;
            p = p->next;
        }
        while(p != nullptr){
            pre = p;
            p = p->next;
        }
        if(m != pre){ // deplacement neccessaire
            /* supprimer m entre les premiers (taille-i) elements dans la liste */
            if(q != nullptr) q->next = m->next;
            else head = m->next;
            /* l'ajouter a la fin */
            pre->next = m;
            m->next = nullptr;
        }
        p = head; // mettre a jour p pour recommencer
        // affi_livres(p); // debug en affichant le processus de tri
    }
    if(ud) cout << "Voici le résultat après avoir trié les livres par auteur dans l'ordre croissant: " << endl;
    else cout << "Voici le résultat après avoir trié les livres par auteur dans l'ordre décroissant: " << endl;
    affi_livres(p);
}

/* Trier les livres par année */
void trier_livres_par_annee(list& p, const int& taille, const bool& ud){
    node* head = p;
    for(int i=0; i<taille; i++){
        /* reinitialiser */
        node* m = p, *pre = p, *q = nullptr;
        p = p->next;
        /* chercher m entre les premiers (taille-i) elements dans la liste */
        for(int j=0; j<taille-i-1; j++){
            if(ud){ // m = min
                if(m->l.annee > p->l.annee){
                    m = p;
                    q = pre;
                }
            } else{ // m = max
                if(m->l.annee < p->l.annee){
                m = p;
                q = pre;
            }
            }
            pre = p;
            p = p->next;
        }
        while(p != nullptr){
            pre = p;
            p = p->next;
        }
        if(m != pre){ // deplacement neccessaire
            /* supprimer m entre les premiers (taille-i) elements dans la liste */
            if(q != nullptr) q->next = m->next;
            else head = m->next;
            /* l'ajouter a la fin */
            pre->next = m;
            m->next = nullptr;
        }
        p = head; // mettre a jour p pour recommencer
        // affi_livres(p); // debug en affichant le processus de tri
    }
    if(ud) cout << "Voici le résultat après avoir trié les livres par année dans l'ordre croissant: " << endl;
    else cout << "Voici le résultat après avoir trié les livres par année dans l'ordre décroissant: " << endl;
    affi_livres(p);
}

/* Quitter le programme en libérant toute la mémoire allouée */
void quitter_livres(list& p){
    while(p != nullptr){
        p = p->next;
        delete[] p;
    }
    cout << "Sortie réussie! Aurevoir~" << endl;
}
