#include "gtest/gtest.h"
#include <math.h>


int divide_power2(int x, int k)
{
	return x >> k;
}


TEST(divide_power2, 测试)
{
	int x = INT32_MIN;
	EXPECT_EQ(x/((int)pow(2, 1)), divide_power2(x, 1));
	EXPECT_EQ(x/((int)pow(2, 2)), divide_power2(x, 2));
	EXPECT_EQ(x/((int)pow(2, 3)), divide_power2(x, 3));
	EXPECT_EQ(x/((int)pow(2, 4)), divide_power2(x, 4));
	EXPECT_EQ(x/((int)pow(2, 5)), divide_power2(x, 5));
	EXPECT_EQ(x/((int)pow(2, 6)), divide_power2(x, 6));
	EXPECT_EQ(x/((int)pow(2, 7)), divide_power2(x, 7));
	EXPECT_EQ(x/((int)pow(2, 8)), divide_power2(x, 8));
	EXPECT_EQ(x/((int)pow(2, 9)), divide_power2(x, 9));
	EXPECT_EQ(x/((int)pow(2, 10)), divide_power2(x, 10));
	EXPECT_EQ(x/((int)pow(2, 11)), divide_power2(x, 11));
	EXPECT_EQ(x/((int)pow(2, 12)), divide_power2(x, 12));
	EXPECT_EQ(x/((int)pow(2, 13)), divide_power2(x, 13));
	EXPECT_EQ(x/((int)pow(2, 14)), divide_power2(x, 14));
	EXPECT_EQ(x/((int)pow(2, 15)), divide_power2(x, 15));
	EXPECT_EQ(x/((int)pow(2, 16)), divide_power2(x, 16));
	EXPECT_EQ(x/((int)pow(2, 17)), divide_power2(x, 17));
	EXPECT_EQ(x/((int)pow(2, 18)), divide_power2(x, 18));
	EXPECT_EQ(x/((int)pow(2, 19)), divide_power2(x, 19));
	EXPECT_EQ(x/((int)pow(2, 20)), divide_power2(x, 20));
	EXPECT_EQ(x/((int)pow(2, 21)), divide_power2(x, 21));
	EXPECT_EQ(x/((int)pow(2, 22)), divide_power2(x, 22));
	EXPECT_EQ(x/((int)pow(2, 23)), divide_power2(x, 23));
	EXPECT_EQ(x/((int)pow(2, 24)), divide_power2(x, 24));
	EXPECT_EQ(x/((int)pow(2, 25)), divide_power2(x, 25));
	EXPECT_EQ(x/((int)pow(2, 26)), divide_power2(x, 26));
	EXPECT_EQ(x/((int)pow(2, 27)), divide_power2(x, 27));
	EXPECT_EQ(x/((int)pow(2, 28)), divide_power2(x, 28));
	EXPECT_EQ(x/((int)pow(2, 29)), divide_power2(x, 29));
	EXPECT_EQ(x/((int)pow(2, 30)), divide_power2(x, 30));
	EXPECT_EQ(-1, divide_power2(x, 31));
}