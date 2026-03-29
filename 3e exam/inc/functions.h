#pragma once

/* Compare deux caractères, avec option de sensibilité à la casse.
    @param first_char Premier caractère
    @param second_char Deuxième caractère
    @param case_sensitive 1 si sensible à la casse, 0 sinon
    @returns 1 si égaux, 0 sinon
*/
int compare_characters(const char first_char, char second_char, int case_sensitive);

/* Vérifie si deux mots sont des anagrammes, avec ou sans casse.
    @param word1 Premier mot
    @param word2 Deuxième mot
    @param case_sensitive 1 si sensible à la casse, 0 sinon
    @returns 1 si anagrammes, 0 sinon
*/
int is_anagram(const char *word1, const char *word2, int case_sensitive);

/* Cherche les anagrammes d'un mot dans un fichier dictionnaire et les affiche avec printf.
    @param file_path Chemin du fichier dictionnaire
    @param word Mot recherché
    @param case_sensitive 1 si sensible à la casse, 0 sinon
    @return nombre d'anagrammes trouvés
*/
int find_anagram_in_dict(const char *file_path, const char *word, int case_sensitive);
