#pragma once

#include <stdbool.h>

/**
 * EXO 1: Compare 2 characters with case sensitivity option
 *
 * @param c1 First character
 * @param c2 Second character
 * @param case_sensitive If true, comparison is case-sensitive; if false, ignores case
 * @return true if characters match according to case_sensitivity parameter, false otherwise
 */
bool compare_chars(char c1, char c2, bool case_sensitive);

/**
 * EXO 2: Check if 2 words are anagrams using the previous function
 *
 * @param word1 First word
 * @param word2 Second word
 * @param case_sensitive If true, comparison is case-sensitive; if false, ignores case
 * @return true if words are anagrams, false otherwise
 */
bool are_anagrams(const char *word1, const char *word2, bool case_sensitive);

/**
 * EXO 3: Read dictionary file and count anagrams of a word
 *
 * @param dictionary_file Path to the dictionary file (one word per line)
 * @param target_word The word to find anagrams for
 * @param case_sensitive If true, comparison is case-sensitive; if false, ignores case
 * @param anagrams Array to store found anagrams (should be pre-allocated)
 * @param max_anagrams Maximum number of anagrams to store
 * @return Number of anagrams found
 */
int find_anagrams(const char *dictionary_file, const char *target_word,
                  bool case_sensitive, char **anagrams, int max_anagrams);

/**
 * EXO 4: Main function to use the dictionary function and print results
 * (This is implemented in main.c, but including the test structure here)
 */

/**
 * @brief Deciphers a given string using the Caesar cipher technique.
 *
 * This function takes an input string and shifts each character backwards
 * by the specified number of positions in the alphabet. The shift value
 * determines how many positions each character is moved. Non-alphabetic
 * characters are not modified.
 *
 * @param str The input string to be deciphered. This string is modified in place.
 * @param shift The number of positions to shift each character backwards.
 *
 * @note The function assumes that the input string contains only ASCII characters.
 *
 * @example
 * char text[] = "khoor";
 * caesarDecipher(text, 3);
 * // text now contains "hello"
 */
void caesarDecipher(char *str, int shift);

/**
 * @brief Extracts information from the specified input file and stores it in the provided message buffer.
 *
 * This function reads data from the given input file and processes it to extract relevant information.
 * The extracted information is then stored in the message buffer provided by the caller.
 *
 * @param input_file The path to the input file from which information is to be extracted.
 * @param message A buffer to store the extracted information. The caller must ensure that the buffer
 *                is large enough to hold the extracted data.
 * @return An integer indicating the success or failure of the operation. Typically, a return value
 *         of 0 indicates success, while a non-zero value indicates an error.
 */
int extract_information(const char *input_file, char *message);