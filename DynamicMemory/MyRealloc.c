/*
@Author : Dr.Mydhili K Nair, Professor and Head B.Tech(H), SoCSE, RVU
Modified by Dr. Shobana
Expected behavious of realloc is to reallocate the memory that was previously occupied by a pointer allocated dynamically.
NOTE: Realloc FAILS if it tries to reallocate memory for a location that was previously statically allocated.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_elems;

    printf("\nHow many elements do you want to enter? ");
    scanf("%d", &num_elems);
    printf("\n\n******************First Malloc **************************************");
    // If malloc is not able to allot - you will get a segmentation fault
    int *imallocarray1 = (int *)malloc(num_elems * sizeof(int));

    if (imallocarray1 == NULL)
    {
        printf("\n%d bytes could not be allotted by the first malloc", num_elems * sizeof(int));
    }
    else
    {
        printf("\n%d bytes allotted", num_elems * sizeof(int));
    }

    // for (int i = 0; i < num_elems; i++) imallocarray1[i] = 2*i;
    for (int i = 0; i < num_elems; i++)
    {
        printf("\n%d is the %dth element at address %p", imallocarray1[i], i, &imallocarray1[i]);
    }

    printf("\n\n*******************Second Malloc***********************************");

    int *imallocarray2 = (int *)malloc(num_elems * sizeof(int));
    if (imallocarray2 == NULL)
    {
        printf("\n%d bytes could not be allotted by the second malloc", num_elems);
    }
    else
    {
        printf("\n%d bytes allotted", num_elems * sizeof(int));
    }

    // for (int i = 0; i < num_elems; i++) imallocarray2[i] = 3*i;
    for (int i = 0; i < num_elems; i++)
    {
        printf("\n%d is the %dth element at address %p", imallocarray2[i], i, &imallocarray2[i]);
    }

    printf("\n\n************************Realloc Usage******************************");
    printf("\nReallocating using the first malloc pointer");

    int *ireallocarray2 = (int *)realloc(imallocarray1, sizeof(int) * 2 * num_elems);

    if (ireallocarray2 == NULL)
    {
        printf("\n\n%d bytes could not be allotted by realloc", sizeof(int) * 2 * num_elems);
    }
    else
    {
        printf("\n%d bytes allotted", 2 * num_elems * sizeof(int));
    }

    for (int i = 0; i < 2 * num_elems; i++)
    {
        printf("\n%d is the %dth element at address %p", ireallocarray2[i], i, &ireallocarray2[i]);
    }

    // printf("\n\n***Reallocating using compile time array pointer- FAIL Case - ABORTED CORE DUMP RunTime Error**");
    // printf("\n\n****REALLOC - FAIL Case - *********************");
    //  do the code here
    int arr[10];
    int *arr1 = (int *)realloc(arr, sizeof(int) * 2 * num_elems);
    if (arr1 == NULL)
    {
        printf("\n\n%d bytes could not be allotted by realloc", sizeof(int) * 2 * num_elems);
    }
    else
    {
        printf("\n%d bytes allotted", 2 * num_elems * sizeof(int));
    }
}

/*
output
How many elements do you want to enter? 6

******************First Malloc **************************************
24 bytes allotted
12981472 is the 0th element at address 00C616F0
12976320 is the 1th element at address 00C616F4
12981912 is the 2th element at address 00C616F8
1549890657 is the 3th element at address 00C616FC
637534246 is the 4th element at address 00C61700
4295 is the 5th element at address 00C61704

*******************Second Malloc***********************************
24 bytes allotted
12981472 is the 0th element at address 00C61710
12976320 is the 1th element at address 00C61714
1163020371 is the 2th element at address 00C61718
830357849 is the 3th element at address 00C6171C
1886404956 is the 4th element at address 00C61720
1635017028 is the 5th element at address 00C61724

************************Realloc Usage******************************
Reallocating using the first malloc pointer
48 bytes allotted
12981472 is the 0th element at address 00C61730
12976320 is the 1th element at address 00C61734
12981912 is the 2th element at address 00C61738
1549890657 is the 3th element at address 00C6173C
637534246 is the 4th element at address 00C61740
4295 is the 5th element at address 00C61744
1512917075 is the 6th element at address 00C61748
1426083909 is the 7th element at address 00C6174C
1146242387 is the 8th element at address 00C61750
1229016399 is the 9th element at address 00C61754
1330798414 is the 10th element at address 00C61758
1313426753 is the 11th element at address 00C6175C


48 bytes could not be allotted by realloc
*/