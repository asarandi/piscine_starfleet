#include <stdlib.h>
#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue	*queue;

	if ((queue = malloc(sizeof(struct s_queue))) == NULL)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char *dequeue(struct s_queue *queue)
{
	struct s_node	*ptr;
	char			*message;

	if ((queue == NULL) || (queue->first == NULL))
		return (NULL);
	ptr = queue->first;
	message = ptr->message;
	queue->first = ptr->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free(ptr);
	return (message);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*new_element;

	if (queue == NULL)
		return ;
	if ((new_element = malloc(sizeof(struct s_node))) == NULL)
		return ;
	new_element->message = message;
	new_element->next = NULL;
	if (queue->last != NULL)
		queue->last->next = new_element;
	queue->last = new_element;
	if (queue->first == NULL)
		queue->first = new_element;
	return ;
}


char *peek(struct s_queue *queue)
{
	if ((queue == NULL) || (queue->first == NULL))
		return (NULL);
	return (queue->first->message);

}

int isEmpty(struct s_queue *queue)
{

	if ((queue == NULL) || (queue->first == NULL))
		return (1);
	return (0);
}
