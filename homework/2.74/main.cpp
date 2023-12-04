#include "gtest/gtest.h"
#include "../include/clib.h"


int tsub_ok(int x, int y)
{
	int mask = (-1) << ((sizeof(int) << 3) - 1);
	int z = x - y;
	return !(((x & mask)^(y & mask)) & ((x & mask)^(z & mask)));
}


TEST(tsub_ok, 相等)
{
	EXPECT_EQ(tsub_ok(300, 400), 1);
	EXPECT_EQ(tsub_ok(INT32_MAX, -1), 0);
	EXPECT_EQ(tsub_ok(INT32_MAX, -INT32_MAX), 0);
	EXPECT_EQ(tsub_ok(INT32_MAX, INT32_MIN), 0);
	EXPECT_EQ(tsub_ok(0x7FFFFFFF, 0xC0000000), 0);
	EXPECT_EQ(tsub_ok(-2000, 59999), 1);
	EXPECT_EQ(tsub_ok(0xC0000000, 0x7FFFFFFF), 0);
	EXPECT_EQ(tsub_ok(INT32_MIN, 1), 0);
	EXPECT_EQ(tsub_ok(INT32_MIN, INT32_MAX), 0);
	EXPECT_EQ(tsub_ok(INT32_MIN, INT32_MIN), 1);
}