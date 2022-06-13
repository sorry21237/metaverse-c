#include <stdio.h>

#include "call_example.h"

#include "call_homework.h"
#include "homework01.h"
#include "homework02.h"
#include "homework03.h"
#include "homework04.h"
#include "homework05.h"


int input_target(void); // category choose function

int main(void)
{
	int type = 0;

	// category choose
	printf("What do you want to see ?\n");
	printf("1. example code\n2. homework code\n");
	type = input_target();

	switch (type)
	{
	case 1: // exam list call function in call_exam.c
		call_exam();
		break;
	case 2: // homework list call function in call_work.c
		call_work();
		break;
	default:
		break;
	}

	return 0;
}

int input_target(void) // category choose function
{
	int flag_t = 0;
	do
	{
		printf("input the number you want : ");
		if (scanf_s("%d", &flag_t))
		{
			if (flag_t > 2 || flag_t <= 0) //wrong range num input
			{
				printf("wrong input. try again\n");
				return input_target();
			}
			else 
			{
				return flag_t;
			}
		}
		else //wrong type input
		{
			printf("wrong input. try again\n");
		}
	} while (getchar() != '\n');

	return input_target();
}