// demontstrate qsort for numbers
// Author: Kurt Seiffert

/*
    qsort_ph_nbrs:

    This program demonstrates using an array to store the beginning of each 
    phone number in a character buffer that is filled form stdin. That is the array
    is an index of the beginning of each phone number in the array. All values stored
    in the index array are postive integers that are the indexes to the char array. 

    The index array is sorted using an implementation of qsort. The qsort uses
    a helper function that can compare two phone numbers. 

    The sorted index is used to print out each phone number resulting in the phone
    numbers being printed in the ascending order.

    The original character buffer is never altered.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define BUF_SIZE 1024       // max length of the character buffer
#define PH_LEN 12           // max length of a phone number
#define INDEX_SZ BUF_SIZE / PH_LEN + 1   // Number of phone numbers that fit in buffer

void qsort(char c_buf[], int array[], int low, int high);
int partition_idx(char c_buf[], int arr[], int low, int high);
int comp_ph_nbrs(char c_buf[], int ph1_idx, int ph2_idx);

int load_buffer(char arr[]);
int index_nmbrs(char char_buf[], int buf_idx[]);



/*
    main:

    Driver for the program setups the char buf and index array and loads the buffer from
    stdin. Then it indexes the buffer and finally prints the buffer contents in the order 
    of the sorted index.
*/
int main(void) {
    //  need to force this setup since debuger will not redirect stdin
    char char_buf[BUF_SIZE] = "455-688-1398\n186-663-6344\n807-561-9851\n081-315-1057\n379-208-3901\n";
    int char_cnt = 65;
    
    int buf_idx[INDEX_SZ];

    // initialize the phone number index with a value not used to index our array
    for (int i = 0; i < INDEX_SZ; i++ )
        buf_idx[i] = -1;

    char_cnt = load_buffer(char_buf);

    int idx_cnt = index_nmbrs(char_buf, buf_idx);
    // printf("index count: %d\n", idx_cnt);

    qsort(char_buf, buf_idx, 0, idx_cnt - 1);

    // print out the phone numbers by the sorted index
    for(int i = 0; i < idx_cnt; i++){
        printf("%d: %d ", i, buf_idx[i]);
        for(int j = buf_idx[i]; j < (PH_LEN + buf_idx[i]); j++) {
            putchar(char_buf[j]);
        }
        puts("");
    }

}

/*
    index_nmbrs:

    Fills the provided array with the index in c_buf of the first digit of
    each phone number in c_buf. Phone numbers are considered any sequence of 
    digits and '-' characters. 
*/
int index_nmbrs(char c_buf[], int buf_idx[]) {
    int cur_char = 0;
    int ph_count = 0;
    bool in_num_f = false;  // flag to indicate if currently in ph nmbr
    while (cur_char < BUF_SIZE) {
        if (isdigit(c_buf[cur_char]) || c_buf[cur_char] == '-') {
            if (in_num_f) {
                cur_char++;
            } else {
                // just found the first digit of a phone number
                // store it in the index, increment our ph_count,
                // move to the next character, and set our in nmbr flag
                buf_idx[ph_count++] = cur_char++;
                in_num_f = true;
            }
        } else {
            // cur_char is not a part of a ph nmbr so set our flag
            // to false and move on to the next char
            in_num_f = false;
            cur_char++;
        }
    }
    return ph_count;
}

/*
    load_buffer:

    Loads the given char array with characters from stdin.
    It reads a maximum of BUF_SIZE. If stdin does not fill the array
    the rest of the array is initialized to '\n'. 
*/
int load_buffer(char arr[]) {
    char c;
    int char_cnt = 0;

    // standard idiom to get each character until EOF or buffer filled.
    while ((c = getchar()) != EOF && char_cnt < BUF_SIZE) { 
         arr[char_cnt++] = c;
    }

    // padd the rest of the buffer with \n 
    for (int j = char_cnt; j < BUF_SIZE; j++) {
        arr[j] = '\n';
    }
    
    return char_cnt;
}

/*
    qsort:

    Sorts the given index array by the ph numbers stored in c_buf using 
    the paritiion_idx(). Calls the paritiion_idx() to divide the array and 
    then recursively calls itself on each leftside of the array and then
    the right side.
*/
void qsort(char c_buf[], int arr[], int lo, int hi) {
    if (lo >= hi || lo < 0)
        return;     // sanity check that indexes are in proper order

    int partition = partition_idx(c_buf, arr, lo, hi);
    // printf("partition: %2d lo:%2d hi:%2d\n", partition, lo, hi);

    qsort(c_buf, arr, lo, partition - 1);  // partition to the left
    qsort(c_buf, arr, partition + 1, hi);
}

/*
    partition_idx:

    Takes an array of indexes to ph nmbrs in c_buf as well as the range of the
    index to be sorted (lo and hi). 

    This uses the arr[hi] as the partitioning value. It then finds the position
    in the array where all values to the left are less than arr[hi] and all 
    values to theright are larger than arr[i]. It then puts arr[i] in that 
    position and returns the position. 
*/
int partition_idx(char c_buf[], int arr[], int lo, int hi) {
    // grab the last value and parition the array around this value
    int pivot_value = arr[hi];    

    // temp_pivot_idx points to the last value seen lower than pivot_value
    int tmp_pivot_idx = lo - 1;

    // since tmp_pivot_idx points to the last value lower than our pivot_value
    // if we find another value lower, we increment tmp_pivot_idx (which has to point
    // to the first value larger than the pivot_value) and swap the new value 'low'
    // value and the first value larger than the 
    for (int j = lo; j < hi - 1; j++) {
        if (comp_ph_nbrs(c_buf, arr[j], pivot_value) < 0) {
            tmp_pivot_idx++;  
            // swap the current point and the last tmp_pivot_idx
            int tmp = arr[tmp_pivot_idx];
            arr[tmp_pivot_idx] = arr[j];
            arr[j] = tmp;
        }
    }

    // after we have compared all the values in the array to the arr[hi]
    // tmp_pivot_idx points to the last value smaller than arr[hi] 
    // so we increment the tmp_pivot_idx to the first value not smaller and 
    // swap that with arr[hi] leaving arr[hi] in the 'middle' of the array
    tmp_pivot_idx++;
    int tmp = arr[tmp_pivot_idx];
    arr[tmp_pivot_idx] = arr[hi];
    arr[hi] = tmp;
    return tmp_pivot_idx;
}

/*
    comp_ph_nubrs:

    Compares two phone numbers starting at locations c_buf[ph1] and c_buf[ph2] by
    comparing each corresponding character in the two phone numbers.

    If all characters are the same return 0. Return -1 if ph1 encounters a char 
    smaller than the corresponding ph2, and +1 if ph1 encounters a char larger
    than the corresponding character in ph2.
*/
int comp_ph_nbrs(char c_buf[], int ph1, int ph2) {
    for (int i = 0; i < PH_LEN; i++) {
        if (c_buf[ph1 + i] < c_buf[ph2+i]) 
            return -1;
        else if (c_buf[ph1 + i] > c_buf[ph2 + i])
            return 1;
        else 
            return 0;
    }
}
