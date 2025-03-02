# Gestion d'une base de données de livres

## Description
Ce projet implémente une gestion simple d'une bibliothèque en C++ en utilisant trois classes principales :
- **Book** : représente un livre avec un titre, un auteur et une année de publication.
- **Library** : gère une collection de livres et fournit des fonctionnalités pour ajouter, supprimer, rechercher et trier des livres.
- **Menu** : permet une interaction utilisateur via un menu pour gérer les livres de la bibliothèque.

L'utilisateur peut ajouter, supprimer, rechercher et afficher les livres de la bibliothèque via un menu interactif.

## Fonctionnalités
- **Ajouter un livre** avec un titre, un auteur et une année.
- **Supprimer un livre** en fonction de son titre.
- **Rechercher un livre** par son titre.
- **Trier les livres** selon leur titre.
- **Afficher tous les livres** présents dans la bibliothèque.
- **Quitter** le programme proprement.

## Prérequis
- Un compilateur C++ compatible avec le standard **C++11** (GCC, Clang, MSVC, etc.).
- **CMake** pour la gestion de la compilation.

## Structure du projet
```
LibraryManagement/
│── CMakeLists.txt
│── compile.sh
│── includes/
│   ├── Book.h
│   ├── Library.h
│   ├── Menu.h
│── src/
│   ├── Book.cpp
│   ├── Library.cpp
│   ├── Menu.cpp
│   ├── main.cpp
│── bin/  (dossier de sortie après compilation)
│── build/ (dossier temporaire pour la compilation)
│── README.md
```

## Implémentation

### Compilation avec CMake
1. Exécuter le script de compilation :
   ```bash
   ./compile.sh
   ```
   Cela va générer l'exécutable dans le dossier `bin/`.

2. Alternativement, tu peux compiler manuellement avec les commandes :
   ```bash
   mkdir -p build
   cd build
   cmake ..
   make
   cd ..
   ```

### Exécution
Lancer le programme avec :
```bash
./bin/LibraryManagement
```

Le processus demande d'abord à l'utilisateur de saisir la taille et l'ordre pour initialiser une liste de livres. Ensuite, un menu interactif s'affichera pour naviguer entre les différentes fonctionnalités.

## Améliorations futures
- **Sauvegarde et chargement des livres** dans un fichier pour conserver les données entre les sessions.
- **Gestion avancée des erreurs** pour éviter l'ajout de livres avec des champs invalides.
- **Ajout d'une interface graphique** pour une meilleure expérience utilisateur.

## Contact
Pour toute question ou suggestion concernant ce projet, vous pouvez me contacter :  
- **Email** : [jiangmengmeng1211@gmail.com](mailto:jiangmengmeng1211@gmail.com)  
- **GitHub** : [GitHub Repository](https://github.com/Jiang-mengmeng/Gestion-d-une-base-de-donnees-de-livres)  
