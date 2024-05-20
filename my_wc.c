#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_BUFFER_SIZE 40
#define INITIAL_WORD_LIST_SIZE 10

// Define a struct to store words and their counts
typedef struct {
    char *word;
    int count;
} WordEntry;

// Print usage information
void print_usage() {
    fprintf(stderr, "Usage: wc [-l] [-c] [-w] [-f] [-v] [-h] [-d]\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Declare variables
    int line_count = 0, char_count = 0, word_count = 0, all_words_count = 0;
    int opt_l = 0, opt_c = 0, opt_w = 0, opt_f = 0, opt_v = 0, opt_h = 0, opt_d = 0;
    char *buffer = NULL;
    size_t buffer_size = 0;
    WordEntry *word_list = NULL;
    size_t word_list_size = 0;

    // Parse command line options
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            opt_l = 1;
        } else if (strcmp(argv[i], "-c") == 0) {
            opt_c = 1;
        } else if (strcmp(argv[i], "-w") == 0) {
            opt_w = 1;
        } else if (strcmp(argv[i], "-f") == 0) {
            opt_f = 1;
        } else if (strcmp(argv[i], "-v") == 0) {
            opt_v = 1;
        } else if (strcmp(argv[i], "-h") == 0) {
            opt_h = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            opt_d = 1;
        } else {
            fprintf(stderr, "Invalid option: %s\n", argv[i]);
            print_usage();
            return 1;
        }
    }
    // Print debug information
    if (opt_h) {
        print_usage();
        return 0;
    }
    if (!opt_l && !opt_c && !opt_w && !opt_f && !opt_v) {
        opt_w = 1;
    }
    if (opt_v) {
        opt_l = opt_c = opt_w = opt_f = 1;
    }
    // Read input and count lines, characters, and words
    buffer = malloc(INITIAL_BUFFER_SIZE);
    buffer_size = INITIAL_BUFFER_SIZE;
    word_list = malloc(INITIAL_WORD_LIST_SIZE * sizeof(WordEntry));
    word_list_size = INITIAL_WORD_LIST_SIZE;
    int c;
    size_t buf_pos = 0, line_start = 0;
    // Read input character by character
    while ((c = getchar()) != EOF) {
        if (buf_pos == buffer_size - 1) {
            buffer_size += INITIAL_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size);
        }
        buffer[buf_pos++] = (char)c;

        if (c == '\n') {
            line_count++;
        }
        // Check for whitespace or end of file
        if (isspace(c) || c == EOF) {
            buffer[buf_pos - 1] = '\0';
            char *word = &buffer[line_start];
            size_t word_length = strlen(word);
            // Check if word is not empty
            if (word_length > 0) {
                int found = 0;
                // Check if word is already in list
                for (size_t i = 0; i < word_count; i++) {
                    if (strcmp(word_list[i].word, word) == 0) {
                        word_list[i].count++;
                        all_words_count++;
                        found = 1;
                        break;
                    }
                }
                // Add word to list if not found
                if (!found) {
                    if (word_count == word_list_size) {
                        word_list_size += INITIAL_WORD_LIST_SIZE;
                        word_list = realloc(word_list, word_list_size * sizeof(WordEntry));
                    }

                    word_list[word_count].word = strdup(word);
                    word_list[word_count].count = 1;
                    word_count++;
                    all_words_count++;
                }
                
            }
            // Reset line start
            line_start = buf_pos;
        }
        // Increment character count
        char_count++;
    }

    // Process the last word in the input if it doesn't end with a whitespace character
    if (char_count > 0 && !isspace(buffer[char_count - 1])) {
        buffer[char_count] = '\0';
        char *word = &buffer[line_start];
        size_t word_length = strlen(word);
        if (word_length > 0) {
            int found = 0;
            for (size_t i = 0; i < word_count; i++) {
                if (strcmp(word_list[i].word, word) == 0) {
                    word_list[i].count++;
                    all_words_count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (word_count == word_list_size) {
                    word_list_size += INITIAL_WORD_LIST_SIZE;
                    word_list = realloc(word_list, word_list_size * sizeof(WordEntry));
                }

                word_list[word_count].word = strdup(word);
                word_list[word_count].count = 1;
                word_count++;
                all_words_count++;
            }
        }
    }

// ... (printing the results and freeing memory)



    // Print results
    if (opt_w) {
        printf("word_count: %d\n", all_words_count);
    }
    if (opt_l) {
        printf("line_count: %d\n", line_count);
    }
    if (opt_c) {
        printf("char_count: %d\n", char_count);
    }
    if (opt_f) {
        printf("word_frequency:\n");
        for (size_t i = 0; i < word_count; i++) {
            printf("%s: %d\n", word_list[i].word, word_list[i].count);
        }
    }
    // Free memory
    for (size_t i = 0; i < word_count; i++) {
        free(word_list[i].word);
    }
    free(word_list);
    free(buffer);

    return 0;
}


/*
I will be keeping the pseudocode for this assignment below for reference.

Pseudocode:

Initialize line_count, char_count, and word_count to 0
Initialize option flags (opt_l, opt_c, opt_w, opt_f, opt_v, opt_h, opt_d) to 0
Initialize buffer and buffer_size
Initialize word_list and word_list_size

Parse command line options:
    Set corresponding option flag to 1 for each option provided

If opt_h is set:
    Print usage message and exit

If no options are provided:
    Set opt_w to 1

If opt_v is set:
    Set opt_l, opt_c, opt_w, and opt_f to 1

Allocate memory for buffer and word_list

While reading characters from stdin:
    If buffer is full:
        Reallocate memory for buffer

    Add character to buffer

    If character is a newline:
        Increment line_count

    If character is whitespace or end-of-file:
        Mark the end of the word in the buffer

        If the word is non-empty:
            Initialize found flag to 0

            Iterate through word_list:
                If the word is in word_list:
                    Increment the count for that word
                    Set found flag to 1
                    Break

            If word not found:
                If word_list is full:
                    Reallocate memory for word_list

                Add the word to word_list with count 1
                Increment word_count

        Update the starting position for the next word

    Increment char_count

If opt_w is set:
    Print word_count

If opt_l is set:
        Print line_count

If opt_c is set:
        Print char_count

If opt_f is set:
    Print word_frequency:

    Iterate through word_list:
        Print word and count
Free memory
Exit
*/