// Program description: using arrays and pointers tell how many words are repeated
// Author: Thomas Waggoner

/*****************************************************************************
 * 
 * Psuedocode here:
 * 
*****************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "string_index.h"


int main(void) {
    // variable declartaions 
int words_found;                 // to store the total number of unique words found
char buffer[BUFFER_SIZE];        // to store the input character buffer
char word_index[WORD_LIMIT][2];   // to store the beginning and end of each word found using pointers
int word_counts[WORD_LIMIT];     // to store the count of each unique word found using pointers
int word_index_array[WORD_LIMIT][2]; // to store the beginning and end of each word



    // initialize storage


    /* ***** DO NOT CHANGE ANY CODE BEYOND THIS POINT IN main() ****** */
    initialize_buffer(buffer);

    //words_found = index_buffer_by_ptr(buffer, word_index, word_counts);

    //print_report_by_ptr(buffer, word_index, word_counts, words_found);

    words_found = index_buffer_by_array(buffer, word_index_array, word_counts);

   print_report_by_array(buffer, word_index_array, word_counts, words_found);
    
} // end main

/* ***** YOUR FUNNCTION DEFINTIONS BELOW ***** */

