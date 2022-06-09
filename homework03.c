#include <stdio.h>

#include "homework03.h"
#include "common_function.h"

void homework03(void) //show list of day 03 and choose the problem num
{

	//edit array size F_A[number of the days]
	void (*workList[5])() = { homework0301,
														homework0302,
														homework0303,
														homework0304,
														homework0305,
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

void homework0301(void)
{
	// table's multiplication table

	int table = 0;
	printf("input multiplication table num : ");
	table = scanf_int();

	printf("-----%d multiplication table-----\n\n", table);
	for (int i = 1; i <= 9; i++)
	{
		printf("%d * %d = %d\n", table, i, table * i);
	}
}

void homework0302(void)
{
	// 1 ~ 9 multiplication table
	for (int i = 1; i <= 9; i++)
	{
		printf("-----%d multiplication table-----\n\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d * %d = %d\t", i, j, i * j);
			if (j % 3 == 0)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
}

void homework0303(void)
{
	// select range of multiplication table

	int startnum = 0;
	int endnum = 0;

	printf("input start num : ");
	startnum = scanf_int();
	printf("input end num : ");
	endnum = scanf_int();

	//prevent if the end is bigger then the start
	if (endnum > startnum)
	{
		swap(&startnum, &endnum);
	}

	//print table
	printf("===== start from %d to %d multiplication table =====\n\n", startnum, endnum);
	for (int i = startnum; i <= endnum; i++)
	{
		printf("-----* %d multiplication table *-----\n\n", i);

		for (int j = 1; j <= 9; j++)
		{
			printf("%d * %d = %d\t", i, j, i * j);
			//change the row at multiple of 3
			if (j % 3 == 0)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
}

void homework0304(void)
{
	//buzz game (similar to 369game)

	int num = 0;
	printf("intput number 10 ~ 50 : ");
	do
	{
		num = scanf_int();
	} while (num >= 10 && num <= 50);

	printf("buzz on the 3 game 1 ~ %d\n", num);

	for (int i = 1; i <= num; i++)
	{
		if (i % 10 == 0)
		{
			for (int j = i / 10; j > 0; j--)
			{
				printf("BOOM");
			}
			printf("\n");
		}
		else if (i / 10 != 0 && i / 10 % 3 == 0)
		{
			printf("BUZZ\n");
		}
		else if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9)
		{
			printf("buzz\n");
		}
		else
		{
			printf("%d ", i);
		}
	}
}

void homework0305(void)
{
	// select range of multiplication table
	// change row at print 3 table

	int startnum = 0;
	int endnum = 0;

	printf("input start num : ");
	startnum = scanf_int();
	printf("input end num : ");
	endnum = scanf_int();

	//exception at end bigger then start
	if (endnum < startnum)
	{
		swap(&startnum, &endnum);
	}

	//printf table
	printf("===== start from %d to %d multiplication table =====\n\n", startnum, endnum);

	for (int i = startnum; i <= endnum; i += 3)
	{
		//multple 1 ~ 9
		for (int j = 1; j <= 9; j++)
		{
			//printf three table at once
			for (int k = i; k < i + 3; k++)
			{
				//if i + 3 bigger than end stop print
				if (k <= endnum)
				{
					printf("%d * %d = %d\t", k, j, k * j);
				}
			}
			printf("\n");
		}
		//row change
		printf("\n");
	}
}