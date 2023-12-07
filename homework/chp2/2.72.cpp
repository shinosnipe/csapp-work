#include "gtest/gtest.h"


/*
原判断条件出现的问题是sizeof的结果是size_t类型，该类型是unsigned long类型，是无符号的。
当无符号做减法，得到的结果会溢出，成为一个很大的数字。
条件判断永远得不到小于0的数字，因为无符号结果根本没有小于0的，致使条件判断永远为真。*/
void copy_int(int val, void *buf, int maxbytes)
{
	if (maxbytes-(int)sizeof(val) >= 0)
		memcpy(buf, (void*) &val, sizeof(val));
}


TEST(copy_int, 复制成功)
{
	int buf = 0;
	copy_int(0x67, &buf, 4);
	EXPECT_EQ(buf, 0x67);
	copy_int(0x5266, &buf, 4);
	EXPECT_EQ(buf, 0x5266);
	copy_int(0xad765, &buf, 4);
	EXPECT_EQ(buf, 0xad765);
	copy_int(0x114514, &buf, 4);
	EXPECT_EQ(buf, 0x114514);
}

TEST(copy_int, 无法复制)
{
	int buf = 0;
	copy_int(2333, &buf, 2);
	EXPECT_NE(buf, 2333);
	copy_int(4567, &buf, 2);
	EXPECT_NE(buf, 4567);
	copy_int(818, &buf, 2);
	EXPECT_NE(buf, 818);
	copy_int(383838, &buf, 2);
	EXPECT_NE(buf, 383838);
}