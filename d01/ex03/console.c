#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"
#include <ctype.h>


#define	BUFSIZE 512
#define MAXLENGTH 256
#define	UNDO "UNDO"
#define SEND "SEND"
#define PROMPT "?: "

struct	s_stack *initStack()
{
	struct	s_stack	*stack;

	if ((stack = malloc(sizeof(struct s_stack))) == NULL)
		return (NULL);
	bzero(stack, sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void	push(struct s_stack *stack, int idx)
{
	struct s_item	*item;

	if (stack == NULL)
		return ;
	if ((item = malloc(sizeof(struct s_item))) == NULL)
		return ;
	bzero(item, sizeof(struct s_item));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
	return ;
}

int		pop(struct s_stack *stack)
{
	struct	s_item	*item;
	int				result;

	if ((stack == NULL) || (stack->item == NULL))
		return (0);
	item = stack->item;
	result = item->idx;
	stack->item = item->next;
	free(item);
	return (result);
}

char	*console(void)
{
	struct	s_stack	*stack;
	char	input[BUFSIZE];
	int		i;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;

	if ((stack = initStack()) == NULL)
		return (NULL);
	bzero(&input, BUFSIZE);
	i = 0;
	while (1)
	{
		printf("%s", PROMPT);
		if ((linelen = getline(&line, &linecap, stdin)) < 0)
			break ;
		while ((linelen > 0) && (isspace(line[linelen - 1])))
			line[--linelen] = 0;
		if (linelen == 0)
			continue ;
		if (strncmp(line, UNDO, 4) == 0)		//UNDO
		{
			bzero(&input[i], BUFSIZE - i);
			if (stack->item != NULL)
			{
				i = pop(stack);
				bzero(&input[i], BUFSIZE - i);
				while ((i > 0) && (isspace(input[i - 1])))
					input[--i] = 0;
				if (i > 0)
					input[i++] = ' ';
			}
		}
		else if (strncmp(line, SEND, 4)  == 0)	//SEND
		{
			bzero(&input[i], BUFSIZE - i);
			while (stack->item != NULL)
				pop(stack);
			free(stack);
			return (strdup(&input[0]));
		}
		else									//ADD TO STACK
		{
			if (i + linelen < MAXLENGTH)
			{
				strncpy(&input[i], line, linelen);
				input[i + linelen] = ' ';
				push(stack, i);
				i += linelen + 1;
			}
			else
				printf("[maximum message length exceeded]\n");
		}
		printf("%s\n\n", &input[0]);
	}
	return ("\n");
}
