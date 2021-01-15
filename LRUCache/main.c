#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "cache.h"

struct Player
{
	int kills;
	int deaths;
};

void FreePlayer(struct Player* player)
{
	printf("Freeing player: %d, %d\n", player->kills, player->deaths);
	//free(player);
}

void FreeInt(int* ptr)
{
	printf("Freeing %d\n", *ptr);
	free(ptr);
}

int main(void)
{
	/*char* key1 = "hey1";
	int* ptr1 = malloc(sizeof(int));
	if (ptr1 != NULL)
		*ptr1 = 69;

	char* key2 = "hey2";
	int* ptr2 = malloc(sizeof(int));
	if (ptr2 != NULL)
		*ptr2 = 70;

	char* key3 = "hey3";
	int* ptr3 = malloc(sizeof(int));
	if (ptr3 != NULL)
		*ptr3 = 71;

	char* key4 = "hey4";
	int* ptr4 = malloc(sizeof(int));
	if (ptr4 != NULL)
		*ptr4 = 72;

	char* key5 = "hey5";
	int* ptr5 = malloc(sizeof(int));
	if (ptr5 != NULL)
		*ptr5 = 73;

	struct Cache* cache = malloc(sizeof(struct Cache));
	if (cache == NULL)
		return 1;
	CacheInit(cache, 5);
	CacheInsert(cache, key1, ptr1, FreeInt);
	CacheInsert(cache, key2, ptr2, FreeInt);
	CacheInsert(cache, key3, ptr3, FreeInt);
	CacheInsert(cache, key4, ptr4, FreeInt);
	CacheInsert(cache, key5, ptr5, FreeInt);

	int* iPtr = CacheGet(cache, "hey5");
	if (iPtr != NULL)
	{
		printf("%d\n", *iPtr);
	}

	CacheCleanup(cache);
	free(cache);*/

	struct File* file1 = FileLoad("C:\\Users\\Mark\\Documents\\Visual Studio 2019\\Projects\\LRUCache\\bin\\x64\\Debug\\test.txt");
	if (file1 == NULL)
	{
		printf("An error occurred.\n");
		return 1;
	}

	struct File* file2 = FileLoad("C:\\Users\\Mark\\Documents\\Visual Studio 2019\\Projects\\LRUCache\\bin\\x64\\Debug\\1.jpg");
	if (file2 == NULL)
	{
		printf("An error occurred.\n");
		return 1;
	}

	FileCopy(file2, "copy.jpg");

	/*struct Cache cache;
	CacheInit(&cache, 5);
	CacheInsert(&cache, "file1", file1, FileDestroy);
	CacheInsert(&cache, "file2", file2, FileDestroy);

	struct File* temp = CacheGet(&cache, "file2");
	printf("%s\n", temp->fileName);

	CacheCleanup(&cache);*/

	return 0;
}