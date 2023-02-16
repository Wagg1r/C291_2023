#include <stdio.h>

int main(void) {
    int count;

    int *countPtr;

    char string[] = "Hello";


    printf("string location: %p string value:%s\n", string, string );

    for (int i = 0; i < sizeof(string); i++) {
       printf("string[%d]: %c address of: %p\n", i, string[i],&string[i]);
    }
}
