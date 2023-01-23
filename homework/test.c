/*
 * test.c
 * Copyright (C) 2022 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include "include/clib.h"

int main()
{
	printf("%X\n", replace_byte(0x12345678, 2, 0xAB));
	printf("%X\n", replace_byte(0x12345678, 0, 0xAB));

	return 0;
}
