// Program to demonstrate functions
// Programmer: Kurt Seiffert
#include <stdio.h>

/*
    Demonstrate how to pass a variable to the function.
*/

void myFunction(void);       // function prototype or declaration

int main(void) {

    printf( "Inside main function.\n" );
    myFunction();
}

void myFunction(void) {
    
    printf("Inside myfunction.\n");

}