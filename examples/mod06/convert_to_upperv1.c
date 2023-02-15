// demo non-constant pointer to non-constant data

#include <stdio.h>
#include <ctype.h>

// prototypes
void convertToUppercase(char *sPtr);
void printCharacters(const char *sPtr);

int main(void) {
    char string[] = "cHaRaCtErS and $32.98";

    // case of non-constant pointer to non-constant data
    printf("[MAIN] The string before conversion: %s\n", string);
    convertToUppercase(string);
    printf("[MAIN]The string after the conversion: %s\n", string);

    // case of non-constant pointer to constant data
    printCharacters(string);
    puts("");

    // case of constant pointer to non-constant data
    int x; 
    int y;

    int * const ptr = &x;
    *ptr = 7;       // data referenced is not constant
    // ptr = &y;    // compilation error -- ptr itself is constant

    // case of constant pointer to constant data
    // good for passing array that only uses array index and no 
    // need to modify data
    const int * const cPtr = &x;
    printf("%d\n", *ptr);
    // *cPtr = 10;   // error: ptr is to constant data
    // cPtr = &y;    // error: ptr itself is constant
}

void convertToUppercase(char *sPtr) {
    while (*sPtr != '\0') {
        *sPtr = toupper(*sPtr);
        ++sPtr;     // increment the pointer to point to the next char
    }
}

/*
    printCharacters:

    By declaring the passed pointer to a const value ensures the 
    function cannot alter the referenced string.
*/
void printCharacters(const char * sPtr) {
    // *sPtr = 'A';     // causes a compilation error

    for (; *sPtr != '\0'; ++sPtr) {
        putchar(*sPtr);
    }
}