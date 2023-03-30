#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    int nums[] = {1, 2, 3, 4, 5};

    nums[2] = 6;

    printf("Elements of the array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int arr[MAX_SIZE];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

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

    char names[][20] = {"John", "Jane", "Jim"};

    printf("The second name is: %s\n", names[1]);

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
