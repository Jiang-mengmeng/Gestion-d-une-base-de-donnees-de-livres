#include "livres.hpp"

/* [Constructeur] Initialiser une liste de livres avec n livres */
Livres::Livres(const int& taille, const bool& ud) : taille(taille), ud(ud) {
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
    p = suiv;
    affi_livres();
}
/* [Destructeur] Quitter le programme en libérant toute la mémoire allouée */
Livres::~Livres(){
    while(p != nullptr){
        p = p->next;
        delete p;
    }
    cout << "Sortie réussie! Aurevoir~" << endl;
}
/* Afficher la liste des livres (titre, auteur, année) */
void Livres::affi_livres(){
    node* head = p;
    while(p != nullptr){
        if(p->next != nullptr){
            cout << p->l.titre << " " << p->l.auteur << " " << p->l.annee << " -> ";
            p = p->next;
        } else{
            cout << p->l.titre << " " << p->l.auteur << " " << p->l.annee << endl;
            p = p->next;
        }
    }
    p = move(head); // restaurer la tête
}
/* Ajouter un livre au début de la liste des livres */
void Livres::head_ajoute_livre(){
    node* head = new node;
    cout << "Saisir le titre, l'auteur et l'année du livre svp: ";
    cin >> head->l.titre >> head->l.auteur >> head->l.annee;
    head->next = p;
    p = head; // restaurer la tête
    taille++; // mettre a jour la taille
    cout << "Voici le résultat après avoir ajouté le livre au début de la liste: " << endl;
    affi_livres();
}
/* Ajouter un livre à la fin de la liste des livres */
void Livres::tail_ajoute_livre(){
    node* tail = new node, *head = p;
    cout << "Saisir le titre, l'auteur et l'année du livre svp: ";
    cin >> tail->l.titre >> tail->l.auteur >> tail->l.annee;
    tail->next = nullptr;
    while(p->next != nullptr) p = p->next;
    p->next = tail;
    p = head; // restaurer la tête
    taille++; // mettre a jour la taille
    cout << "Voici le résultat après avoir ajouté le livre à la fin de la liste: " << endl;
    affi_livres();
}
/* Supprimer un livre par titre */
void Livres::supprimer_livres_par_titre(){
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
            delete q; // liberer la memoire allouee
            taille--; // mettre a jour la taille
        } else{ // livre courant ne corresponde pas
            pre = p;
            p = p->next;
        }
    }
    p = move(head); // restaurer la tête
    cout << "Voici le résultat après avoir supprimé un(des) livre(s) avec le titre <<" << title << ">> dans la liste:" << endl;
    affi_livres();
}
/* Supprimer un livre par auteur */
void Livres::supprimer_livres_par_auteur(){
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
            delete q; // liberer la memoire allouee
            taille--; // mettre a jour la taille
        } else{ // livre courant ne corresponde pas
            pre = p;
            p = p->next;
        }
    }
    p = move(head); // restaurer la tête
    cout << "Voici le résultat après avoir supprimé un(des) livre(s) avec l'auteur " << author << " dans la liste:" << endl;
    affi_livres();
}
/* Supprimer un livre par année */
void Livres::supprimer_livres_par_annee(){
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
            delete q; // liberer la memoire allouee
            taille--; // mettre a jour la taille
        } else{ // livre courant ne corresponde pas
            pre = p;
            p = p->next;
        }
    }
    p = move(head); // restaurer la tête
    cout << "Voici le résultat après avoir supprimé un(des) livre(s) avec l'année " << year << " dans la liste:" << endl;
    affi_livres();
}
/* Rechercher un livre par titre */
void Livres::rechercher_livres_par_titre(){
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
void Livres::rechercher_livres_par_auteur(){
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
void Livres::rechercher_livres_par_annee(){
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
void Livres::trier_livres_par_titre(){
    node* head = p;
    for(int i=0; i<taille; i++){
        /* reinitialiser */
        node* m = p, *pre = p, *q = nullptr; // q pour capturer le predecesseur
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
    affi_livres();
} 
/* Trier les livres par auteur */
void Livres::trier_livres_par_auteur(){
    node* head = p;
    for(int i=0; i<taille; i++){
        /* reinitialiser */
        node* m = p, *pre = p, *q = nullptr; // q pour capturer le predecesseur
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
    affi_livres();
}
/* Trier les livres par année */
void Livres::trier_livres_par_annee(){
    node* head = p;
    for(int i=0; i<taille; i++){
        /* reinitialiser */
        node* m = p, *pre = p, *q = nullptr; // q pour capturer le predecesseur
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
    affi_livres();
} 