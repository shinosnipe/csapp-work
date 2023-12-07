/*
 * main.c
 * Copyright (C) 2023 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include "../include/clib.h"



int main()
{
	int i1 = 0x7f7fffff;
	float *fi = &i1;
	float f0 = *fi;

	printf("%f\n", f0);
	show_float(f0);
}
