/*
 * test.c
 * Copyright (C) 2022 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include "../include/clib.h"

int main()
{
	int x = 0x89ABCDEF;
	int y = 0x76543210;

	printf("%X\n", y&(~0xFF)|x&0xFF);

	return 0;
}
