// Program description
// Author:

/*****************************************************************************
 * 
 * Psuedocode here:
 * 
*****************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include "string_index.h"


int main(void) {
    // variable declartaions 



    // initialize storage


    /* ***** DO NOT CHANGE ANY CODE BEYOND THIS POINT IN main() ****** */
    initialize_buffer(buffer);

    words_found = index_buffer_by_ptr(buffer, word_index, word_counts);

    print_report_by_ptr(buffer, word_index, word_counts, words_found);

    words_found = index_buffer_by_array(buffer, word_index_array, word_counts);

    print_report_by_array(buffer, word_index_array, word_counts, words_found);
    
} // end main

/* ***** YOUR FUNNCTION DEFINTIONS BELOW ***** */

