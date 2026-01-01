File statistics
==================

## Guide

This project includes the following structure:

- **Makefile**: This file is used to manage the build process. It contains rules and dependencies to compile the project. This file is provided as read-only and should not be modified.
- **Header File (.h)**: This file contains function declarations, macros, and definitions that are shared across multiple C files. This file is also provided as read-only and should not be modified.
- **C File (.c)**: This file contains the actual implementation of the functions declared in the header file. The C file is initially provided with empty implementations, and you are required to modify this file to complete the project.

Please note that only the C files should be modified. The Makefile and header files are provided in read-only mode to ensure consistency and correctness in the build process and function declarations.


## Exercise: Fibonnacci

In this warm up exercise, you will write a C function that computes the Fibonacci value for a given integer `n`. The Fibonacci sequence is defined as follows:

- `F(0) = 0`
- `F(1) = 1`
- `F(n) = F(n-1) + F(n-2)` for `n > 1`

Files:
- header in `functions` header file 
- implementation in `fibo.c`

Good luck!

## Exercise: File Analysis

In this exercise, you will analyze a file and return some of its metrics. You are required to implement the methods defined in the `functions` header file. The metrics to be calculated include:

- Minimum line length
- Maximum line length
- Total length of all lines
- Line count

Refer to the `functions` header file for the input and output specifications of each method. Your implementation should be efficient and handle edge cases such as empty files and files with only whitespace.

Implementation has to be realized in `file_metrics.c`.

Good luck!

## Exercise: caesarDecipher

In this exercise, you will implement a function to decipher a message encoded with the Caesar cipher. The Caesar cipher shifts each letter in the plaintext by a fixed number of positions down the alphabet. For example, with a shift of 3, `A` becomes `D`, `B` becomes `E`, and so on. The function should handle both uppercase and lowercase letters, and preserve non-alphabetic characters unchanged.

Good luck!

### Requirements
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