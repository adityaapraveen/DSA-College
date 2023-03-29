#include <stdio.h>
int main()
{
    int size;
    int arr[size];
    printf("\nEnter the size of the array:");
    scanf("%d", &size);
    for (int i = 1; i < 3;i++)
    {
        printf("\nEnter the %d number:", i);
        scanf("%d", &arr[i]);
    }
}