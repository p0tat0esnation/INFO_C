#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"

/* Compare two characters, with optional case sensitivity
    @param first_char First character
    @param second_char Second character
    @param case_sensitive 1 for case sensitive, 0 for case insensitive
    @returns 1 if equal, 0 otherwise
*/
int compare_characters(const char first_char, char second_char, int case_sensitive)
{
    if (case_sensitive)
    {
        return first_char == second_char;
    }
    else
    {
        return tolower(first_char) == tolower(second_char);
    }
    return 0;
}