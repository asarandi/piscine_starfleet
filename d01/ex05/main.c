#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"



void printAllStacks(struct s_tank *tank)
{
	struct s_stack *stack;
	int i = 0;

	printf("number of stacks = %d\n", tank->n);

	while (i < tank->n)
	{
		if ((stack = tank->stacks[i]) == NULL)
			break ;
		printf("stack #%d, sum = %d\n", i, stack->sum);
		i++;
	}
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/

	tankPush(tank, 10); printf("push 10\n");
	tankPush(tank, 50); printf("push 50\n");
	printAllStacks(tank);
	tankPop(tank);		printf("pop\n");
	printAllStacks(tank);

	tankPush(tank, 560); printf("push 560\n");
	tankPush(tank, 980); printf("push 980\n");
	printAllStacks(tank);
	tankPush(tank, 100); printf("push 100\n");
	tankPush(tank, 500); printf("push 500\n");
	printAllStacks(tank);
	tankPop(tank);		printf("pop\n");
	printAllStacks(tank);
	tankPop(tank);		printf("pop\n");
	printAllStacks(tank);
	tankPop(tank);		printf("pop\n");
	printAllStacks(tank);
	tankPop(tank);		printf("pop\n");
	printAllStacks(tank);
	tankPop(tank);		printf("pop\n");
	printAllStacks(tank);
	tankPop(tank);		printf("pop\n");
	printAllStacks(tank);


	return (0);
}



// Function used for the test
// Don't go further :)
