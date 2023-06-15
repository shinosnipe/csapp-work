/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"


int lower_one_mask(int n)
{
	int t = 1 << (n-1);
	t |= t>>1;
	t |= t>>2;
	t |= t>>4;
	t |= t>>8;
	t |= t>>16;
	return t;
}


int main()
{
	printf("%d, %x\n", 1, lower_one_mask(1));
	printf("%d, %x\n", 2, lower_one_mask(2));
	printf("%d, %x\n", 6, lower_one_mask(6));
	printf("%d, %x\n", 12, lower_one_mask(12));
	printf("%d, %x\n", 30, lower_one_mask(30));
	printf("%d, %x\n", 31, lower_one_mask(31));
	printf("%d, %x\n", 32, lower_one_mask(32));

	return 0;
}

