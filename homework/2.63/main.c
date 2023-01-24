/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include <stdio.h>
#include "../include/clib.h"


unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int) x >> k;
	unsigned mask = (0x1 << (8*sizeof(signed)-k))-1;
	return xsra & mask;
}


int sra(int x, int k)
{
	int xsrl = (unsigned) x >> k;
	int s = (x >> ((sizeof(unsigned) * 8 ) - 1 )) & 0x1;
	s && (xsrl = (xsrl | ~((0x1 << (8 * sizeof(int) - k)) - 1)));
	return xsrl;
}


int main()
{
	printf("%10X\n", sra(0x12345678, 8));
	printf("%10X\n", 0x12345678 >> 8);
	printf("%10X\n", sra(0xF2345678, 8));
	printf("%10X\n", 0xF2345678 >> 8);
	return 0;
}
