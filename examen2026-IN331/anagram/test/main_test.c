#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main() {

    printf("=====================================\n");
    printf("Running tests for anagram functions...\n");
    printf("=====================================\n");
    
    //test for compare_characters
    printf("Testing compare_characters function:\n");
    printf("compare_characters('a', 'A', 0): %d (expected 1)\n", compare_characters('a', 'A', 0));
    printf("compare_characters('a', 'A', 1): %d (expected 0)\n", compare_characters('a', 'A', 1));
    printf("compare_characters('b', 'b', 1): %d (expected 1)\n", compare_characters('b', 'b', 1));
    printf("compare_characters('c', 'd', 0): %d (expected 0)\n", compare_characters('c', 'd', 0));
    printf("=====================================\n");

    //test for is_anagram
    printf("Testing is_anagram function:\n");
    printf("is_anagram('listen', 'silent', 0): %d (expected 1)\n", is_anagram("listen", "silent", 0));
    printf("is_anagram('Listen', 'silent', 0): %d (expected 1)\n", is_anagram("Listen", "silent", 0));
    printf("is_anagram('Listen', 'silent', 1): %d (expected 0)\n", is_anagram("Listen", "silent", 1));
    printf("is_anagram('hello', 'world', 0): %d (expected 0)\n", is_anagram("hello", "world", 0));
    printf("is_anagram('eraser', 'Anders', 0): %d (expected 0)\n", is_anagram("eraser", "Anders", 0));
    printf("=====================================\n");

    //test for find_anagram_in_dict
    printf("Testing find_anagram_in_dict function:\n");
    printf("Number of anagrams found for 'listen': %d (expected > 0, 'silent' is in words.txt)\n", find_anagram_in_dict("data/testset.txt", "listen", 0));
    printf("Number of anagrams found for 'eraser': %d (expected 0)\n", find_anagram_in_dict("data/testset.txt", "language", 0));

    printf("=====================================\n");
    printf("Tests completed.\n");
    printf("=====================================\n");

    return 0;
}