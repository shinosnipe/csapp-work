/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"
#include <limits.h>
#include "gtest/gtest.h"


/*
int fits_bits(int x, int n)
{
	unsigned w = sizeof(int)<<3;
	unsigned mask = 0 - 1;
	mask = mask >> (w-n);
	mask = ~mask;
	int result = !(x & mask);
	print2bit(mask);
	print2bit(x);
	print2bit(result);

	return result;
}
*/


int fits_bits(int x, int n)
{
	unsigned w = sizeof(int)<<3;
	// 当x为正数时全为0,负数时全为1。
	unsigned signed_bit = (int)(x & ~((unsigned)0b1 << (w-2))) >> (w - 1);
	unsigned source_code = (~x & signed_bit) | (x & ~signed_bit);
	unsigned mask = 0b1 << (n - 1);
	mask = mask >> 1;
	// 填满1的低位
	mask |= mask >> 16;
	mask |= mask >> 8;
	mask |= mask >> 4;
	mask |= mask >> 2;
	mask |= mask >> 1;
	mask = ~mask;
	// 若有为1的位，说明不能表示为n位补码
	unsigned result = !(source_code & mask);

	return result;
}


TEST(fits_bits, 可以表示)
{
	EXPECT_EQ(1, fits_bits(747, 11));
	EXPECT_EQ(1, fits_bits(298623168, 30));
	EXPECT_EQ(1, fits_bits(-1924040441, 32));
	EXPECT_EQ(1, fits_bits(17550, 16));
	EXPECT_EQ(1, fits_bits(-3935839, 23));
	EXPECT_EQ(1, fits_bits(106958, 18));
	EXPECT_EQ(1, fits_bits(14506526, 25));
}

TEST(fits_bits, 不能表示)
{
	EXPECT_EQ(0, fits_bits(747, 10));
	EXPECT_EQ(0, fits_bits(298623168, 29));
	EXPECT_EQ(0, fits_bits(-1924040441, 31));
	EXPECT_EQ(0, fits_bits(17550, 15));
	EXPECT_EQ(0, fits_bits(-3935839, 22));
	EXPECT_EQ(0, fits_bits(106958, 17));
	EXPECT_EQ(0, fits_bits(14506526, 24));
}

TEST(fits_bits, 极限情况)
{
	EXPECT_EQ(1, fits_bits(0, 1));
	EXPECT_EQ(1, fits_bits(-1, 1));
	EXPECT_EQ(0, fits_bits(1, 1));
	EXPECT_EQ(0, fits_bits(-2, 1));
	EXPECT_EQ(1, fits_bits(0x80000000-1, 32));
	EXPECT_EQ(1, fits_bits((int)0x80000000, 32));
}