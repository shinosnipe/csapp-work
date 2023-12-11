#include "gtest/gtest.h"
#include "../include/clib.h"


// 设默认类型为int,w是int的位长
int answer_2_81_1(int k)
{
	return 1 << k;
}

int answer_2_81_2(int j, int k)
{
	return ((1 << j) - 1) << k;
}


int main()
{
	print2bit(answer_2_81_1(10));
	print2bit(answer_2_81_1(20));
	print2bit(answer_2_81_1(17));
	print2bit(answer_2_81_2(3, 6));
	print2bit(answer_2_81_2(7, 8));
	print2bit(answer_2_81_2(20, 7));
	print2bit(answer_2_81_2(15, 15));
	print2bit(answer_2_81_2(3, 24));
}