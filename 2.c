#include <stdio.h>

int main() {
    int i, j;
    i = 0;
    j = 10;

    do {
        printf("i = %d, j = %d\n", i, j);
        i++;
        j++;
    } while (i < 6);

    return 0;
}
