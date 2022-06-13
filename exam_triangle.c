#include <stdio.h>

#include "exam_triangle.h"
#include "common_function.h"

void equilateral(int* line);
void equilateralinverted(int* p_line);
void rightangle(int* line);
void rightinverted(int* line);
void leftinverted(int* line);
void leftrightangle(int* line);
void leftangle(int* p_line);
void rightangle(int* p_line);
void diamond(int* p_line);

void homework01(void) //show list of day 01 and choose the problem num
{

	//edit array size F_A[number of the days]
	void (*workList[3])() = { exam0101,
														exam0102,
														exam0103,
	};
	int fp_arraySize = sizeof workList / sizeof workList[0];

	printf("-------- show work list -------\n");
	for (int i = 1; i <= fp_arraySize; i++)
	{
		printf("exam num %d\n", i);
	}
	printf("-------------------------------\n");
	int flag = 0;
	do
	{
		printf("what work ? : ");
		flag = scanf_int();
	} while (flag == 0 || flag > fp_arraySize);

	workList[flag - 1]();
}

void exam0101(void)
{

	for (int i = 1; i <= 100; i++)
	{
		printf("%d\t", i);

		if (i % 10 == 0)
		{
			printf("\n");
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d\t", i);
		}
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}
}

void exam0102(void)
{
	int num = 0;
	printf("intput num : ");
	num = scanf_int();

	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			printf("%d\t", i);
		}
	}

}

void exam0103(void)
{
	int line = 0;
	int flag = 1;

	printf("what size of triangle? : ");
	line = scanf_int();

	printf("triangle choose\n");
	printf("---------------\n");
	printf("0. exit\n");
	printf("1. equilateral triangle\n");
	printf("2. inverted equilateral triangle\n");
	printf("3. right-angle triangle\n");
	printf("4. right inverted triangle\n");
	printf("5. left right-angle triangle\n");
	printf("6. left inverted triangle\n");
	printf("7. left angle triangle\n");
	printf("8. right angle triangle\n");
	printf("9. diamond\n");

	do
	{
		flag = scanf_int();
		switch (flag)
		{
		case 0:
			break;
		case 1:
			//equilateral triangle
			equilateral(line);
		case 2:
			//inverted equilateral triangle
			equilateralinverted(line);
		case 3:
			//right-angled triangle
			rightangle(line);
		case 4:
			//right inverted triangle
			rightinverted(line);
		case 5:
			//left right inverted triangle
			leftrightangle(line);
		case 6:
			//left right inverted triangle
			leftinverted(line);
		case 7:
			//left right triangle + left inverted right triangle
			leftangle(line);
		case 8:
			//right inverted triangle + right triangle
			rightangle(line);
		case 9:
			//diamond
			diamond(line);
		}
	} while (flag);
}

void equilateral(int* line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line - i; j++)
		{
			printf("-");

		}
		for (int k = 0; k < i * 2 + 1; k++)
		{
			printf("*");

		}
		printf("\n");
	}
}

void equilateralinverted(int* p_line)
{
	int line = p_line;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("-");
		}
		for (int k = 0; k < 2 * (line - i) - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void rightangle(int* line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line - i; j++)
		{
			printf("-");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void rightinverted(int* line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("-");
		}
		for (int k = 0; k < line - i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void leftinverted(int* line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void leftrightangle(int* line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void leftangle(int* p_line)
{
	int line = p_line;

	for (int i = 0; i <= line; i++)
	{
		if (i <= (line + 1) / 2)
		{
			for (int j = 0; j < i; j++)
			{
				printf("*");
			}
		}
		else
		{
			for (int k = 0; k <= line - i; k++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
}

void rightangle(int* p_line)
{
	int line = p_line;

	for (int i = 0; i < line; i++)
	{
		if (i < (line + 1) / 2)
		{
			for (int j = 0; j < i; j++)
			{
				printf("-");
			}
			for (int k = 0; k < (line + 1) / 2 - i; k++)
			{
				printf("*");
			}
		}
		else
		{
			for (int j = 0; j < (line - i) - 1; j++)
			{
				printf("-");
			}
			for (int k = 0; k <= i - ((line + 1) / 2) + 1; k++)
			{
				printf("*");
			}

		}
		printf("\n");
	}
}

void diamond(int* p_line)
{
	int whatcase;
	int line = p_line;

	for (int i = 0; i < line; i++)
	{
		if (i < (line + 1) / 2)
		{
			whatcase = 1;
		}
		else
		{
			whatcase = 2;
		}

		switch (whatcase)
		{
		case 1: //0 ~ 5
			for (int j = 0; j < line - i; j++)
			{
				printf("-");

			}
			for (int k = 0; k < i * 2 + 1; k++)
			{
				printf("*");

			}
			break;
		case 2: //6 ~ 9
			for (int j = 0; j < i + 1; j++)
			{
				printf("-");
			}
			for (int k = 0; k <= 2 * ((line - i) - 1); k++)
			{
				printf("*");
			}
			break;
		default:
			break;
		}
		printf("\n");
	}
}