/*
 * main.c
 * Copyright (C) 2023 chilono <shinosnipe@qq.com>
 *
 * Distributed under terms of the GPL3 license.
 */

#include "../include/clib.h"


int any_odd_one(unsigned x)
{
	return !(0xAAAAAAAA & ~x);
}


void test(unsigned x)
{
	show_int(x);
	printf("%u\n", any_odd_one(x));
}


int main()
{
	test(0xAAAAAAAA);
	test(0xBBBECECF);
        test(0xBEAEABCF);
        test(0xBECBFCCC);
        test(0xAACCAEBF);
        test(0xCCCFBEFB);
        test(0xAEEBCCCA);
        test(0xCECCCACE);
        test(0xFBACFBCF);
        test(0xFCECECCC);
        test(0xCEBCBCAE);
        test(0xEFFECAEC);
        test(0xBEBFFEAA);
        test(0xEBCFFEEB);
        test(0xFBFFECEC);
        test(0xBEEAACCB);
        test(0xEBCEEEBB);
        test(0xFFFABBCE);
        test(0xFCCECBEA);
        test(0xFFAFEECE);
        test(0xECCBCFAB);
        test(0xFEBFFECF);
        test(0xCBBBCFCC);
        test(0xBCCCECCF);
        test(0xEFCACCBF);
        test(0xFFAABFBB);
        test(0xEEFFBEBE);
        test(0xFBAABABF);
        test(0xCCCCECBB);
        test(0xCECBECAC);
        test(0xBBCCCBFF);
        test(0xCCCAECFA);
        test(0xCFCEBCEC);
        test(0xCBFBACBF);
        test(0xBCABFBEB);
        test(0xACCFACCA);
        test(0xFCEBEECC);
        test(0xAACFECAA);
        test(0xAFFCFECC);
        test(0xFFBCCACE);
        test(0xFECECCEF);
        test(0xEAECEEFC);
        test(0xEABFFFBB);
        test(0xACFCAAFB);
        test(0xEBCCCEFB);
        test(0xAEBECECC);
        test(0xBCBEEFFC);
        test(0xBEBFBCBF);
        test(0xCFCEEBEE);
        test(0xAFBEAFFC);
        test(0xFFABBABE);
	test(0xFFFFFFFF);

	return 0;
}
