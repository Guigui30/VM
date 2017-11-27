#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

uint32_t hash(char *data)
{
	uint32_t h = 0;
	while(*data != 0)
	{
		h+= *data;
		h+= 1024*h;
		h = h ^ h/64;
		data++;
	}
	h += h*8;
	h = h ^ h/2048;
	h += h*32768;
	return h;
}

struct htable* create_htable(size_t capacity)
{
	struct htable *htable = malloc(sizeof(struct htable));
	if(htable != NULL)
	{
		htable->size = 0;
		htable->capacity = capacity;
		htable->tab = malloc(sizeof(struct pair*)*capacity);
		if(htable->tab == NULL)
			return NULL;		
		for(uint32_t i = 0; i < htable->capacity; i++)
			*(htable->tab+i) = NULL;
		return htable;
	}
	else
		return NULL;
}

struct pair* access_htable(struct htable *htable, char *key)
{
	uint32_t h = hash(key)%htable->capacity;
	struct pair *i = *(htable->tab+h);
	for(; i != NULL && strcmp(i->key,key) != 0; i = i->next)
		continue;
	return i;
}

static void auto_resize(struct htable *htable)
{
	if(htable->size/htable->capacity>0.75)
	{
		struct pair **new = malloc(sizeof(struct pair*)*htable->capacity*2);
		struct pair **old = htable->tab;
		for(uint32_t i = 0; i < htable->capacity*2; i++)
			*(new+i) = NULL;
		uint32_t oldCap = htable->capacity;
		htable->capacity *= 2;
		htable->size = 0;
		htable->tab = new;
		for(uint32_t i = 0; i<oldCap; i++)
		{
			struct pair *j = *(old+i);
			if(j!=NULL)
			{
				struct pair *k = j->next;
				for(; k != NULL; k = k->next)
				{
					add_htable(htable, j->key, j->value);
					free(j);
					j = k;
				}
				add_htable(htable, j->key, j->value);
				free(j);
			}
		}
		free(old);
	}
}

int add_htable(struct htable *htable, char *key, void *value)
{
	uint32_t h = hash(key)%htable->capacity;
	struct pair *i = *(htable->tab+h);
	for(; i != NULL && strcmp(i->key,key) != 0; i = i->next)
		continue;
	if(i != NULL)
		return 0;
	struct pair *p = malloc(sizeof(struct pair));
	if(p == NULL)
		return 0;
	p->key = key;
	p->value = value;
	p->hkey = h;
	if(*(htable->tab+h) == NULL)
		htable->size += 1;
	p->next = *(htable->tab+h);
	*(htable->tab+h) = p;
	auto_resize(htable);
	return 1;
}

void remove_htable(struct htable *htable, char *key)
{
	uint32_t h = hash(key)%htable->capacity;
	struct pair *i = *(htable->tab+h);
	if (i != NULL)
	{
		if(strcmp(i->key, key) == 0)
		{
			*(htable->tab+h) = i->next;
			free(i);
			if(*(htable->tab+h) == NULL)
				htable->size -= 1;
		}
		else
		{
			for(; i->next != NULL && strcmp(i->next->key, key) != 0; i = i->next)
				continue;
			if (i->next != NULL)
			{
				struct pair *rm = i->next;
				i->next = i->next->next;
				free(rm);
				if(*(htable->tab+h) == NULL)
					htable->size -= 1;
			}
		}
	}
}

void clear_htable(struct htable *htable)
{
	for(uint32_t i = 0; i<htable->capacity; i++)
	{
		struct pair *j = *(htable->tab+i);
		if(j!=NULL)
		{
			struct pair *k = j->next;
			while(k!=NULL)
			{
			  free(j);
			  j = k;
			  k = k->next;
			}
			free(j);
		}
	}
	htable->size = 0;
}
