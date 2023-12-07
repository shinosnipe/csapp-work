#include "gtest/gtest.h"


int mul3div4(int x)
{
	return ((x << 1) + x ) >> 2;
}


TEST(mul3div4, 测试)
{
	int x = 3847;
	EXPECT_EQ(x*3/4, mul3div4(x));
	x = INT32_MAX;
	EXPECT_EQ(x*3/4, mul3div4(x));
}