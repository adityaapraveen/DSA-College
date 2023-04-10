#include <stdio.h>
int main()
{
    char *pc;
    int *pi;
    float *pf;
    double *pd;

    printf("\n Size of character pointer is %d", sizeof(pc));
    printf("\n Size of int pointer is %d", sizeof(pi));
    printf("\n Size of float pointer is %d", sizeof(pf));
    printf("\n Size of double pointer is %d", sizeof(pd));

    char carr[10];
    int iarr[10];
    float farr[10];
    double darr[10];

    pc = carr;
    printf("\n \n Size of character array pointer is %d", sizeof(pc));
    printf("\n Size of one character in this machine is %d", sizeof(char));
    printf("\n Size of character array carr is %d", sizeof(carr));

    pi = iarr;
    printf("\n \n Size of character array pointer is %d", sizeof(pi));
    printf("\n Size of one character in this machine is %d", sizeof(int));
    printf("\n Size of character array carr is %d", sizeof(iarr));

    pf = farr;
    printf("\n \n Size of character array pointer is %d", sizeof(pf));
    printf("\n Size of one character in this machine is %d", sizeof(float));
    printf("\n Size of character array carr is %d", sizeof(farr));

    pd = darr;
    printf("\n \n Size of character array pointer is %d", sizeof(pd));
    printf("\n Size of one character in this machine is %d", sizeof(double));
    printf("\n Size of character array carr is %d", sizeof(darr));

    int s;
    printf("\n Enter the size of the array");
    scanf("%d", &s);
    int array[s];
    printf("\n %d is the size of my array", sizeof(array));
}