#include <stdio.h>

#include "homework01.h"
#include "scanf_exception_handling.h"


void homework01(void) //show list of day 01 and choose the problem num
{
	void (*workList[4])() =	{ homework0101,
														homework0102,
														homework0103,
														homework0104,
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
		printf("what work ? : ");
		flag = scanf_int();
	} while (flag == 0 || flag > fp_arraySize);

	workList[flag - 1]();
}

void homework0101(void)
{
	// input two integer and use arithmetic operation

	int a, b;

	printf("intput 1st number : ");
	a = scanf_int();
	printf("intput 2nd number : ");
	b = scanf_int();


	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	if (b != 0)
	{
	printf("%d / %d = %f\n", a, b, (double)a / b);
	printf("%d %% %d = %d\n", a, b, a % b);
	}
}

void homework0102(void)
{
	// input three integer and get sum and avg

	int arrayNum[3];
	int arraySize = 3;
	int sum = 0;

	for (int i = 0; i < arraySize; i++)
	{
		printf("input num %d : ", i);
		scanf_s("%d", &arrayNum[i]);

		sum += arrayNum[i];
	}

	float avg = sum / arraySize;

	printf("Number's sum : %d, avg : %.2f\n", sum, avg);
}

void homework0103(void)
{
	//input the second and print hour minute second

	int sec;

	int result_second;
	int result_minute;
	int result_hour;
	printf("input the second : ");
	sec = scanf_int();

	result_second = sec;

	result_hour = floor(sec / 3600);
	if (result_hour > 0)
	{
		result_second -= result_hour * 3600;
	}
	result_minute = floor(result_second / 60);

	if (result_minute > 0)
	{
		result_second -= result_minute * 60;
	}
	result_second %= 60;

	printf("%d second is %d hour %d min %d sec", sec, result_hour, result_minute, result_second);
}

void homework0104(void)
{
	//buy the things and calculating the change

	int price = 0;
	int pay = 0;

	printf("input the price : ");
	price = scanf_int();
	printf("input the pay : ");
	pay = scanf_int();

	int charge = pay - price;

	int temp = charge;
	int thousand = 0;
	int hundred = 0;
	int ten = 0;

	while (temp >= 1000)
	{
		thousand += 1;
		temp -= 1000;
	}
	while (temp >= 100)
	{
		hundred += 1;
		temp -= 100;
	}
	while (temp >= 10)
	{
		ten += 1;
		temp -= 10;
	}

	printf("charge is : %d\n", charge);
	printf("thousand : %d\n", thousand);
	printf("hundred : %d\n", hundred);
	printf("ten : %d\n", ten);
}