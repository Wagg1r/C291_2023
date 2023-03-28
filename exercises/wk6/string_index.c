// word frequency counter
// Author: Thomas Waggoner

/*****************************************************************************
 * 
 * Psuedocode here:
 * index_buffer_by_array
 * 
 * 
*****************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
//#include <string.h>
#include "string_index.h"


#define BUFFER_SIZE 2048
#define WORD_LIMIT 100
#define NOT_FOUND -1
#define WD_BGN  0
#define WD_END  1


int main(void) {
    // variable declartaions 

    char buffer[BUFFER_SIZE];
    int words_found = 0;
    int word_index_array[WORD_LIMIT][2] = {{0}};
    int word_counts[WORD_LIMIT] = {0};
    const char *word_index[WORD_LIMIT][2] = {{0}};

    // initialize storage

    /* ***** DO NOT CHANGE ANY CODE BEYOND THIS POINT IN main() ****** */
    initialize_buffer(buffer);
    
    // pointer

     //words_found = index_buffer_by_ptr(buffer, word_index, word_counts);

     //print_report_by_ptr(buffer, word_index, word_counts, words_found);
    
    // array
    printf("\n");
        
    words_found = index_buffer_by_array(buffer, word_index_array, word_counts);

    print_report_by_array(buffer, word_index_array, word_counts, words_found);
    
} // end main

int initialize_buffer(char buffer[]){
	// initialize variables
    for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = '\0';
}   
	char letter = 'a';
	int num_chars = -1;
	// if its not the end of file or the buffer size keep reading characters and saving them all into an array 
	while ((letter != EOF && num_chars < BUFFER_SIZE-1)){
        letter = getchar();
		buffer[++num_chars] = letter;
	}
	return num_chars;
}

int index_buffer_by_array(const char buffer[], int index[][2], int w_counts[] ) {
    int buf_index = 0, word_beg = 0, word_end = 0, count = 0, i=0;

    for (i = 0; i < WORD_LIMIT; i++) {
        index[i][WD_BGN] = NOT_FOUND;
        index[i][WD_END] = NOT_FOUND;
        w_counts[i] = 0;
    }

    while (buffer[buf_index] != '\0') {
        // Skip over any non-alphabetic characters
        while (isspace(buffer[buf_index])) {
            buf_index++;
        }

        // when its not a space mark that as the begining of the word
        word_beg = buf_index;

        // if its not whitespace and the buffer is not a space or null incresae the index to find the end of the word
        while (buffer[buf_index] != '\0' && !isspace(buffer[buf_index])) {
            buf_index++;
        }

        // the previous loop will stop at the end of the word so index will be the end of the word
        word_end = buf_index;

        // see if the word has already been indexed by a different function
        int index_num = find_word_by_array(word_beg, buffer, index);

        if (index_num == NOT_FOUND) {
            // if the word is not found add it to the index by incrementing the count giving it a new spot
            index_num = count++;
            index[index_num][WD_BGN] = word_beg;
            index[index_num][WD_END] = word_end;
        }

        // Increment number of times word has been seen
        w_counts[index_num]++;
    }
    return count;
}

int find_word_by_array(int word_beg, const char buf[], int index[][2]) {
    int i=0, j=0;
    for (i = 0; i < BUFFER_SIZE ; i++) {
        // Check if word is already indexed
        if (index[i][0] == NOT_FOUND) {
            break; // Stop searching if the index array is not fully initialized yet
        }
        
        for (j = 0;  j < WORD_LIMIT; j++) {
            // Convert characters to lower case for comparison if they aren't the same break else return i
            if (tolower(buf[word_beg] != tolower(buf[index[i][WD_BGN+j]]))) {
                break;
            }
            else{
                return i;
            }
        }
        
    }
    return NOT_FOUND;  //if there is no word found
}

void print_report_by_array(const char buf[], int index[][2], int counts[], int word_cnt) {
    for (int i = 0; i < word_cnt; i++) {
        printf("%2d(%2d): %2d %.*s\n", i, index[i][WD_BGN], counts[i],
               index[i][WD_END] - index[i][WD_BGN], &buf[index[i][WD_BGN]]);
    }
}

// pointer
/*
int index_buffer_by_ptr(const char * buf, const char * index[][2], int word_counts[] ){
    int * buf_index = 0, * word_begin = 0, * word_ends = 0, count = 0, i=0;

    for (i = 0; i < WORD_LIMIT; i++) {
        index[i][WD_BGN] = NOT_FOUND;
        index[i][WD_END] = NOT_FOUND;
        word_counts[i] = 0;
    }

    while (* buf != '\0') {
        // Skip over any non-alphabetic characters
        while (isspace(* buf)) {
            buf++;
        }

        // when its not a space mark that as the begining of the word
        word_begin = buf;

        // if its not whitespace and the buffer is not a space or null incresae the index to find the end of the word
        while (* buf != '\0' && !isspace(* buf)) {
            buf++;
        }

        // the previous loop will stop at the end of the word so index will be the end of the word
        word_ends = buf;

        // see if the word has already been indexed by a different function
        int index_num = find_word_by_ptr(word_begin, index);

        if (index_num == NOT_FOUND) {
            // if the word is not found add it to the index by incrementing the count giving it a new spot
            index_num = count++;
            index[index_num][0] = word_begin;
            index[index_num][1] = word_ends;
        }

        // Increment number of times word has been seen
        word_counts[index_num]++;
    }
    return count;
}

int find_word_by_ptr(const char * beg, const char * index[][2]) {
    int i, j;

    for (i = 0; i < BUFFER_SIZE ; i++) {
        // Check if word is already indexed
        if (index[i][0] == NOT_FOUND) {
            break; // Stop searching if the index array is not fully initialized yet
        }

        for (j = 0; j < WORD_LIMIT; j++) {
            // Convert characters to lower case for comparison
            if (tolower(*(beg + index[i][0] + j)) != tolower(*(beg + index[i][1] + j))) {
                break;
            }

            if (*(beg + index[i][0] + j) == '\0' || *(beg + index[i][1] + j) == '\0') {
                // End of word found in either the buffer or the indexed word
                return i;
            }
        }
    }
    return NOT_FOUND; // the word isn't found
}

void print_report_by_ptr(const char * buf, const char * index[][2], int counts[], int word_cnt){
    for (int i = 0; i < word_cnt; i++) {
        printf("%2d(%2d): %2d %.*s\n", i, index[i][WD_BGN], counts[i],
               (int)(index[i][WD_END] - index[i][WD_BGN]), &buf[index[i][WD_BGN]]);
    }
}
*/