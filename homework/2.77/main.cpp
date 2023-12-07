#include "gtest/gtest.h"


TEST(测试, 测试)
{
	int x = 80;
	EXPECT_EQ((x << 4) + x, x * 17);
	printf("(x << 4) + x = %d, x * 17 = %d\n", (x << 4) + x, x * 17);
	EXPECT_EQ(x*(-7), x-(x<<3));
	printf("x*(-7) = %d, x-(x<<3) = %d\n", x*(-7), x-(x<<3));
	EXPECT_EQ(x*60, (x<<6)-(x<<2));
	printf("x*60 = %d, (x<<6)-(x<<2) = %d\n", x*60, (x<<6)-(x<<2));
	EXPECT_EQ(x*(-112), (x<<4)-(x<<7));
	printf("x*(-112) = %d, (x<<4)-(x<<7) = %d\n", x*(-112), (x<<4)-(x<<7));
}