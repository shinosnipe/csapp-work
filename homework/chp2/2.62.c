/*
 * main.c
 * Copyright (C) 2023 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include "../include/clib.h"


int int_shifts_are_arithmetic()
{
	int x = ~0x0;
	int shifts = (sizeof(int)<<3)-1;
	x >>= shifts;
	return !(~x & 0xF0);
}


int main()
{
	printf("该机器是否使用算术右移： %d\n", int_shifts_are_arithmetic());

	return 0;
}



