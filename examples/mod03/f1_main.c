/* 
    Main entry point for f1.
    C291 (Fall 2021)
    Programmer: Kurt Seiffert
*/

#include <stdio.h>
#include "f1.h"

int a = 1, b = 2;

int main(void) {

    printf("Context: Main initially Values a: %d b: %d\n", a, b);
    myFunc();
    printf("Context: Main after calling myFunc Values a: %d b: %d \n", a, b);

    return 0;

}