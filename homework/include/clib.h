/*******************************************************************************
 * @File name: clib.h
 * @Author: chilono
 * @Version: 0.1
 * @Date: 2022-11-24
 * @Description: 做作业使用的一些通用函数
 ******************************************************************************/


/*******************************************************************************
 * 头文件引用
 ******************************************************************************/
#include <string.h>
#include <stdint.h>
#include <stdio.h>


/*******************************************************************************
 * 类型声明
 ******************************************************************************/
typedef unsigned char *byte_pointer;


/*******************************************************************************
 * 函数声明
 ******************************************************************************/
void itoa(int, char[]);
void reverse(char[]);
void ltoa(long, char[]);


/*******************************************************************************
 * Function name: itoa
 * Description: int转换二进制char字符
 * @param n	要转换成二进制的int
 * @param s	返回二进制char的数组
 ******************************************************************************/
void itoa(int n, char s[])
{
	int i;
	for (i = 0; i < sizeof(int)*8; i++)
	{
		s[i] = (n&0x1) + '0';
		n = n >> 1;
	}

	// 末尾添加结尾符
	s[i] = '\0';
	reverse(s);
}


/*******************************************************************************
 * Function name: reverse
 * Description: 反转字符数组
 * @param s	要反转的字符数组
 ******************************************************************************/
void reverse(char s[])
{
	int len = strlen(s);

	int i, j;
	for (i = 0, j = len-1; i < j; i++, j--)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}


/*******************************************************************************
 * Function name: ltoa
 * Description: 
 * @param s	要反转的字符数组
 ******************************************************************************/
void ltoa(long n, char s[])
{
	char ctmp[80] = {0};
	itoa(n, ctmp);
	itoa(n>>(sizeof(int)<<3), s);
	strcat(s, ctmp);
}


/*******************************************************************************
 *
 ******************************************************************************/
void print2bit(int x)
{
	char s[40] = {};
	itoa(x, s);
	printf("%s\n", s);
}


/*******************************************************************************
 * Function name: show_bytes
 * Description: 打印十六进制的字节
 * @param start	打印开始地址
 * @param len	打印长度
 ******************************************************************************/
void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_short(short x)
{
	show_bytes((byte_pointer) &x, sizeof(short));
}
void show_int(int x)
{
	show_bytes((byte_pointer) &x, sizeof(int));
}
void show_long(long x)
{
	show_bytes((byte_pointer) &x, sizeof(long));
}
void show_double(double x)
{
	show_bytes((byte_pointer) &x, sizeof(double));
}


/*******************************************************************************
 * Function name: is_little_endian
 * Description: 判断机器是否是小端
 * @return 返回小端是否值
 * 	-1 机器是小端
 * 	-0 机器是大端
 ******************************************************************************/
int is_little_endian()
{
	int16_t a = 0x1234;
	int8_t b = ((byte_pointer) &a)[0];

	if (b == 0x34)
	{
		return 1;
	}

	return 0;
}


/*******************************************************************************
 * Function name: replace_byte
 * Description: 替换指定字节
 * @param[in] x	目标操作的字
 * @param[in] i 替换字节的位置，以低位0到高位编号
 * @param[in] b 替换的内容字节
 * @return 返回替换过的x
 ******************************************************************************/
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	((byte_pointer)&x)[i] = b;
	return x;
}

