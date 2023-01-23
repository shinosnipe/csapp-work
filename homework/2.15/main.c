#include <stdio.h>
#include "../include/clib.h"

int func2_15(int x, int y)
{
	return !~(x^~y);
}

void testi()
{
	FILE *fp = fopen("testi.txt", "r");
	while (!feof(fp))
	{
		int x, y;
		fscanf(fp, "%d,%d", &x, &y);

		// 测试代码
		printf("x: %d\ny: %d\n", x, y);
		printf("x==y: %d\n", x==y);
		printf("func: %d\n", func2_15(x, y));
		printf("===========================\n");
	}
}

int main()
{
	testi();

	return 0;
}
