/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"


int leftmost_one(unsigned x)
{
	print2bit(x);
	x |= (x >> 1);
	print2bit(x);
	x |= (x >> 2);
	print2bit(x);
	x |= (x >> 4);
	print2bit(x);
	x |= (x >> 8);
	print2bit(x);
	x |= (x >> 16);
	print2bit(x);

	return x & ((~x >> 1) | 0x80000000);
}


int main()
{
	print2bit(leftmost_one(0x288a8c8f));
	print2bit(leftmost_one(0xf2888332));

	return 0;
}


