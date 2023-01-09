/*
    Examples playing with scanf and printf 
    C291 (Fall 2021)
    Programmer: Kurt Seiffert
*/

#include <stdio.h>

int main(void) {
    char myString1[] = "Hello, Class!";
    char myString2[] = {'H', 'e', 'l', 'l','o', '\0'};

    // printf( "%d\n", 678);
    // printf( "%d\n", -678);

    // printf( "%4d\n", 678);
    // printf( "%4d\n", -678);

    // printf( "%-4d\n", 678);
    // printf( "%-4d\n", -678);

    // printf( "Octal %O\n", 8);
    // printf( "Hex %X\n", 16);
    // printf( "Hex (better) %p\n", 16);

    // printf( "Char %c %u\n", 'Y', 'Y');
    // printf( "Char %c %d\n", 88, 88);

    // printf( "String %s\n", myString1);
    // printf( "String %25s\n", myString1);

    // printf( "String %s\n", myString2);

    // default precision for %f is 6 decimal digits
    // printf( "Floating %f\n", 54321.78901398948376);
    // printf( "Floating %16.7f\n", 54321.78901398948376); //16 positions allocated for number with 7 for decimal
    // printf( "Floating %16.7f\n", 21.78901398948376);
    // printf( "Floating %16.7f\n", 987654321.78901398948376);

    // specify the precision as an argument
    // printf( "Floating %*.*f\n", 16, 4, 21.78901398948376);

    // scientific (Note the rounding)
    printf( "Floating %e\n", 654321.78901398948376);
    printf( "Floating %G\n", 987654321.78901398948376);

}