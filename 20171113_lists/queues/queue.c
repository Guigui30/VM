#include <stdlib.h>
#include <stdio.h>

#include "queue.h"


void queue_init(struct queue *queue)
{
	queue->size = 0;
	queue->store = NULL;
}

int queue_is_empty(struct queue *queue)
{
	return queue->store == NULL;
}

void queue_push(struct queue *queue, void *elm)
{
	struct list *i = malloc(sizeof(struct list));
	i->data = elm;
	if(queue->size == 0)
	{
		i->next = i;
		queue->store = i;
		queue->size = 1;
	}
	else
	{
		i->next = queue->store->next;
		queue->store->next = i;
		queue->store = queue->store->next;
		queue->size += 1;
	}
}

void* queue_pop(struct queue *queue)
{
	if(queue->size == 0)
		return NULL;
	else if(queue->size == 1)
	{
		queue->size = 0;
		struct list *elm = queue->store;
		queue->store = NULL;
		void *data = elm->data;
		free(elm);
		return data;
	}
	else
	{
		struct list *elm = queue->store->next;
		queue->store->next = queue->store->next->next;
		queue->size -= 1;
		void *data = elm->data;
		free(elm);
		return data;
	}
}
