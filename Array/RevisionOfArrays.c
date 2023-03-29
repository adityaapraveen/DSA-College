#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    // Declaring and initializing a one-dimensional array of integers
    int nums[] = {1, 2, 3, 4, 5};

    // Changing the value of an array element
    nums[2] = 6;

    // Printing all elements of the array using a loop
    printf("Elements of the array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Inputting values for the array using a loop
    int arr[MAX_SIZE];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Printing all elements of the array using a loop
    printf("Elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Searching for an element in the array
    int search_num;
    printf("Enter a number to search in the array: ");
    scanf("%d", &search_num);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search_num)
        {
            printf("Number found at index %d\n", i);
            break;
        }
    }

    // Declaring and initializing a two-dimensional array of characters
    char names[][20] = {"John", "Jane", "Jim"};

    // Accessing and printing a single element of the array
    printf("The second name is: %s\n", names[1]);

    // Declaring and initializing an array of strings
    char strs[3][MAX_SIZE];
    printf("Enter three strings: ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", strs[i]);
    }
    printf("The entered strings are:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", strs[i]);
    }

    return 0;
}
