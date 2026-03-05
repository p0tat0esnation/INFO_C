#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * EXO 1: Compare 2 characters with case sensitivity option
 */
bool compare_chars(char c1, char c2, bool case_sensitive)
{
    // TODO: Implement comparison logic
    // If case_sensitive is false, convert both to lowercase before comparing

    if (!case_sensitive)
    {
        c1 = tolower(c1);
        c2 = tolower(c2);
    }
    else
    {
        // If case_sensitive is true, compare as is
    }
    return c1 == c2;
}

/**
 * EXO 2: Check if 2 words are anagrams (use compare_chars for character comparison)
 */
bool are_anagrams(const char *word1, const char *word2, bool case_sensitive)
{
    if (!word1 || !word2)
        return false;

    /* Count character frequencies for both words, taking case sensitivity into account */
    int freq1[256] = {0};
    int freq2[256] = {0};

    for (const unsigned char *p = (const unsigned char *)word1; *p; p++)
    {
        unsigned char c = *p;
        if (!case_sensitive)
        {
            if (isspace(c))
                continue; // Ignore spaces when case-insensitive
            c = (unsigned char)tolower(c);
        }
        freq1[c]++;
    }

    for (const unsigned char *p = (const unsigned char *)word2; *p; p++)
    {
        unsigned char c = *p;
        if (!case_sensitive)
        {
            if (isspace(c))
                continue; // Ignore spaces when case-insensitive
            c = (unsigned char)tolower(c);
        }
        freq2[c]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq1[i] != freq2[i])
            return false; // Different character frequencies: not anagrams
    }

    return true; // Same character frequencies: they are anagrams
}

/**
 * EXO 3: Read dictionary file and count anagrams
 */
int find_anagrams(const char *dictionary_file, const char *target_word,
                  bool case_sensitive, char **anagrams, int max_anagrams)
{
    // TODO: Implement dictionary reading and anagram finding
    // Use are_anagrams function to check each word
    FILE *file = fopen(dictionary_file, "r");
    if (!file)
        return -1; // Could not open file
    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), file))
    {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        if (are_anagrams(target_word, line, case_sensitive))
        {
            if (count < max_anagrams)
            {
                strncpy(anagrams[count], line, sizeof(line) - 1);
                anagrams[count][sizeof(line) - 1] = '\0'; // Ensure null-termination
            }
            count++;
        }
    }
    fclose(file);
    return count;
}
