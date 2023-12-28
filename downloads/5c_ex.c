#include <stdio.h>

int main() {
    char ch;
    printf("input a char: ");
    scanf("%c", &ch);
    if (ch == 'a') {
        printf("You pressed 'a'\n");
    }
    return 0;
}