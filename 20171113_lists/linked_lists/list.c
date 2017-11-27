#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void list_init (struct list *list)
{
	list->next = NULL;
}

int list_is_empty(struct list *list)
{
	return list->next == NULL;
}

size_t list_len(struct list *list)
{
	struct list *i = list;
	size_t counter = 0;
	while (i->next != NULL)
	{
		counter++;
		i = i->next;
	}
	return counter;
}

void list_push_front(struct list *list, struct list *elm)
{
	elm->next = list->next;
	list->next = elm;
}

struct list* list_pop_front(struct list *list)
{
	struct list *elm = list->next;
	if(elm != NULL)
		list->next = elm->next;
	return elm;
}

struct list* list_find(struct list *list, int value)
{
	struct list *finder = list->next;
	while(finder != NULL && finder->data != value)
		finder = finder->next;
	if(finder==NULL)
		return NULL;
	return finder;
}

struct list* list_lower_bound(struct list *list, int value)
{
	struct list *found = list;
	while(found->next != NULL && found->next->data<value)
		found = found->next;
	return found;
}

int list_is_sorted(struct list *list)
{
	struct list *i = list->next;
	while(i->next != NULL && i->data <= i->next->data)
		i = i->next;
	return i->next == NULL;
}

void list_insert(struct list *list, struct list *elm)
{
	struct list *i = list;
	while(i->next != NULL && i->next->data<elm->data)
		i = i->next;
	elm->next = i->next;
	i->next = elm;
}

void list_rev(struct list *list)
{
	struct list *p = NULL;
	struct list *i = list->next;
	while(i->next != NULL)
	{
		struct list *x = i->next;
		i->next = p;
		p = i;
		i = x;
	}
	i->next = p;
	list->next = i;
}

void list_half_split(struct list *list, struct list *second)
{
	struct list *p1 = list;
	struct list *p2 = list;
	while(p1 != NULL)
	{
		p1 = p1->next;
		if(p1 != NULL)
			p1 = p1->next;
		if(p1 != NULL)
			p2 = p2->next;
	}
	second->next = p2->next;
	p2->next = NULL;
}
