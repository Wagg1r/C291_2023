// Program to demonstrate breaking up a program into multiple files.
// Programmer: Kurt Seiffert

#include <stdio.h>

void myFunc(void);       // function prototype

int a = 1, b = 2;

int main(void) {

    printf("Context: Main initially Values a %d b: %d\n", a, b);
    myFunc();
    printf("Context: Main after calling myFunc Values a: %d b: %d\n", a, b);

    return 0;
}

void myFunc(void) {
    int b = 4;

    printf("Context: myFunc  value a: %d b: %d\n", a += b, b);
    return;
}