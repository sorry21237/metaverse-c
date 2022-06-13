#include <stdio.h>

#include "common_function.h"

int updown(int* p_answer);

void homework05(void)
{
	int answer = randnum();

	int result = updown(answer);

	if (result == 0)
	{
		printf("so close. failed\n");
		printf("correct answer was %d\n", answer);
	}
	else
	{
		printf("-----------\n");
		printf("**you win**\n");
		printf("-----------\n");
	}
}

int updown(int* p_answer)
{
	int life = 5;
	int reply = 0;

	int correct = p_answer;
	//range
	int min = 1;
	int max = 100;

	printf("----- game start -----\n");

	//game play
	while (life)
	{
		printf("now range is : %d ~ %d\n", min, max);
		reply = scanf_int();

		//guess the range and narrow down
		if (reply == correct)
		{
			break;
		}
		else if (reply <= correct && reply >= min)
		{
			min = reply;
		}
		else if (reply >= correct && reply <= max)
		{
			max = reply;
		}
		//chance discount
		life--;
	}
	
	return life;
}
