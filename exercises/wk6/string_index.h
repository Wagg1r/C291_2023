#ifndef STRING_INDEX_HEADER
#define STRING_INDEX_HEADER

#define BUFFER_SIZE 2048
#define WORD_LIMIT 100
#define NOT_FOUND -1
#define WD_BGN  0
#define WD_END  1

// Prototypes

/*
    initialize_buffer:
    Fills the given array with characters from stdin until either EOF or 
    2048 characters have been loaded.
    Returns the total number of characters loaded and -1 if no characters loaded.
*/
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


/********************************************************
  Functions that work with arrays
********************************************************/

/*
    index_buffer_by_array:
    Indexes the beginning and end of each unique word (string of non-whitespace characters). 
    The index is a list of beginning and ending array indexes for each unique word found.
    Duplicate words are counted in w_counts array. 
    Returns the total number of unique words found in the character buffer.
*/

int index_buffer_by_array(const char buffer[], int index[][2], int w_counts[] ){
    int buffer_index = 0;
    int index_count = 0;
    int word_length = 0;
    bool in_word = false; // tells me if i am in a word    
    int word_start = NOT_FOUND;
    
    // loop through buffer and index each word
    while (index_count < BUFFER_SIZE-1 && buffer[index_count] != '\0') {
        if (isalpha(buffer[index_count])) {
            if (!in_word) {
                // start of new word
                in_word = true;
                word_start = index_count;
            }
            word_length++;
        } else  if (in_word){
                // end of word
                in_word = false;
                // check if word already exists in index array
                bool found = false;
                for (int i = 0; i < buffer_index; i++) {
                    //if (strncmp((buffer+word_start), (buffer+index[i][WD_BGN]), word_length) == 0) {
                    if (strncasecmp((buffer+word_start), (buffer+index[i][WD_BGN]), word_length) == 0) {
                        // word already exists so you increment w_count
                        w_counts[i]++;
                        found = true;
                        break;
                    }
                }
                // if its a new word make a new entry
                if (!found) {
                    index[buffer_index][WD_BGN] = word_start;
                    index[buffer_index][WD_END] = index_count - 1;
                    w_counts[buffer_index] = 1;
                    buffer_index++;
                }
                word_length = 0;
            
        }
        index_count++;
    }
    return buffer_index;
    

}

/*
    find_word_by_array:
    Determines if the word in buf[] beginning at index word_beg is already indexed. 
    A word terminates with the first whitespace character.
    Returns the index number for the word if found, otherwise returns NOT_FOUND.
*/
int find_word_by_array(int word_beg, const char buf[], int index[][2]){
    int word_freq = 0;
    for (int i = 0; i < WORD_LIMIT && buf[i] != '\0'; i++) {
        //the start of the word
        if (buf[i+1] == '\0' || isspace(buf[i+1])) {
            index[i][WD_END] = i;
            word_freq++;
            word_beg = NOT_FOUND;
        } else if (word_beg == NOT_FOUND) {
                // start of new word
                word_beg = i;
                index[i][WD_BGN] = word_beg;
        // the end of a word will be null or empty space so check that and save it
        }
    }
// sanity check to see whats     
//for (int i = 0; i < WORD_LIMIT; i++) {
//     printf("%d %d\n", index[i][0], index[i][1]);
// }
    return word_freq;
}//ends function

/*
    print_report_by_array:
    Prints to stdout a report giving the word index number, offset of first letter from
    beginning of the buffer, the word count, and the word itself. This function expects index
    to be an array of array indexes for the beginning and end of each word.
    Example output for buffer containing the characters in quotes "all the all"
    0( 0): 2 all
    1( 4): 1 the
*/
void print_report_by_array(const char buf[], int index[][2], int counts[], int word_cnt) {
    for (int i = 0; i < word_cnt; i++) {
        printf("%d( %d): %d %.*s\n", i, index[i][WD_BGN], counts[i], index[i][WD_END] - index[i][WD_BGN] + 1, buf+index[i][WD_BGN]);
    }
}

/*******************************************************
  Functions that work with pointers
********************************************************/

/*
//     index_buffer_by_ptr:

//     Indexes the beginning and end of each unique word (string of non-whitespace characters). 
//     The index is a list of beginning and ending char pointers for each unique word found.
//     Duplicate words are counted in w_counts array. 

//     Returns the total number of unique words found in the character buffer.
// */
// int index_buffer_by_ptr(const char * buf, const char * index[][2], int word_counts[] );

// int buffer_index = 0;
//     int index_count = 0;
//     int word_length = 0;
//     bool in_word = false; // tells me if i am in a word    
//     int word_start = NOT_FOUND;
    
//     // loop through buffer and index each word
//     while (index_count < BUFFER_SIZE-1 && buffer[index_count] != '\0') {
//         if (isalpha(buffer[index_count])) {
//             if (!in_word) {
//                 // start of new word
//                 in_word = true;
//                 word_start = index_count;
//             }
//             word_length++;
//         } else  if (in_word){
//             // end of word
//             in_word = false;
//             // check if word already exists in index array
//             bool found = false;
//             for (int i = 0; i < buffer_index; i++) {
//                 //if (strncmp((buffer+word_start), (buffer+index[i][WD_BGN]), word_length) == 0) {
//                 if (strncmp((buffer+word_start), (buffer+index[i][WD_BGN]), word_length) == 0) {
//                     // word already exists so you increment w_count
//                     //printf("%s",buffer+index[i][WD_BGN]);
//                     w_counts[i]++;
//                     found = true;
//                     break;
//                 }
//             }
//             // if its a new word make a new entry
//             if (!found) {
//                 (index)[buffer_index][WD_BGN] = word_start;
//                 (*index)[buffer_index][WD_END] = index_count - 1;
//                 w_counts[buffer_index] = 1;
//                 buffer_index++;
//             }
//                 word_length = 0;
            
//         }
//         index_count++;
//     }
//     return buffer_index;
    



// /*
//     find_word_by_ptr:

//     Determines if the word in  beginning at the char * beg  is already indexed. 
//     A word terminates with the first whitespace character.

//     Returns the index number for the word if found, otherwise returns NOT_FOUND.

// */



// int find_word_by_ptr(const char * beg, const char * index[][2]);

// /*
//     print_report_by_ptr:

//     Prints to stdout a report giving the word index number, offset of first letter from
//     beginning of the buffer, the word count, and the word itself. This function expects index
//     to be an array of char pointers for the beginning and end of each word.

//     Example output for buffer containing the characters in quotes "all the all"
//     0( 0): 2 all
//     1( 4): 1 the
// */
// void print_report_by_ptr(const char * buf, const char * index[][2], int counts[], int word_cnt);


#endif
