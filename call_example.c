#include <stdio.h>

#include "call_example.h"

#include "exam_triangle.h"

void call_exam(void);
int input_exam(int arraySize);

void call_exam(void) //examp_XXXXXX.c function calling
{

	//edit array size F_A[number of the days]
	void (*workDate[1])() = { exam01, //exam ....
	};

	const int fp_arraySize = sizeof workDate / sizeof workDate[0];

	int whatExam = input_exam(fp_arraySize);

	for (int i = 0; i <= fp_arraySize; i++) // search choosen date homework list
	{
		if (i == whatExam)
		{
			workDate[whatExam - 1](); //date num start 1 but array num start 0
		}
	}

}

int input_exam(int arraySize) // input homework date in range of array size
{
	int flag = 0;
	int date = arraySize; //recursion parameter save (in the case of errors)
	do
	{
		printf("%d exam exist\n", arraySize);
		printf("input the exam number you want : ");
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