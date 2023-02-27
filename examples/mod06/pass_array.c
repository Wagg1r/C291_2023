// Demo of passing by value and reference
// Author: Kurt A. Seiffert

#include <stdio.h>

// Function prototypes
void print_array(int array[], int a_size);
void incr_array(int array[], int a_size);
void incr_a_by_val(int val);
void incr_a_by_ref(int * val);
int ret_incr_a(int val);

#define SIZE 5

/*
    main:

    Entry point for program. Demos incrementing an integer variable with
    a call by value and then by reference.

    Call array by reference.
*/
int main(void) {
    int a = 10;

    printf("[MAIN] Value of a beginning main: %d\n", a);

    incr_a_by_val(a);

    printf("[MAIN] Value of a after incr_a_by_value: %d\n\n", a);

    incr_a_by_ref(&a);

    printf("[MAIN] Value of a after incr_a_by_ref: %d\n\n", a);

    printf("[MAiN] Value of a BEFORE ret_incr_a: %d\n", a);
    a = ret_incr_a(a);
    printf("[MAIN] Value of a AFTER ret_incr_a: %d\n\n", a);

    int arr[SIZE] = {1,2,3,4,5};
    printf("Size of arr is: %zu\n", sizeof(arr));

    puts("[MAIN] Print arr values BEFORE incr_arr():");
    for (int i = 0; i < SIZE; i++) {
        printf("[MAIN]\tarray[%d] = %d &array[%d] = %p\n", i, arr[i], i, &arr[i]);
    }
    puts("[MAIN] Print arr values in function (call by reference)");
    print_array(arr, SIZE);
    incr_array(arr, SIZE);
    puts("[MAIN] Print arr values AFTER incr_arr():");
    for (int i = 0; i < SIZE; i++) {
        printf("[MAIN]\tarray[%d] = %d &array[%d] = %p\n", i, arr[i], i, &arr[i]);
    }


} // end main

/*
    incr_a_by_val:

    Shows value entering function and after incrementing val.
*/
void incr_a_by_val(int val) {
    printf("\t[incr_a_by_val]Value of a passed to incr_a_by_val: %d\n", val);
    val += 1;
    printf("\t[incr_a_by_val]Value of after incrementing in incr_a_by_val: %d\n", val);
}

/*
    incr_a_by_ref:

    Shows value entering function and after incrementing val.
*/
void incr_a_by_ref(int * val) {
    printf("\t[incr_a_by_ref]Value of a passed to incr_a_by_ref: %d\n", *val);
    *val += 1;
    printf("\t[incr_a_by_ref]Value of a in incr_a_by_ref after incrementing: %d\n", *val);
}

/*
    ret_incr_a:

    Shows value entering function, after incrementing, and what is returned.
*/
int ret_incr_a(int val) {
    printf("\t[ret_incr_a]Value of a passed to ret_incr_a: %d\n", val);
    val += 1;
    printf("\t[ret_incr_a]Value of a in ret_incr_a after incrementing: %d\n", val);
    return val;
}

/*
    print_array:

    Prints each value of passed array along with address of array index.
*/
void print_array(int array[], int a_size) {
    for (int i = 0; i < a_size; i++) {
        printf("\t[print_array]\tarray[%d] = %d &array[%d] = %p\n", i, array[i], i, &array[i]);
    }
} // end print_array

/*
    incr_array;

    Increments each element of array by multiplying by 10.
*/
void incr_array(int array[], int a_size) {
    puts("\t[incr_array] array BEFORE incrementing.");
    for (int i = 0; i < a_size; i++) {
        printf("\t[incr_array]\tarray[%d] = %d &array[%d] = %p\n", i, array[i], i, &array[i]);
    }
    for (int i = 0; i < a_size; i++) {
        array[i] *= 10;
    }
    puts("\t[incr_array] array AFTER incrementing.");
    for (int i = 0; i < a_size; i++) {
        printf("\t[incr_array]\tarray[%d] = %d &array[%d] = %p\n", i, array[i], i, &array[i]);
    }
} // end incr_array