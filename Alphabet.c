/* Author: pbollom
Date: 2020-06-03
Description: Writes out the en-US alphabet in an array */
#include<stdio.h>

#define SIZE	'z'-'a'+1
#define UPPER   1

char letters[SIZE];

int main()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        letters[i] = UPPER ? 'A' + i : 'a' + i;
    }

    printf("{");
    printf("%c", letters[0]);
    for (i = 1; i < SIZE; i++)
    {
        printf(", %c", letters[i]);
    }
    printf("}\n");

    return 0;
}