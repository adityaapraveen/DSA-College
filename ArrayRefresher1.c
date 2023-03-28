#include <stdio.h>

int main()
{
    char name[20];
    int numbers[5];
    int i;

    // Prompt user for their name
    printf("Please enter your name: ");
    scanf("%s", name);

    // Prompt user for five numbers
    printf("Please enter five numbers:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // Print out the user's name and the five numbers
    printf("Your name is: %s\n", name);
    printf("The five numbers you entered are: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
