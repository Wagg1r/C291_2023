// demo use of const with array

#include <stdio.h>

void copy_array(const int a1[], int a2[]);

int main(void) {
    int array1[] = { 1, 2, 3, 4, 5};
    int array2[5];

    puts("Contents of array2 before copy:");
        for (int i = 0; i < 5; i++) {
        printf("%d ", array2[i]);
    }
    puts("");

    copy_array(array1, array2);
    puts("Contents of array2:");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array2[i]);
    }
    puts("");
}

void copy_array(const int a1[], int a2[]) {
    for (int i = 0; i < 5; i++) {
        a2[i] = a1[i];
    }
    // for (int i = 0; i < 5; i++) {
    //     a1[i] = a2[i];
    // }
}