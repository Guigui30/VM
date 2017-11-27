#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hash_table.h"

static void OK(int x)
{
	printf("- should be ");
	if(x == 1)
		printf("OK\n");
	else if(x == 0)
		printf("FAILED\n");
	else if(x == 2)
		printf("CLEAR\n");
	else
		printf("NOT PRESENT\n");
}

static struct htable* create(size_t capacity)
{
	struct htable *table = create_htable(capacity);
	printf("Create htable of capacity %zu : ", capacity);
	if(table != NULL)
		printf("OK ");
	else
		printf("FAILED ");
	return table;
}

static void spec(struct htable *table)
{
	size_t count = 0;
	for(size_t i = 0; i < table->capacity; i++)
	{
		if(*(table->tab+i) != NULL)
			count += 1;
	}
	printf("Size : %zu - should be %zu\n", table->size, count);
	printf("Capacity : %zu\n\n", table->capacity);
}

static void add(struct htable *table, char *s, char *v)
{
	int done = add_htable(table, s, v);
	printf("Add %s (type : %s) : ", s, v);
	if(done)
		printf("OK ");
	else
		printf("FAILED ");
}

static int search(struct htable *table, char *s, int mode)
{
	struct pair *search = access_htable(table, s);
	if(mode)
	{
		printf("Search for %s : ", s);
		if(search != NULL)
			printf("OK ");
		else
			printf("FAILED ");
	}
	return search == NULL;
}

static void delete(struct htable *table, char *s)
{
	if(search(table, s, 0))
		printf("Try remove %s but it is not present ", s);
	else
	{
		remove_htable(table, s);
		printf("Remove %s : ", s);
		if(search(table, s, 0))
			printf("OK ");
		else
			printf("FAILED ");
	}
}

static void clear(struct htable *table)
{
	printf("Clean htable : ");
	if(table->size == 0)
		printf("already clear ");
	else
	{
		clear_htable(table);
		if(table->size == 0)
			printf("OK ");
		else
			printf("FAILED ");
	}
}

static void free_t(struct htable *table)
{
	free(table->tab);
	free(table);
}

int main()
{
	char *s1 = "bonjour";
	char *s2 = "hello";
	char *s3 = "yooo";
	char *s4 = "2015";
	char *s5 = "2016";
	char *s6 = "2017";

	char *type1 = "word";
	char *type2 = "year";
	
	struct htable *table = create(2);
	OK(1);
	spec(table);

	delete(table, s1);
	OK(3);
	spec(table);

	search(table, s1, 1);
	OK(0);
	search(table, s2, 1);
	OK(0);
	search(table, s3, 1);
	OK(0);
	search(table, s4, 1);
	OK(0);
	search(table, s5, 1);
	OK(0);
	search(table, s6, 1);
	OK(0);

	printf("\n");

	add(table, s1, type1);
	OK(1);
	spec(table);
	add(table, s2, type1);
	OK(1);
	spec(table);
	add(table, s3, type1);
	OK(1);
	spec(table);
	add(table, s4, type2);
	OK(1);
	spec(table);
	add(table, s5, type2);
	OK(1);
	spec(table);
	add(table, s6, type2);
	OK(1);
	spec(table);
	add(table, s6, type2);
	OK(0);
	spec(table);


	search(table, s2, 1);
	OK(1);
	printf("\n");
	delete(table, s2);
	OK(1);
	spec(table);
	delete(table, s2);
	OK(3);
	spec(table);


	delete(table, s1);
	OK(1);
	spec(table);
	delete(table, s3);
	OK(1);
	spec(table);
	delete(table, s4);
	OK(1);
	spec(table);
	delete(table, s5);
	OK(1);
	spec(table);
	delete(table, s6);
	OK(1);
	spec(table);


	clear(table);
	OK(2);
	add(table, s1, type1);
	OK(1);
	clear(table);
	OK(1);

	printf("\n");
	free_t(table);
	return 1;
}
