/* This modification will prompt the user to enter the array size first and then take inputs
for all the elements of the array.*/
int main()
#include <stdio.h>
{
    int arr[5];
    int size;

    printf("\nEnter the size of the array:");
    scanf("%d", &size);

    printf("\nEnter %d numbers:\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nElements of the array are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*This modification will take inputs for all the elements of the array and then
print out the sum of the even and odd elements of the array separately.*/

#include <stdio.h>
int main()
{
    int arr[5];
    int sum_even = 0, sum_odd = 0;

    printf("\nEnter 5 numbers:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
        {
            sum_even += arr[i];
        }
        else
        {
            sum_odd += arr[i];
        }
    }

    printf("\nElements of the array are: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nSum of even elements of the array: %d", sum_even);
    printf("\nSum of odd elements of the array: %d", sum_odd);

    return 0;
}
