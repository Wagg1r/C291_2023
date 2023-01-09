/*
    Defiintion of f1.h functions.
    C291 (Fall 2021)
    Programmer: Kurt Seiffert
*/
#include <stdio.h>

extern int a;

void myFunc(void) {
    int b = 4;

    printf("Context: myFunc  value a: %d b: %d\n", a += b, b);
    return;
}
