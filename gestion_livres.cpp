#include "livres.hpp"

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
    Livres liv(taille, ud);
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
                liv.affi_livres();
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
                    if(head) liv.head_ajoute_livre();
                    else liv.tail_ajoute_livre();
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
                        cout << "Saisir le titre du livre vous souhaitez supprimer svp: ";
                        cin >> liv.title;
                        liv.supprimer_livres_par_titre();
                        break;
                    }
                    case 1:{
                        cout << "Saisir l'auteur du livre vous souhaitez supprimer svp: ";
                        cin >> liv.author;
                        liv.supprimer_livres_par_auteur();
                        break;
                    }
                    case 0:{
                        cout << "Saisir l'année du livre vous souhaitez supprimer svp: ";
                        cin >> liv.year;
                        liv.supprimer_livres_par_annee();
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
                        cout << "Saisir le titre du livre vous souhaitez rechercher svp: ";
                        cin >> liv.title;
                        liv.rechercher_livres_par_titre();
                        break;
                    }
                    case 1:{
                        cout << "Saisir l'auteur du livre vous souhaitez rechercher svp: ";
                        cin >> liv.author;
                        liv.rechercher_livres_par_auteur();
                        break;
                    }
                    case 0:{
                        cout << "Saisir l'année du livre vous souhaitez rechercher svp: ";
                        cin >> liv.year;
                        liv.rechercher_livres_par_annee();
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
                cin >> liv.ud;
                if(liv.ud!=0 && liv.ud!=1){
                    cerr << "Invalide parametre!\n" << endl;
                    break;
                }
                switch(y){
                    case 2:{
                        liv.trier_livres_par_titre();
                        break;
                    }
                    case 1:{
                        liv.trier_livres_par_auteur();
                        break;
                    }
                    case 0:{
                        liv.trier_livres_par_annee();
                        break;
                    }
                    default:;
                }
                cout << endl;
                break;
            }
            case 6:{ // Quitter
                return EXIT_SUCCESS;
            }
            default:;
        }
    }
}
