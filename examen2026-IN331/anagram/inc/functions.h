#pragma once

/* Compare two characters, with case sensitivity option
    @param first_char First character
    @param second_char Second character
    @param case_sensitive 1 for case sensitive, 0 for case insensitive
    @returns 1 if equal, 0 otherwise
*/
int compare_characters(const char first_char, char second_char, int case_sensitive);

/* Check if two words are anagrams, case sensitively or not.
    @param word1 First word
    @param word2 Second word
    @param case_sensitive 1 for case sensitive, 0 for case insensitive
    @returns 1 if anagrams, 0 otherwise
*/
int is_anagram(const char *word1, const char *word2, int case_sensitive);

/* Find anagrams of a word in a dictionary file, print them to stdout using printf
    @param file Path to the dictionary file
    @param word Word to find anagrams for
    @param case_sensitive 1 for case sensitive, 0 for case insensitive
    @return number of anagrams found
*/
int find_anagram_in_dict(const char *file_path, const char *word, int case_sensitive);
