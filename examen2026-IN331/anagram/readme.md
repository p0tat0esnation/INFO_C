````markdown
Anagram
==================

## Introduction

This exercise provides functions to detect anagrams and to search for anagrams of a given word in a dictionary file. The program reads a dictionary, compares words, and prints any anagrams it finds.

## Compilation

The provided `Makefile` builds a shared library and two binaries into `out/bin` with supporting code placed in `out/lib`. Run `make` from the project root to build everything.

## How to run

A test binary for unitary functions is located at [out/bin/main_test](out/bin/main_test).

The main binary is located at [out/bin/anagram](out/bin/anagram).

From the project root you can build and run the tests and program:

```bash
make clean all
./out/bin/main_test
./out/bin/anagram data/words eraser 0
```

Notes:
- Arguments: `./out/bin/anagram <dictionary_path> <word> <case_sensitive>`
  - `case_sensitive` should be `1` for case-sensitive comparison, `0` for case-insensitive.
- The dictionary file included is `data/words`.

## Implementation details

- Function prototypes are declared in the header at [inc/functions.h](inc/functions.h).
- `compare_characters` (src/compare_characters.c): compare two characters with optional case sensitivity.
- `is_anagram` (src/is_anagram.c): determine whether two words are anagrams.
- `find_anagram_in_dict` (src/find_anagram_in_dict.c): scan the dictionary file and print matching anagrams using `printf`.
- `anagram` (src/anagram.c): program entry point; parse command-line arguments and call `find_anagram_in_dict`.

### Suggested workflow

- Implement and test `compare_characters` first.
- Implement `is_anagram` using `compare_characters`.
- Implement `find_anagram_in_dict` to open the dictionary, use `is_anagram` and print matches; return the number of matches.
- Implement `main` in `anagram.c` to parse arguments and return `0` if at least one anagram was found, otherwise `1`.

### Hints

- Use `man` command to get information about standard functions.
- Use `fopen()` to open the dictionary file in read mode (`"r"`). Check the return value for `NULL` to handle errors.
- Use `fgets()` to read lines from the file into a buffer. It automatically handles newlines and null-terminates strings.
- Use `fclose()` to close the file when done reading. See `man fopen`, `man fgets`, and `man fclose` for details.

````
