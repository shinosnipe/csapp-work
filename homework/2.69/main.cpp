/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"
#include "gtest/gtest.h"


unsigned rotate_left(unsigned x, int n)
{
	unsigned t = 0;
	unsigned w = sizeof(unsigned)<<3;
	t |= x << n;
	t |= x >> (w - n);
	return t;
}


TEST(rotate_left, 相等)
{
	#define SNUM 0x12345678
	EXPECT_EQ(0x8d159e04, rotate_left(SNUM, 6));
	EXPECT_EQ(0x56781234, rotate_left(SNUM, 16));
	EXPECT_EQ(0x12345678, rotate_left(SNUM, 0));
	EXPECT_EQ(0x23456781, rotate_left(SNUM, 4));
	EXPECT_EQ(0x67812345, rotate_left(SNUM, 20));
}