// demo of pass-by-reference and pass-by-value
// author: Kurt Seiffert

#include <stdio.h>

// prototypes
int cube_by_value(int a);       // cube the integer passed by value
void cube_by_reference(int *a);  // cube the integer passed by reference

int main(void) {
    int a = 10;

    printf("[MAIN] value of a: %d\n", a);
    int result = cube_by_value(a);
    printf("[MAIN] value of a: %d value of result: %d\n\n", a, result);

    cube_by_reference(&a);
    printf("[MAIN] Value of a: %d\n", a);

}

/*
    cube_by_value:

    Takes an integer and returns the cube of the integer.
*/
int cube_by_value(int a) {
    a = a * a * a;
    printf("\t[cube_By_value] value of a: %d\n", a);
    return a;
}

/*
    cube_by_refernce:

    Takes an integer pointer and changes the location to the cube of the integer value
*/
void cube_by_reference(int *a) {
    
    printf("\t[cube_by_reference] Value of ptr: %p Dereferenced value: %d\n", a, *a);
    *a = *a * *a * *a;
    printf("\t[cube_by_reference] Value of ptr: %p, Dereference value: %d\n", a, *a );
}
