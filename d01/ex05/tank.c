#include "header.h"
#include <stdlib.h>
#include <strings.h>

#define N_STACKS 1
#define STACK_MAX 1000

struct s_tank *initTank(void)
{
	struct s_tank	*tank;

	if ((tank = malloc(sizeof(struct s_tank))) == NULL)
		return (NULL);

	tank->stacks = malloc( (N_STACKS + 1) * sizeof(struct s_stack *));
	bzero(tank->stacks, (N_STACKS + 1) * sizeof(struct s_stack *));
	int i = 0;
	while (i < N_STACKS)
	{
		tank->stacks[i] = malloc(sizeof(struct s_stack));
		bzero(tank->stacks[i], sizeof(struct s_stack));
		i++;
	}
	tank->n = N_STACKS;
	return (tank);
}

void addStack(struct s_tank *tank)
{
	int i = tank->n + 1;
	struct s_stack **new_stacks;

	if ((new_stacks = malloc( (i + 1) * sizeof(struct s_stack *))) == NULL)
		return ;
	bzero(new_stacks, (i + 1) * sizeof(struct s_stack *));
	i = 0;
	while (i < tank->n)
	{
		new_stacks[i] = tank->stacks[i];
		i++;
	}
	new_stacks[i] = malloc(sizeof(struct s_stack));
	bzero(new_stacks[i], sizeof(struct s_stack));
	free(tank->stacks);
	tank->stacks = new_stacks;
	tank->n = tank->n + 1;
	return ;
}

void insertElement(struct s_stack *stack, int energy)
{
	struct	s_elem	*elem;
	struct	s_elem	*ptr;

	elem = malloc(sizeof(struct s_elem));
	elem->energy = energy;
	elem->next = NULL;

	if (stack->elem == NULL)
	{
		stack->elem = elem;
		stack->sum += energy;
		return ;
	}
	ptr = stack->elem;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = elem;
	stack->sum += energy;
	return ;
}

void tankPush(struct s_tank *tank, int energy)
{
	// see if we need to add a stack to tank
	

	struct s_stack	*stack;

	if (tank == NULL)
		return ;
	int i = 0;
	while (i < tank->n)
	{
		if (tank->stacks[i]->sum + energy < STACK_MAX)
		{
			stack = tank->stacks[i];
			//insert energy here
			insertElement(stack, energy);
			return ;
		}
		i++;
	}
	addStack(tank);
	stack = tank->stacks[tank->n - 1];
	insertElement(stack, energy);
	return ;
}

int tankPop(struct s_tank *tank)
{
	struct s_stack	*stack;
	struct s_elem	*elem;
	struct s_elem	*prev;
	int				result = 0;

	if ((tank->n == 1) && (tank->stacks[0]->sum == 0))
		return (0);

	stack = tank->stacks[tank->n - 1];
	elem = stack->elem;
	if ((elem == NULL) && (stack->sum == 0))
	{
		free(stack);
		tank->stacks[tank->n - 1] = NULL;
		tank->n = tank->n - 1;
		return (tankPop(tank));
	}
	if (elem != NULL)
	{
		prev = elem;
		while (elem->next != NULL)
		{
			prev = elem;
			elem = elem->next;
		}
		result = elem->energy;
		stack->sum -= result;
		if ((stack->sum == 0) && (tank->n > 1))
		{
			free(stack);
			tank->stacks[tank->n - 1] = NULL;
			tank->n = tank->n - 1;
		}
		prev->next = NULL;
		free(elem);
	}
	return (result);
}

