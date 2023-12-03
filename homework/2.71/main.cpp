#include "gtest/gtest.h"
#include "../include/clib.h"


typedef unsigned packed_t;


int xbyte(packed_t word, int bytenum)
{
	return (int)((word << ((3 - bytenum) << 3))) >> 24;
}


TEST(xbyte, 标准)
{
	packed_t word_a = 0x12345678;
	EXPECT_EQ(xbyte(word_a, 0), 0x78);
	EXPECT_EQ(xbyte(word_a, 1), 0x56);
	EXPECT_EQ(xbyte(word_a, 2), 0x34);
	EXPECT_EQ(xbyte(word_a, 3), 0x12);

	packed_t word_b = 0x83A6E5D4;
	EXPECT_EQ(xbyte(word_b, 0), 0xFFFFFFD4);
	EXPECT_EQ(xbyte(word_b, 1), 0xFFFFFFE5);
	EXPECT_EQ(xbyte(word_b, 2), 0xFFFFFFA6);
	EXPECT_EQ(xbyte(word_b, 3), 0xFFFFFF83);
}