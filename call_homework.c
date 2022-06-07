#include <stdio.h>

#include "homework01.h"

void call_work(void) //homeworkXXXX.c function calling
{

	//edit array size F_A[number of the days]
	void (*workDate[1])() = { homework01, //homework02, ...
						};

	const int fp_arraySize = sizeof workDate / sizeof workDate[0];

	int whatDate = input_work_date(fp_arraySize);

	for (int i = 0; i <= fp_arraySize; i++) // search choosen date homework list
	{
		if (i == whatDate)
		{
			workDate[whatDate - 1](); //date num start 1 but array num start 0
		}
	}
	
}

int input_work_date(int arraySize) // input homework date in range of array size
{
	int flag = 0;
	int date = arraySize; //recursion parameter save (in the case of errors)
	do
	{
		printf("%d days exist\n", arraySize);
		printf("input the date you want : ");
		if (scanf_s("%d", &flag))
		{
			if (flag > date || flag <= 0) //wrong range num input
			{
				printf("wrong input. try again\n");
				return input_work_date(date);
			}
			else
			{
				return flag;
			}
		}
		else //wrong type input
		{
			printf("wrong input. try again\n");
		}
	} while (getchar() != '\n');

	return input_work_date(date); //recursion when wrong input
}