/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */


#include "../include/clib.h"




int odd_ones(unsigned x)
{
	unsigned t = x ^ (x >> 16);
	t = t ^ (t >> 8);
	t = t ^ (t >> 4);
	t = t ^ (t >> 2);
	t = t ^ (t >> 1);

	return 0x1 & t;
}


void test(unsigned x)
{
	char s[40] = {};
	itoa(x, s);
	printf("%d\n%s\n%d\n-----------\n", x, s, odd_ones(x));
}


int main()
{
	test(0xa7f62a7d);
	test(0xb6fe46b9);
test(0xef71fb8c);
test(0x275667b5);
test(0x2d0d206a);
test(0x3acdc8fa);
test(0xcd5bb51b);
test(0xcb0d70d0);
test(0x0bb0d43c);
test(0xe44bcb60);
test(0xc2fea27f);
test(0xce70135a);
test(0xe3a76972);
test(0x1fdc1d96);
test(0x07b85c4a);
test(0x89b2efdd);
test(0x91daa3da);
test(0x9b389ba9);
test(0x04ca48ed);
test(0xabad3dba);
test(0x2b2d5887);
test(0x8914ac20);
test(0x56d7c88b);
test(0x10c8b772);
test(0x2470a109);
test(0x31c703f6);
test(0xc9652085);
test(0x6cce2673);
test(0xc6124ac5);
test(0x79922a33);
test(0x88a5ea9e);
test(0x9e5e9a86);
test(0x9b60ee10);
test(0x0234e783);
test(0x33ef6866);
test(0xc2f3ee18);
test(0xb4a53137);
test(0x3f45930f);
test(0xa93ce84d);
test(0x48a0d396);
test(0x62c15a34);
test(0x1df2a2a3);
test(0x6d7238d1);
test(0xa7aa9e35);
test(0x402118fa);
test(0xea3e1c23);
test(0x45d54430);
test(0x17da2590);
test(0xa07fb0dd);
test(0x8d06e817);
test(0x30a0ac2c);

	return 0;
}

