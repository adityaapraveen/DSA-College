#include <stdio.h>

int main()
{
    char game[10];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the name of the game:");
        scanf("%s", &game[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%c", game[i]);
    }
}
