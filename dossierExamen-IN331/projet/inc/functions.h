#pragma once

/**
 * @struct file_line_metrics
 * @brief Structure to hold metrics about lines in a file.
 *
 * This structure is used to store various metrics related to the lines in a file.
 *
 * @var file_line_metrics::min_length
 * Minimum length of a line in the file.
 *
 * @var file_line_metrics::max_length
 * Maximum length of a line in the file.
 *
 * @var file_line_metrics::total_length
 * Total length of all lines in the file.
 *
 * @var file_line_metrics::line_count
 * Total number of lines in the file.
 */
typedef struct
{
    int min_length;
    int max_length;
    int total_length;
    int line_count;
} file_line_metrics;

/**
 * @brief Computes metrics for a given file.
 *
 * This function reads the specified file and computes various metrics
 * related to its contents, storing the results in the provided metrics
 * structure.
 *
 * @param filename The path to the file for which metrics are to be computed.
 * @param metrics A pointer to a file_line_metrics structure where the computed
 *                metrics will be stored.
 */
void compute_file_metrics(const char *filename, file_line_metrics *metrics);


/**
 * @brief Computes the first n values of the Fibonacci sequence.
 * 
 * This function computes the first n values of the Fibonacci sequence and stores
 * them in the provided array.
 * 
 */
void fibonnacci(int n, int values[]);


/**
 * @brief Deciphers a given string using the Caesar cipher technique.
 *
 * This function takes an input string and shifts each character backwards
 * by the specified number of positions in the alphabet. The shift value
 * determines how many positions each character is moved. Non-alphabetic
 * characters are not modified.
 *
 * @param str The input string to be deciphered. This string is modified in place.
 * @param shift The number of positions to shift each character backwards.
 *
 * @note The function assumes that the input string contains only ASCII characters.
 *
 * @example
 * char text[] = "khoor";
 * caesarDecipher(text, 3);
 * // text now contains "hello"
 */
void caesarDecipher(char *str, int shift);


/**
 * @brief Extracts information from the specified input file and stores it in the provided message buffer.
 *
 * This function reads data from the given input file and processes it to extract relevant information.
 * The extracted information is then stored in the message buffer provided by the caller.
 *
 * @param input_file The path to the input file from which information is to be extracted.
 * @param message A buffer to store the extracted information. The caller must ensure that the buffer
 *                is large enough to hold the extracted data.
 * @return An integer indicating the success or failure of the operation. Typically, a return value
 *         of 0 indicates success, while a non-zero value indicates an error.
 */
int extract_information(const char *input_file, char *message);