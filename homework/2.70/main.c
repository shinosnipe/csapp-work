/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"
#include <limits.h>


int fits_bits(int x, int n)
{
	unsigned w = sizeof(int)<<3;
	unsigned mask = 0 - 1;
	mask = mask >> (w-n);
	mask = ~mask;
	int result = !(x & mask);
	print2bit(mask);
	print2bit(x);
	print2bit(result);

	return result;
}


int main()
{
	printf("%d\n", fits_bits(-32768, 16));
	printf("%d\n", fits_bits(32767, 16));
	printf("%d\n", fits_bits(INT_MAX, 32));
	printf("%d\n", fits_bits(INT_MIN, 32));
	printf("%d\n", fits_bits(0, 16));
	printf("%d\n", fits_bits(0, 32));
	printf("%d\n", fits_bits(32768, 16));
	printf("%d\n", fits_bits(-32769, 16));
	printf("%d\n", fits_bits(INT_MIN, 31));
	printf("%d\n", fits_bits(INT_MAX, 31));

	return 0;
}
