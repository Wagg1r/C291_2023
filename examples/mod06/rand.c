// simple demo of rand() function

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t cur_time;

int main(void) {
    puts("Call rand with seed 1:");
    srand(1);
    for (int i = 0; i < 5; i++) {
        printf("Trial%d: %d\n", i, rand() % 10);
    }
    puts("");

    puts("Call rand with seed 2:");
    srand(2);
    for (int i = 0; i < 5; i++) {
        printf("Trial%d: %d\n", i, rand() % 10);
    }
    puts("");

    puts("Call rand with seed 1:");
    srand(1);
    for (int i = 0; i < 5; i++) {
        printf("Trial%d: %d\n", i, rand() % 10);
    }
    puts("");

    time(&cur_time);
    printf("Call rand with seed %zu\n", cur_time);
    srand(cur_time);
    for (int i = 0; i < 5; i++) {
        printf("Trial%d: %d\n", i, rand() % 10);
    }
    puts("");
}