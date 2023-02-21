// Generate a list of randomly generated phone numbers
// Author: Kurt Seiffert

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OUT_SIZE 4096

int main(void) {
    size_t t;
    time(&t);
    srand(t);

    for(int i = 0; i < OUT_SIZE / 12; ++i) {
        printf("%03d-%03d-%04d\n", 
            rand() % 1000, rand() % 1000, rand() % 10000);
    }

}