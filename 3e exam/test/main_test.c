#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

static int tests_total = 0;
static int tests_ok = 0;

static void assert_equal_int(const char *label, int actual, int expected)
{
    tests_total++;
    if (actual == expected)
    {
        tests_ok++;
        printf("[OK]   %s -> %d\n", label, actual);
    }
    else
    {
        printf("[FAIL] %s -> obtenu=%d attendu=%d\n", label, actual, expected);
    }
}

int main(void)
{
    printf("=====================================\n");
    printf("Évaluation automatique - Sujet anagrammes\n");
    printf("=====================================\n\n");

    /* compare_characters */
    printf("[Bloc] compare_characters\n");
    assert_equal_int("'a' vs 'A' (insensible)", compare_characters('a', 'A', 0), 1);
    assert_equal_int("'a' vs 'A' (sensible)", compare_characters('a', 'A', 1), 0);
    assert_equal_int("'b' vs 'b' (sensible)", compare_characters('b', 'b', 1), 1);
    assert_equal_int("'c' vs 'd' (insensible)", compare_characters('c', 'd', 0), 0);
    printf("\n");

    /* is_anagram */
    printf("[Bloc] is_anagram\n");
    assert_equal_int("listen/silent (insensible)", is_anagram("listen", "silent", 0), 1);
    assert_equal_int("Listen/silent (insensible)", is_anagram("Listen", "silent", 0), 1);
    assert_equal_int("Listen/silent (sensible)", is_anagram("Listen", "silent", 1), 0);
    assert_equal_int("hello/world", is_anagram("hello", "world", 0), 0);
    assert_equal_int("eraser/Anders", is_anagram("eraser", "Anders", 0), 0);
    printf("\n");

    /* find_anagram_in_dict */
    printf("[Bloc] find_anagram_in_dict\n");
    assert_equal_int("listen dans testset", find_anagram_in_dict("data/testset.txt", "listen", 0), 1);
    assert_equal_int("language dans testset", find_anagram_in_dict("data/testset.txt", "language", 0), 0);
    printf("\n");

    printf("=====================================\n");
    printf("Résultat: %d/%d tests validés\n", tests_ok, tests_total);
    printf("=====================================\n");

    return (tests_ok == tests_total) ? 0 : 1;
}