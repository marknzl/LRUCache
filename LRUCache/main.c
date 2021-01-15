#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "cache.h"

void FreeInt(int* i)
{
	// This is a dummy free-function
	printf("Freeing %d\n", *i);
}

int main(void)
{
	// DRIVER CODE FOR TESTING PURPOSES
	
	struct Cache cache;
	CacheInit(&cache, 5);

	/* DUMMY DATA */
	char* key1 = "hey1";
	int i1 = 69;

	char* key2 = "hey2";
	int i2 = 420;

	char* key3 = "hey3";
	int i3 = 21;

	char* key4 = "hey4";
	int i4 = 70;

	char* key5 = "hey5";
	int i5 = 71;
	/* DUMMY DATA */

	CacheInsert(&cache, key1, &i1, FreeInt);
	CacheInsert(&cache, key2, &i2, FreeInt);
	CacheInsert(&cache, key3, &i3, FreeInt);
	CacheInsert(&cache, key4, &i4, FreeInt);
	CacheInsert(&cache, key5, &i5, FreeInt);
	
	// After insertions, linkedlist looks like:
	// 5 -> 4 -> 3 -> 2 -> 1

	int* temp = CacheGet(&cache, key1);
	printf("%d\n", *temp);

	// We get a cache hit. Previously, '1' was at the back of the
	// linkedlist, but now it will move to the front:
	// 1 -> 5 -> 4 -> 3 -> 2

	CacheCleanup(&cache);

	return 0;
}