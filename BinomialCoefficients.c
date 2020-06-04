/* Author: pbollom
Date: 2020-06-03
Description: Writes a SIZE x SIZE table of binomial coefficients */
#include<stdio.h>

#define SIZE	25

long coefficients[SIZE][SIZE];

void compute();
void print();

/* compute and print the table of coefficients. doesn't handle overflow */
int main()
{
	compute();
	print();

	return 0;
}

/* compute: calculates the values of the binomial coefficients and stores them in the 
coefficients table */
void compute()
{
	int i, j;

	coefficients[0][0] = 1;
	for (i = 1; i < SIZE; i++)
	{
		coefficients[0][i] = 0;
	}

	for (i = 1; i < SIZE; i++)
	{
		coefficients[i][0] = 1l;
		for (j = 1; j < i; j++)
		{
			coefficients[i][j] = coefficients[i-1][j-1] + coefficients[i-1][j];
		}
		for (; j < SIZE; j++)
		{
			coefficients[i][j] = 0l;
		}
	}
}

/* print: outputs the coefficients table to standard output */
void print()
{
	int i, j;

	printf("{");
	for (i = 0; i < SIZE; i++)
	{
		if (i > 0)
		{
			printf(",\n");
		}
		printf("{%ld", coefficients[i][0]);
		for (int j = 1; j < SIZE - 1; j++)
		{
			printf(", %ld", coefficients[i][j]);
		}
		printf("}");
	}
	printf("}\n");
}