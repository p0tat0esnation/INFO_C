#include <stdio.h>

#include "functions.h"

int main(int argc, const char *argv[])
{

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printf("========================================================\n");
    for (int i = 1; i < argc; i++)
    {
        file_line_metrics metrics;
        compute_file_metrics(argv[i], &metrics);

        printf("File metrics for \"%s\":\n", argv[i]);
        printf("- Min line length: %d\n", metrics.min_length);
        printf("- Max line length: %d\n", metrics.max_length);
        printf("- Total line length: %d\n", metrics.total_length);
        printf("- Line count: %d\n", metrics.line_count);
        printf("========================================================\n");
    }

    printf("========================================================\n");
    int fib[4];
    fibonnacci(4, fib);
    printf("First 4 Fibonacci numbers:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");
    printf("========================================================\n");

    printf("========================================================\n");
    char message1[] = "Khoor Zruog!";
    int shift = 3;
    caesarDecipher(message1, shift);
    printf("%s\n", message1); // Output: "Hello World!"
    printf("========================================================\n");

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char message[1024];

    if (extract_information(argv[1], message) == 0)
    {
        printf("========================================================\n");
        printf("Extracted message: \"%s\"\n", message);
        printf("========================================================\n");
    }

    return 0;
}