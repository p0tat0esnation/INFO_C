#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

/* Find anagrams of a word in a dictionary file, print them to stdout using printf
    @param file Path to the dictionary file
    @param word Word to find anagrams for
    @param case_sensitive 1 for case sensitive, 0 for case insensitive
    @return number of anagrams found
*/
int find_anagram_in_dict(const char *file_path, const char *word, int case_sensitive)
{
    int nb_anagrames = 0;
    int nb_mots = 0;
    int c;
    char line[256];

    FILE *fp = fopen(file_path, "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return -1;
    }

    while (fgets(line, sizeof line, fp))
    {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0)
            continue;
        if (is_anagram(word, line, case_sensitive) == 1)
        {
            nb_anagrames++;
        }
    }

    return nb_anagrames;
}