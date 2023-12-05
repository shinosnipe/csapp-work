#include "gtest/gtest.h"


void* calloc(size_t nmemb, size_t size)
{
	void* ptr = NULL;
	if (nmemb == 0 || size == 0)
	{
		return ptr;
	}
	size_t buff_size = nmemb * size;
	if (nmemb == buff_size / size)
	{
		ptr = malloc(buff_size);
		if (ptr != NULL)
		{
			memset(ptr, 0, buff_size);
		}
	}
	return ptr;
}