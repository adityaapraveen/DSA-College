#include <stdio.h>

int main()
{
    int num = 1234;
    char str[] = "Hello, world!";

    printf("The length of the integer is: %lu bytes\n", sizeof(num));
    printf("The length of the character array is: %lu bytes\n", sizeof(str));

    return 0;
}
