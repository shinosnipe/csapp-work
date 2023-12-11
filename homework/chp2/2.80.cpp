#include "gtest/gtest.h"
#include "../include/clib.h"


// 计算3/4x的值，不会溢出，向0舍入
int threefourths(int x)
{
	int sig_var = (unsigned)x >> 31;
	int w = sizeof(x) << 3;
	int h_x = x >> (w >> 1);
	int result_h = (((h_x << 1) + h_x) >> 2) << (w >> 1);
	int result_l = ((x << 1) + x ) >> 2;
	int result = ((-1 << (w >> 1)) & result_h) | (((unsigned)-1 >> (w >> 1)) & result_l);

	return result + ((bool)(0b11 & (x << 1) + x) & sig_var);
}


TEST(threefourths, 测试)
{
	int x = 0;
	EXPECT_EQ(threefourths(x), 0);
	x = 1;
	EXPECT_EQ(threefourths(x), 0);
	EXPECT_EQ(threefourths(8) , 6);
	EXPECT_EQ(threefourths(9) , 6);
	EXPECT_EQ(threefourths(10) , 7);
	EXPECT_EQ(threefourths(11) , 8);
	EXPECT_EQ(threefourths(12) , 9);
	EXPECT_EQ(threefourths(-8) , -6);
	EXPECT_EQ(threefourths(-9) , -6);
	EXPECT_EQ(threefourths(-10) , -7);
	EXPECT_EQ(threefourths(-11) , -8);
	EXPECT_EQ(threefourths(-12) , -9);
	EXPECT_EQ(threefourths(INT32_MIN) , (int)(INT32_MIN*0.75));
	EXPECT_EQ(threefourths(INT32_MAX) , (int)(INT32_MAX*0.75));
}