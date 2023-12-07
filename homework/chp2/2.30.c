/*
 * main.c
 * Copyright (C) 2022 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>


int tadd_ok(int, int);

void test1(int x, int y)
{
	printf("%d + %d = %d over: %d\n", x, y, x+y, tadd_ok(x, y));
}

int main()
{
	test1(2324, 252525);
	test1(9999999999, 222222);
	test1(1<<30, 1<<30);
	test1(-238924, -23);
	test1(-(1<<31)+10, -(1<<31)+10);

	return 0;
}

int tadd_ok(int x, int y)
{
	int z = x + y;
	return !(x>0&&y>0&&z<=0) && !(x<0 && y<0 && z>=0);
}
