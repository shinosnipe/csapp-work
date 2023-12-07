/*
 * main.c
 * Copyright (C) 2023 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int test(int x)
{
	int result = !(~x) || !x || !(~x&0xFF) || !((x>>((sizeof(int)-1)<<3))&0xFF);
	printf("%X\n", x);
	printf("%d\n", result);

	return 0;
}

int main()
{
	test(0x00);
	test(0x11);
	test(0xFF);
	test(0x00267474);
	test(0x837482FF);
	test(0x73647263);
	test(0x63746251);


	return 0;
}
