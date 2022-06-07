#include <stdio.h>
#include <stdlib.h>

void swap(int* sort_a, int* sort_b) // swap two int variable
{
	int temp = 0;

	temp = sort_a;
	sort_a = sort_b;
	sort_b = temp;
}

int scanf_int(void) //scanf_exception_handling
{
	int result = 0;
	do
	{
		if (scanf_s("%d", &result))
		{
			return result;
		}
		else //wrong type input
		{
			printf("wrong input. try again\n");
		}
	} while (getchar() != '\n');

	return scanf_int();
}