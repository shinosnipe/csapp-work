/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"


unsigned rotate_left(unsigned x, int n)
{
	unsigned t = 0;
	unsigned w = sizeof(unsigned)<<3;
	t |= x << n;
	t |= x >> (w - n);
	return t;
}


int main()
{
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 6));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 16));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 20));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 21));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 0));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 31));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 0));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 4));
	printf("%x, %x\n", 0x12345678, rotate_left(0x12345678, 20));

	return 0;
}
