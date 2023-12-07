/*
 * main.c
 * Copyright (C) 2023 chilono <chilono@debian>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include "../include/clib.h"

#define POS_INFINITY 1.8e308+1e10
#define NEG_INFINITY -1.8e308-1e10
#define NEG_ZERO     -1.0e-1000

int main()
{
	double d = POS_INFINITY;
	printf("%lf\n", d);
	show_bytes(&d, sizeof(d));

	d = NEG_INFINITY;
	printf("%lf\n", d);
	show_bytes(&d, sizeof(d));

	d = NEG_ZERO;
	printf("%lf\n", d);
	show_bytes(&d, sizeof(d));


	return 0;
}
