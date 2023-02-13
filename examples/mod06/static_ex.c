// demo use of static keyword

#include <stdio.h>

int count_calls(int a);

int main(void) {

    int a = 1;
    int count = 0;

    for (int i = 0; i < 5; i++) {
        count = count_calls(a);
        printf("[MAIN] main count: %d\n", count);
    }

}

int count_calls(int a) {
    static int func_count = 1;
    printf("\t[count_calls] count = %d\n", func_count);
    return func_count++;
}