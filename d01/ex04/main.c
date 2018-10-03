#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue	*queue;

	if ((queue = queueInit()) == NULL)
	{
		printf("queueInit() failed :(\n");
		return (1);
	}

	char	*msg;

	msg = "roses are red";			printf("enqueue(), msg = \'%s\'\n", msg); enqueue(queue, msg);
	msg = "violets are blue";		printf("enqueue(), msg = \'%s\'\n", msg); enqueue(queue, msg);
	msg = "this is a message";		printf("enqueue(), msg = \'%s\'\n", msg); enqueue(queue, msg);
	msg = "that goes into queue";	printf("enqueue(), msg = \'%s\'\n", msg); enqueue(queue, msg);

	printf("peek(), msg = %s\n", peek(queue));
	printf("peek(), msg = %s\n", peek(queue));

	printf("dequeue(), msg = %s\n", dequeue(queue));
	printf("peek(), msg = %s\n", peek(queue));
	printf("dequeue(), msg = %s\n", dequeue(queue));
	printf("peek(), msg = %s\n", peek(queue));


	msg = "havana oh na na";		printf("enqueue(), msg = \'%s\'\n", msg); enqueue(queue, msg);
	printf("isEmpty() returns %d\n", isEmpty(queue));

	printf("dequeue(), msg = %s\n", dequeue(queue));
	printf("peek(), msg = %s\n", peek(queue));
	printf("dequeue(), msg = %s\n", dequeue(queue));
	printf("peek(), msg = %s\n", peek(queue));

	msg = "i'm going back to east atlanta na na";	printf("enqueue(), msg = \'%s\'\n", msg); enqueue(queue, msg);
	printf("isEmpty() returns %d\n", isEmpty(queue));


	printf("dequeue(), msg = %s\n", dequeue(queue));
	printf("peek(), msg = %s\n", peek(queue));
	printf("dequeue(), msg = %s\n", dequeue(queue));
	printf("peek(), msg = %s\n", peek(queue));
	printf("dequeue(), msg = %s\n", dequeue(queue));
	printf("peek(), msg = %s\n", peek(queue));

	printf("isEmpty() returns %d\n", isEmpty(queue));








	return (0);
}



// Function used for the test
// Don't go further :)

