// demo multi-dim with strings arrays

#include <stdio.h>

int main(void) {


    char string1[3][6] = {"One", "toolon", "three"};
    for (int i = 0; i < 3; i++) {
        printf("String[%d] : %s\n", i, string1[i]);
    }

    puts("");

    for (int i = 0; i < 3; i++) {
        printf("string[%d] : ", i );
        for (int j = 0; j < 6; j++) {
            if (string1[i][j] == '\0') {
                printf("\n");
                break;
            } else {
                putchar(string1[i][j]);
            }
        }
        printf("  end loop\n");
    }
}

    
