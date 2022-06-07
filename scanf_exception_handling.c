#include <stdio.h>

int scanf_int(void)
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