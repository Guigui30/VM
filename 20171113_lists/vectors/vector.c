#include <stdlib.h>
#include <stdio.h>
#include <err.h>

#include "vector.h"


int vector_init(struct vector *vect, size_t capacity)
{
	vect = malloc(sizeof(struct vector));
	if(vect == NULL)
		return 0;
	vect->capacity = capacity;
	vect->size = 0;
	vect->data = malloc(sizeof(int)*capacity);
	return vect->data != NULL;
}

struct vector* vector_make(size_t capacity)
{
	struct vector *vect = NULL;
	if(vector_init(vect, capacity))
		return vect;
	return NULL;
}

int vector_push_back(struct vector *vect, int x)
{
	if(vect->size>=vect->capacity)
	{
	  int *tmp = realloc(vect->data, 2 * vect->capacity * sizeof (int));
    if (tmp == NULL) {
      // oups no more memory ?
      warn("realloc of data fails");
      return 0;
    }
    vect->data = tmp;
    vect->capacity *= 2;
  }
  *(vect->data + vect->size) = x;
	vect->size += 1;
	return 1;
}

int vector_pop_back(struct vector *vect, int *x)
{
	if(vect->size==0)
		return 0;
	vect->size -= 1;
	*x = *(vect->data+vect->size+1);
	return 1;
}

int vector_push_front(struct vector *vect, int x)
{
	if(vect->size>=vect->capacity)
	{
		int *tmp = malloc(2 * vect->capacity * sizeof (int));
    if (tmp == NULL) {
      // oups no more memory ?
      warn("malloc of data fails");
      return 0;
    }
		*(tmp) = x;
		for(size_t i = 1; i < vect->capacity+1; *(tmp+i) = *(vect->data+i-1), i++);
		free(vect->data);
    vect->data = tmp;
    vect->capacity *= 2;
		vect->size += 1;
		return 1;
	}
	else
	{
		for(size_t i = 0; i < vect->size; i++)
			*(vect->data+vect->size-i+1) = *(vect->data+vect->size-i);
		*(vect->data) = x;
		vect->size += 1;
		return 1;
	}
}

int vector_pop_front(struct vector *vect, int *x)
{
	if(vect->size==0)
		return 0;
	*x = *(vect->data);
	for(size_t i = 1; i < vect->size; i++)
		*(vect->data+i-1) = *(vect->data+i);
	vect->size -= 1;
	return 1;
}

int vector_insert_at(struct vector *vect, size_t pos, int x)
{
	if(vect->size>=vect->capacity)
	{
		int *tmp = malloc(2 * vect->capacity * sizeof (int));
    if (tmp == NULL) {
      // oups no more memory ?
      warn("malloc of data fails");
      return 0;
    }
		for(size_t i = 0; i < pos; i++)
			*(tmp+i) = *(vect->data+i);
		*(tmp+pos) = x;
		for(size_t i = pos; i < vect->capacity; i++)
			*(tmp+i+1) = *(vect->data+i);
		free(vect->data);
    vect->data = tmp;
    vect->capacity *= 2;
		vect->size += 1;
		return 1;
	}
	else
	{
		for(size_t i = pos; i < vect->size; i++)
			*(vect->data+vect->size-i+1) = *(vect->data+vect->size-i);
		*(vect->data+pos) = x;
		vect->size += 1;
		return 1;
	}
}

int vector_extract_at(struct vector *vect, size_t pos, int *x)
{
	if(vect->size==0)
		return 0;
	*x = *(vect->data+pos);
	for(size_t i = pos+1; i < vect->size; i++)
		*(vect->data+i-1) = *(vect->data+i);
	vect->size -= 1;
	return 1;
}

struct vector* vector_clone(struct vector *vect)
{
	struct vector *clone = vector_make(vect->capacity);
	clone->size = vect->size;
	for(size_t i = 0; i < vect->size; i++)
		*(clone+i) = *(vect+i);
	return clone;
}
int main()
{
	return 1;
}
