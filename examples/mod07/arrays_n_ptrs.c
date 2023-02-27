// demo of relationship between arrays and pointers.
// Author: Kurt A. Seiffert

#include <stdio.h>

#define ARR_SIZE 3

// prototypes
int sum_values_a(int array[], int len);
int sum_values_p(int * buf, int len);

int main(int argc, char * argv[] ) {

    int demo_a[ARR_SIZE] = {4, 5, 6};

    int * int_buffer = demo_a;  //equivalent to &demo_a[0]

    puts("Print numbers by array indexing.");
    // use array indexing to print each number
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("[%d : %p]%2d\n", i, &demo_a[i], demo_a[i]);
    }
    puts("");

    puts("Print numbers using pointer syntax.");
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("[%d : %p]%2d\n", i, demo_a + i, *(demo_a + i));
    }
    puts("");

    // demonstrates that C sum_values_a and sum_values_p are syntactically equivalent
    printf("Sum demo_a using array index: %d\n", sum_values_a(demo_a, ARR_SIZE));
    printf("Sum demo_a using pointers: %d\n", sum_values_p(demo_a, ARR_SIZE));

    // we can also pass a pointer to both functions equally well.
    printf("Sum int_buffer using array index: %d\n", sum_values_a(int_buffer, ARR_SIZE));
    printf("Sum int_buffer using ptrs: %d\n", sum_values_p(int_buffer, ARR_SIZE));
    puts("");

    // two dimensional arrays are a little trickier since the second dimension 
    // represents an internal structure (two integers in our example) for each 
    // entry in the first dimension
    int demo2_a[ARR_SIZE][2] = {{1,2}, {3,4}, {5,6}};

    // note this pointer loses the structure of the array
    int * demo2_ptr = &demo2_a[0][0];

    // prototypes for 2 dimensional array processing
    int sum_prod_a(int array[][2], int len);
    int sum_prod_p(int * buffer, int len);

    // we can pass the 2 dimensional array to each function implementation
    printf("Sum of products by array: %d\n", sum_prod_a(demo2_a, ARR_SIZE));
    // compiler warns you that the types do not match
    printf("Sum of products by ptr: %d\n", sum_prod_p(demo2_a, ARR_SIZE));

    // we can pass the pointer to the buffer to each function
    // compiler warns us that we our types do not match
    printf("Sum of products by array: %d\n", sum_prod_a(demo2_ptr, ARR_SIZE));
    printf("Sum of products by ptr: %d\n", sum_prod_p(demo2_ptr, ARR_SIZE));

    // proper way to declare the pointer to two int values
    int (*demo3_ptr)[2];
    demo3_ptr = &demo2_a[0];

    // now we can call demo2_a passing the pointer
    printf("Sum of products by array sum_prod_a(demo3_ptr): %d\n", sum_prod_a(demo3_ptr, ARR_SIZE));

    // we can define a better version of the sum_prod_p
    int sum_prod_p2(int (*buffer)[2], int len);

    // now we can call sum_prod_p2 passing the 2 dimensional array
    printf("Sum of products by ptr sum_prod_p2(demo2_a)): %d\n", sum_prod_p2(demo2_a, ARR_SIZE));

}

/*
    sum_values_a:

    Return the sum of values in the given array for the length given.
*/
int sum_values_a(int array[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += array[i];
    }
    return sum;
}


/*
    sum_values_p:

    Return the sum of values in given buf for the length given.
*/
int sum_values_p(int * buf, int len ){
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += *(buf + i);
    }
    return sum;
}

/*
    sum_prod_a:

    Takes a 2-dim array and sums the product of int pairs
    using array index syntax.
    Note the function prototype indicates to the programmer
    the expected structure of the data. 
*/
int sum_prod_a(int array[][2], int len) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += array[i][0] * array[i][1];
    }
    return sum;
}

/*
    sum_prod_p:

    Takes a pointer to a int buffer that consists of pairs of integers.
    It returns the sum of the products of each pair.
    Note the function prototype does NOT indicate the structure of the
    buffer. The programmer has to read this documentation or study
    the definition to understand what to send this function.
*/
int sum_prod_p(int * buffer, int len) {
    int sum = 0;
    for(int i = 0; i < len * 2; i += 2) {
        sum += *(buffer + i) * *(buffer + i + 1);
    }

    return sum;
}

/*
    sum_prod_p2:

    Same as sum_prod_p but properly references each element in the buffer 
    as an array of 2 ints. Note this is still a pointer to an integer, so
    our pointer math needs to account for 2 ints in each element.
*/
int sum_prod_p2(int (*buffer)[2], int len) {
    int sum = 0;
    for(int i = 0; i < len * 2; i += 2){
        sum += (*buffer + i)[0] * (*buffer + i)[1];
    }
    return sum;
}