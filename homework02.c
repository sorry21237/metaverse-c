#include <stdio.h>
#include <stdlib.h>

#include "homework02.h"
#include "common_function.h"

void homework02(void) //show list of day 02 and choose the problem num
{

	//edit array size F_A[number of the days]
	void (*workList[2])() = { homework0201,
														homework0202,
	};
	int fp_arraySize = sizeof workList / sizeof workList[0];

	printf("-------- show work list -------\n");
	for (int i = 1; i <= fp_arraySize; i++)
	{
		printf("homework num %d\n", i);
	}

	int flag = 0;
	do
	{
		printf("choose the homework : ");
		flag = scanf_int();
	} while (flag == 0 || flag > fp_arraySize);

	workList[flag - 1]();
}

void homework0201(void)
{
	// judge multiples
	int firstnum;
	int secondnum;

	while (1) //if you want input any char not number
	{
		printf("input 1st num : ");
		if (scanf_s("%d", &firstnum) == 0)
		{
			printf("wrong input");
			break;
		}

		printf("input 2nd num : ");
		if (scanf_s("%d", &secondnum) == 0)
		{
			printf("wrong input");
			break;
		}

		//judge num except 2nd num 0 case
		if (secondnum != 0)
		{
			if (firstnum % secondnum == 0)
			{
				printf("%d is %d's multiples\n", secondnum, firstnum);
			}
			else
			{
				printf("%d is not %d's multiples\n", secondnum, firstnum);
			}
		}
		else
		{
			printf("numbers cannot be divided by 0\n");
		}
	}
}

void homework0202(void)
{
	//bubble sort array 
	int sort_array[3];
	int arraysize = sizeof sort_array / sizeof sort_array[0];

	for (int i = 0; i < arraysize; i++)
	{
		printf("input %d numbers : ", i);
		if (scanf_s("%d", &sort_array[i]) == 0)
		{
			printf("wrong input\n");
			exit(0);
		}
	}

	//show array list
	for (int i = 0; i < arraysize; i++)
	{
		printf("%d \t", sort_array[i]);
	}
	printf("\n");

	//sorting
	for (int i = 0; i < arraysize; i++)
	{
		for (int j = i + 1; j < arraysize; j++)
		{
			if (sort_array[i] > sort_array[j])
			{
				swap(&sort_array[i], &sort_array[j]);
			}
		}
	}
	
	//show sorting array list
	for (int i = 0; i < arraysize; i++)
	{
		printf("%d \t", sort_array[i]);
	}
	printf("\n");
}