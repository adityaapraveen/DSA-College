#include <stdio.h>
#pragma pack(1)


struct mymarks
{
    float IA1; // Occupies 4 bytes
    char a;    // Occupies 1 byte
    int x;     // Occupies 4 bytes
    double d;  // Occupies 8 bytes
    char subject[15];
}; // structure only declared. No memory allocated

int main()
{
    struct mymarks m1; // memory allocated for the structure called 'mymarks'

    // Should take only 32 Bytes. Prints 40 in certain platforms. WHY??
    printf("\n Size of my structure is %d", sizeof(m1));
    printf("\n Size of my structure - subject is %d", sizeof(m1.subject));
    printf("\n Size of my structure - IA1 is %d", sizeof(m1.IA1));
    printf("\n Size of my structure - d is %d", sizeof(m1.d));
    printf("\n Size of my structure - a is %d", sizeof(m1.a));
    printf("\n Size of my structure - x is %d", sizeof(m1.x));
}