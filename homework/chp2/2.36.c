/*
 * main.c
 * Copyright (C) 2022 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>



int tmult_ok(__int32_t x, __int32_t y)
{
	__int64_t z = x*y;
	return !(z & 0xFFFFFFFF00000000);
}

void test1(__int32_t x, __int32_t y)
{
	printf("x = %10d, y = %10d, z = %15ld, ok = %d\n", x, y, (__int64_t)x*y, tmult_ok(x,y));
}

int main()
{
	test1(0xFF00, 0x2784);
	test1(0xFFFFFFFF, 0xff);
	return 0;
}
