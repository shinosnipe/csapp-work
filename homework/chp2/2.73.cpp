#include "gtest/gtest.h"


// 提前计算TMax和T_Min
// 默认unsigned和int同位
int TMax = (unsigned)-1 >> 1;
int TMin = (unsigned)-1 << ((sizeof(int) << 3)-1);


// x和y进行加法，正溢出返回INT32_MAX，副溢出返回INT_32MIN，不溢出返回正常计算结果。
int saturating_add(int x, int y)
{
	// 判断xy符号相同，不同直接返回结果
	// xy符号相同，判断x与z符号，相同直接返回结果
	// xz符号不同，x为正返回TMax，x为负返回TMin

	// z是xy的正常计算结果
	int z = x + y;
	// w是int的位数
	int w = (sizeof(int) << 3);
	// 符号位掩码
	int signed_mask = -1 << (w-1);
	// 符号全掩码，符号不同11..11，符号相同00..00
	int xy_signed = (x^y&signed_mask) >> (w-1);
	int xz_signed = (x^z&signed_mask) >> (w-1);
	// x符号位，负全1,正全0
	int x_signed = (x&signed_mask) >> (w-1);

	// 计算结果
	// 比较傻的与列表实现
	int result = (xy_signed & z) | (~xy_signed & ~xz_signed & z) | (~xy_signed & xz_signed & ~x_signed & TMax)
		| (~xy_signed & xz_signed & x_signed & TMin);
	return result;
}


TEST(saturating_add, 相等)
{
	EXPECT_EQ(saturating_add(3434, 5656), 3434+5656);
	EXPECT_EQ(saturating_add(114514, 818), 114514+818);
	EXPECT_EQ(saturating_add(INT32_MAX, 1), INT32_MAX);
	EXPECT_EQ(saturating_add(INT32_MAX, INT32_MAX), INT32_MAX);
	EXPECT_EQ(saturating_add(-2287, -9983), -2287+-9983);
	EXPECT_EQ(saturating_add(-2233, -4455), -2233-4455);
	EXPECT_EQ(saturating_add(INT32_MIN, -1), INT32_MIN);
	EXPECT_EQ(saturating_add(INT32_MIN, INT32_MIN), INT32_MIN);
	EXPECT_EQ(saturating_add(10000, -20000), 10000-20000);
	EXPECT_EQ(saturating_add(INT32_MAX, INT32_MIN), -1);
}

TEST(saturating_add, 不相等)
{
	EXPECT_NE(saturating_add(467623, 2674), 2);
	EXPECT_NE(saturating_add(273723, 28472874), 5);
	EXPECT_NE(saturating_add(-232, -55), -9);
}