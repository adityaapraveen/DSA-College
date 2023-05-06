#include <stdio.h>

struct struct1
{
    char a; // Occupies 1 byte
    int x;  // Occupies 4 bytes
};          // structure only declared. No memory allocated
typedef struct struct1 struct1;

struct struct2
{
    char c2;
    char c1; // Occupies 1 byte
    int x;   // Occupies 4 bytes
};           // structure only declared. No memory allocated
typedef struct struct2 struct2;

struct struct3
{

}; // structure only declared. No memory allocated
typedef struct struct3 struct3;

int main()
{
    struct1 s1; // memory allocated for the structure
    struct2 s2; // memory allocated for the structure
    struct3 s3; // memory allocated for the structure

    printf("\n Size of struct1 is %d", sizeof(s1));
    printf("\n Size of struct2 is %d", sizeof(s2));
    printf("\n Size of struct3 is %d", sizeof(s3));
}