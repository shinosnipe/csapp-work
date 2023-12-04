#include "gtest/gtest.h"
#include "../include/clib.h"


// 返回int补码乘法的高w位
int signed_high_prod(int x, int y)
{
	long z = (long)x * (long)y;
	return z >> (sizeof(int) << 3);
}


unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	// 调用signed_high_prod返回无符号的高位
	int w = sizeof(int) << 3;
	int mask = -1 << (w - 1);
	int signed_mask_x = (int)(x & mask) >> (w - 1);
	int signed_mask_y = (int)(y & mask) >> (w - 1);
	return signed_high_prod(x, y) + (signed_mask_x & y) + (signed_mask_y & x);
}


int main()
{
	print2bitl(-1L * 0x0FFFFFFFL);
	print2bit(signed_high_prod(-1, 0x0FFFFFFF));
	print2bitl(-1u * 0x0FFFFFFFL);
	print2bit(unsigned_high_prod(-1u, 0x0FFFFFFFU));
	print2bitl(-1000000L * -1000000L);
	print2bit(signed_high_prod(-1000000, -1000000));

	return 0;
}