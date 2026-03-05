# Anagrams Exam Project

## Structure

Ce projet est un environnement de partiel pour implémenter des fonctions sur les anagrammes.

### Fichiers à modifier :

1. **`src/anagrams.c`** - Implémentez les 3 exercices ici:
   - `compare_chars()` - EXO 1: Comparer 2 caractères avec sensibilité à la casse
   - `are_anagrams()` - EXO 2: Vérifier si 2 mots sont des anagrammes
   - `find_anagrams()` - EXO 3: Lire un dictionnaire et compter les anagrammes

2. **`inc/functions.h`** - Contient les signatures des fonctions (à ne pas modifier)

### Fichiers avec tests unitaires :

- **`src/main.c`** - Contient automatiquement les tests pour valider votre implémentation

## Utilisation

### Compiler :
```bash
make
```
Cela génère un exécutable `out/bin/exam` et une bibliothèque partagée `out/lib/libanagrams.so`

### Tester :
```bash
make run
```
Cela compile et exécute immédiatement les tests unitaires.

### Nettoyer :
```bash
make clean
```
Supprime les fichiers compilés.

## Tests

Les tests unitaires vérifient :

**EXO 1 - Compare Characters:**
- Comparaison sensible à la casse : `'a' == 'a'`, `'A' != 'a'`
- Comparaison insensible à la casse : `'A' == 'a'`

**EXO 2 - Anagrams:**
- Détection simple : `"listen"` anagramme de `"silent"`
- Rejet de non-anagrammes : `"hello"` != `"world"`
- Insensibilité à la casse et espaces : `"Dormitory"` anagramme de `"Dirty room"`
- Différentes longueurs : `"abc"` != `"ab"`

**EXO 3 - Dictionary:**
- Recherche dans un fichier dictionnaire
- Compte les anagrammes trouvés
- Un fichier de test `data/test_dictionary.txt` est créé automatiquement

## Notes

- Les warnings d'unused parameters sont normaux au démarrage
- Les tests échouent tant que les fonctions ne sont pas implémentées
- Votre code est correct quand tous les tests passent (`Tests Failed: 0`)
1. The function should correctly decipher the message by shifting each letter in the opposite direction of the encoding.
2. Both uppercase (`A-Z`) and lowercase (`a-z`) letters should be handled.
3. Non-alphabetic characters should remain unchanged.

### Example
```c
char message[] = "Khoor Zruog!";
int shift = 3;
caesarDecipher(message, shift);
printf("%s\n", message); // Output: "Hello World!"
```

Good luck!

## Exercise: Unscrapper

In this exercise, you are given a data file containing a key phrase that has been split into segments. Each segment is surrounded by `scr://` and `;`. Your task is to extract and reconstruct the key phrase from these segments.

For example, if the data file contains the following text:
```
random text scr://key; more random text scr://phrase; even more random text
```

The key phrase to extract would be:
```
key phrase caesar ciphered
```

Steps to complete the exercise:
1. The name of the file shall be passed as argument of the main function.
2. Read the data file.
3. Identify and extract all segments surrounded by `scr://` and `;`.
4. Concatenate the extracted segments to form the key phrase.
5. Use caesarDecipher to get message in clear.

The file that has been sumitted to you is located under the `data/scrambled.dat` path (important clue: first character uncyphered is an 's').

Good luck!

## Tips

- **Using `fgets`**: This function can be used to read a line from the data file. It reads until a newline character or the end of the file is reached. Check the [man page for `fgets`](https://man7.org/linux/man-pages/man3/fgets.3.html) for more details.
- **Using `fopen` and `fclose`**: The `fopen` function is used to open a file, and `fclose` is used to close it. When opening a file for reading, use the mode `"r"`. Here is an example:

    ```c
    FILE *file = fopen("filename.txt", "r");
    if (file == NULL) {
            // Handle error
    }
    // Perform file operations
    fclose(file);
    ```

    Check the [man page for `fopen`](https://man7.org/linux/man-pages/man3/fopen.3.html) and [man page for `fclose`](https://man7.org/linux/man-pages/man3/fclose.3.html) for more details.

Refer to the man pages for detailed usage and examples.