// demo using the extern key word

#include <stdio.h>
#include "extern.h"

extern int a;

int main(void) {
    printf("Value of a: %d\n", a);

    demo_func(2, 3);
}


