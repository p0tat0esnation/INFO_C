#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

/* Check if two words are anagrams, case sensitively or not.
    @param word1 First word
    @param word2 Second word
    @param case_sensitive 1 for case sensitive, 0 for case insensitive
    @returns 1 if anagrams, 0 otherwise
*/
int is_anagram(const char *word1, const char *word2, int case_sensitive)
{
    if (!word1 || !word2)
    {
        return 0;
    }

    // Les anagrammes doivent avoir la même longueur
    if (strlen(word1) != strlen(word2))
    {
        return 0;
    }

    int len = strlen(word1);
    int used[len];
    for (int i = 0; i < len; i++)
    {
        used[i] = 0;
    }

    // Pour chaque caractère du premier mot
    for (int i = 0; word1[i]; i++)
    {
        int found = 0;
        // Chercher un caractère égal dans word2 avec compare_characters
        for (int j = 0; word2[j]; j++)
        {
            if (!used[j] && compare_characters(word1[i], word2[j], case_sensitive))
            {
                used[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            return 0;
        }
    }

    return 1;
}