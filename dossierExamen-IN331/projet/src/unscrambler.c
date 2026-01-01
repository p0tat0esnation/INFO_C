#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int extract_information(const char *input_file, char *message)
{
    FILE *file = fopen(input_file, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    message[0] = '\0';
    char line[1024];

    while (fgets(line, sizeof(line), file))
    {
        char *p = line;

        while ((p = strstr(p, "scr://")) != NULL)
        {
            p += 6;                     // saute "scr://"
            char *end = strchr(p, ';'); // trouve ';'
            if (!end)
                break;

            // Ajoute un espace entre les morceaux (pour retrouver "secret code")
            if (message[0] != '\0')
                strcat(message, " ");

            strncat(message, p, (size_t)(end - p));
            p = end + 1;
        }
    }

    // Bon décalage pour obtenir "secret code" depuis "tfdsf...":
    caesarDecipher(message, 1);




    fclose(file);
    return 0;
}
