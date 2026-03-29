````markdown
Partiel IN331 — Sujet (sans correction)
=======================================

## Contexte

On souhaite développer un programme en C permettant de manipuler des **anagrammes**.
Le programme doit vérifier si deux mots sont des anagrammes et rechercher les anagrammes d'un mot dans un fichier dictionnaire.

> ⚠️ Ce dossier est un **sujet d'examen** : les fichiers `src/*.c` sont volontairement incomplets.

## Arborescence

- `inc/functions.h` : signatures imposées.
- `src/compare_characters.c` : comparaison de caractères avec/sans casse.
- `src/is_anagram.c` : vérification d'anagramme entre deux chaînes.
- `src/find_anagram_in_dict.c` : recherche dans un fichier dictionnaire.
- `src/anagram.c` : programme principal (gestion des arguments).
- `test/main_test.c` : tests unitaires publics d'évaluation.
- `data/testset.txt` : petit jeu de données pour tests.
- `data/words` : dictionnaire plus large.

## Travail demandé

Implémenter les fonctions suivantes **sans modifier leurs prototypes** :

1. `compare_characters(const char first_char, char second_char, int case_sensitive)`
2. `is_anagram(const char *word1, const char *word2, int case_sensitive)`
3. `find_anagram_in_dict(const char *file_path, const char *word, int case_sensitive)`
4. `main(int argc, const char *argv[])` dans `src/anagram.c`

## Contraintes

- C11, compilation sans avertissements bloquants avec `-Wall -Wextra`.
- Utiliser `printf` pour afficher les anagrammes trouvés.
- Gérer proprement les erreurs (arguments invalides, fichier introuvable, etc.).
- Ne pas changer la structure du projet.

## Compilation

Depuis la racine du dossier :

- `make clean all`

Le `Makefile` produit :

- `out/lib/libfunctions.so`
- `out/bin/anagram`
- `out/bin/main_test`

## Exécution

- Lancer les tests unitaires : `./out/bin/main_test`
- Lancer le programme : `./out/bin/anagram data/words eraser 0`

Format attendu :

- `./out/bin/anagram <dictionary_path> <word> <case_sensitive>`
- `case_sensitive = 1` : sensible à la casse
- `case_sensitive = 0` : insensible à la casse

## Évaluation (format type partiel)

Les tests publics fournis dans `test/main_test.c` valident :

- la comparaison de caractères,
- la détection d'anagrammes,
- la recherche dans un dictionnaire.

Le binaire de test retourne :

- `0` si tous les tests passent,
- `1` sinon.

Des cas supplémentaires peuvent être évalués lors de la correction.

## Conseils

- Commencer par `compare_characters`, puis `is_anagram`, puis `find_anagram_in_dict`, puis `main`.
- Consulter `man fopen`, `man fgets`, `man fclose`, `man strlen`, `man tolower`.

````
