#include <stdio.h>

#include "homework04.h"
#include "common_function.h"

void homework03(void) //show list of day 03 and choose the problem num
{

	//edit array size F_A[number of the days]
	void (*workList[3])() = { homework0401,
														homework0402,
														homework0403,
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

void homework0401(void)
{
	// input even number in the int array
	int arrInt[10] = { 0, };
	int arrSize = sizeof arrInt / sizeof arrInt[0];

	int input = 0;

	//input
	do
	{
		printf("input %dth even num : ", input + 1);
		scanf_s("%d", &arrInt[input]);

		//if is an odd input make it an even with +1
		if (arrInt[input] % 2 == 0)
		{
			input++;
		}
	} while (input < arrSize);

	for (int i = 0; i < arrSize; i++)
	{
		printf("%d\t", arrInt[i]);
	}

	/*
	for (int i = 0; i < arrSize; i++)
	{
		printf("input %dth even num : ", i + 1);
		scanf_s("%d", &arrInt[i]);

		while(arrInt[i] % 2 != 0)
		{
			printf("input %dth even num : ", i + 1);
			scanf_s("%d", &arrInt[i]);
		}
		if (arrInt[i] % 2 != 0)
		{
			i--;
		}
	}
	*/
}

void homework0402(void)
{
	//score's sum and avg
	//input error count

	int score[5] = { 0, };
	int arrSize = sizeof score / sizeof score[0];

	int sum = 0;
	float avg = 0;

	int err_cnt = 0;

	//input num at arr
	for (int i = 0; i < arrSize; i++)
	{
		printf("input %d th score : ", i);
		scanf_s("%d", &score[i]);
		if (score[i] > 100 || score[i] < 0)
		{
			score[i] = 0;
			err_cnt++;
		}
		//add score except error
		else
		{
			sum += score[i];
		}
	}
	avg = sum / arrSize;
	printf("%d error in %d input\n", err_cnt, arrSize);
	printf("sum : %d\n", sum);
	printf("avg : %.2f\n", avg);
}

void homework0403(void)
{
	// 31days 1 3 5 7 8 10 12 & 30 days 4 6 9 11 & 28 days 2

	int date = 0;
	int temp = 0;
	int month = 0;

	//start january 1st
	int monthDate[2] = { 1, 1 };

	printf("input date in 1 ~ 365 : ");
	temp = scanf_int();

	date = temp;
	
	//date calc
	do
	{
		if (month <= 6)
		{
			if (month == 1)
			{
				date -= 28;
			}
			else
			{
				date -= month % 2 != 1 ? 31 : 30;
			}
			/*
			else if (month % 2 == 1)
			{
				date -= 30;
			}
			else
			{
				date -= 31;
			}
			*/
			month++;
		}
		else if (month >= 7)
		{
			date -= month % 2 == 1 ? 31 : 30;
			/*
			if (month % 2 == 1)
			{
				date -= 31;
			}
			else
			{
				date -= 30;
			}
			*/
			month++;
		}
	} while (date >= 28);
	monthDate[0] += month;
	monthDate[1] += date;

	printf("%d day from 1 / 1 is %d / %d", temp, monthDate[0], monthDate[1]);
}