// demo multi-dim arrays

#include <stdio.h>

// prototypes
void print_array(int arr[][3]);

int main(void) {

    int array1[2][3] = { {1,2,3}, {4,5,6}};
    puts("Values for array 1 by row are:");
    print_array(array1);

    int array2[2][3] = {1, 2, 3, 4, 5};
    puts("Values for array2 by row:");
    print_array(array2);

    int array3[2][3] = {{1,2}, {4}};
    puts("Values for array3 by row:");
    print_array(array3);

    char string1[3][6] = {"One", "toolon", "three"};
    for (int i = 0; i < 3; i++) {
        printf("String[%d] : %s\n", i, string1[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("string[%d] : ", i );
        for (int j = 0; j < 6; j++) {
            if (string1[i][j] == '\0') {
                printf("\n");
                break;
            } else {
                printf("%c", string1[i][j]);
            }
        }
        printf("  end loop\n");
    }
}

    



void print_array(int arr[][3]) {
    // loop thru rows
    for (int i = 0; i < 2; i++) {

        // loop thru cols
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}