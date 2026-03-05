#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

// Test counters
int tests_passed = 0;
int tests_failed = 0;

// Helper function to print test results
void assert_test(bool condition, const char *test_name)
{
    if (condition)
    {
        printf("✓ PASS: %s\n", test_name);
        tests_passed++;
    }
    else
    {
        printf("✗ FAIL: %s\n", test_name);
        tests_failed++;
    }
}

int main(int argc, const char *argv[])
{
    printf("===== ANAGRAMS EXAM - UNIT TESTS =====\n\n");

    // EXO 1: Test character comparison
    printf("--- EXO 1: Compare Characters ---\n");
    assert_test(compare_chars('a', 'a', true) == true, "EXO1: 'a' == 'a' (case-sensitive)");
    assert_test(compare_chars('A', 'a', true) == false, "EXO1: 'A' != 'a' (case-sensitive)");
    assert_test(compare_chars('A', 'a', false) == true, "EXO1: 'A' == 'a' (case-insensitive)");
    assert_test(compare_chars('x', 'y', false) == false, "EXO1: 'x' != 'y' (case-insensitive)");
    printf("\n");

    // EXO 2: Test anagram checking
    printf("--- EXO 2: Anagram Detection ---\n");
    assert_test(are_anagrams("listen", "silent", true) == true, "EXO2: 'listen' is anagram of 'silent'");
    assert_test(are_anagrams("hello", "world", true) == false, "EXO2: 'hello' is NOT anagram of 'world'");
    assert_test(are_anagrams("Dormitory", "Dirty room", false) == true, "EXO2: 'Dormitory' anagram of 'Dirty room' (ignore spaces/case)");
    assert_test(are_anagrams("abc", "ab", true) == false, "EXO2: different lengths cannot be anagrams");
    printf("\n");

    // EXO 3: Test dictionary search (requires dictionary file)
    printf("--- EXO 3: Dictionary Anagram Search ---\n");

    // Create a test dictionary file
    const char *test_dict = "data/test_dictionary.txt";
    FILE *dict_file = fopen(test_dict, "w");
    if (dict_file)
    {
        fprintf(dict_file, "listen\n");
        fprintf(dict_file, "silent\n");
        fprintf(dict_file, "enlist\n");
        fprintf(dict_file, "apple\n");
        fprintf(dict_file, "stone\n");
        fprintf(dict_file, "notes\n");
        fprintf(dict_file, "tones\n");
        fclose(dict_file);

        char *anagrams[100];
        for (int i = 0; i < 100; i++)
            anagrams[i] = malloc(256);

        int count = find_anagrams(test_dict, "listen", true, anagrams, 100);
        printf("Found %d anagrams for 'listen' in dictionary\n", count);
        assert_test(count >= 2, "EXO3: Should find at least 2 anagrams for 'listen'");

        count = find_anagrams(test_dict, "stone", true, anagrams, 100);
        printf("Found %d anagrams for 'stone' in dictionary\n", count);
        assert_test(count >= 2, "EXO3: Should find at least 2 anagrams for 'stone'");

        for (int i = 0; i < 100; i++)
            free(anagrams[i]);
    }
    else
    {
        printf("Warning: Could not create test dictionary file\n");
    }
    printf("\n");

    // EXO 4: Print summary
    printf("===== TEST SUMMARY =====\n");
    printf("Tests Passed: %d\n", tests_passed);
    printf("Tests Failed: %d\n", tests_failed);
    printf("Total Tests: %d\n", tests_passed + tests_failed);
    printf("========================\n");

    return tests_failed > 0 ? 1 : 0;

    char message[1024];

    if (extract_information(argv[1], message) == 0)
    {
        printf("========================================================\n");
        printf("Extracted message: \"%s\"\n", message);
        printf("========================================================\n");
    }

    return 0;
}