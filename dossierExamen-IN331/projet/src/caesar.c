#include "functions.h"
#include <string.h>

void caesarDecipher(char *str, int shift)
/* fonction pour dechiffrer un texte avec le chiffre de cesar */
{
    int longueur = strlen(str);
    for (int i = 0; i < longueur; i++)
    {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
        {
            if ('a' <= str[i] && str[i] <= 'z')
            {
                str[i] = 'a' + (str[i] - 'a' - shift + 26) % 26;
            }
            else if ('A' <= str[i] && str[i] <= 'Z')
            {
                str[i] = 'A' + (str[i] - 'A' - shift + 26) % 26;
            }
        }
        else
        {
            str[i] = str[i];
        }
    }
    return;
}
