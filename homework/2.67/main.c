/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"


int bad_int_size_is_32()
{
	int set_msb = 1 << 31;
	int beyond_msb = 1 << 31;
	beyond_msb = beyond_msb << 1;

	return set_msb && !beyond_msb;
}


int main()
{
	printf("%d\n", bad_int_size_is_32());

	return 0;
}



