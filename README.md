# Gestion d'une base de données de livres

## Description
Ce projet implémente une gestion simple d'une base de données de livres en utilisant une **classe** avec une liste chaînée intégrée. L'utilisateur peut initialiser, afficher, ajouter, supprimer, rechercher et trier des livres de la liste de manière interactive.

## Fonctionnalités
- **Initialiser une liste de livres** avec une taille et un ordre (croissant ou décroissant).
- **Afficher la liste des livres** avec leur titre, auteur et année de publication.
- **Ajouter un livre** à la liste (ajout en tête ou en queue).
- **Supprimer un livre** de la liste en fonction du titre, de l'auteur ou de l'année.
- **Rechercher un livre** par titre, auteur ou année.
- **Trier les livres** par titre, auteur ou année (ordre croissant ou décroissant).
- **Quitter** le programme tout en libérant la mémoire allouée dynamiquement.

## Prérequis
- Un compilateur C++ (GCC, Clang, MSVC, etc.).
- Un terminal ou un IDE pour exécuter le programme.

## Implémentation

### Compilation
Pour compiler le programme avec `Makefile`, utilisez la commande :  
   ```bash
   make
   ``` 
Pour supprimer tous les fichiers générés par le Makefile, utilisez la commande :  
   ```bash
   make clean 
   ``` 

### Exécution
Lance le programme avec :
```sh
 ./gestion_livres
```

Le processus demande d'abord à l'utilisateur de saisir la taille et l'ordre pour initialiser une liste de livres. Ensuite, un menu interactif s'affichera pour naviguer entre les différentes fonctionnalités.

## Améliorations futures
- Vérification des entrées utilisateur pour éviter l'ajout de livres avec des champs invalides.
- Implémentation d'une sauvegarde des livres dans un fichier pour conserver les données entre les sessions.
- Utilisation d'une interface graphique pour rendre l'application plus conviviale.

## Contact
Pour toute question ou suggestion concernant ce projet, vous pouvez me contacter :  
- **Email** : [jiangmengmeng1211@gmail.com](mailto:jiangmengmeng1211@gmail.com)  
- **GitHub** : [GitHub Repository](https://github.com/Jiang-mengmeng/Gestion-d-une-base-de-donnees-de-livres)  
