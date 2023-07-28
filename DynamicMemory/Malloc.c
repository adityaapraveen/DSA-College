#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("memory not available");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\\nEnter the integers: ");
        scanf("%d", ptr + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nThe memory alloted is %d", ptr + i);
        printf("\nThe integer is %p", *(ptr + i));
    }
}