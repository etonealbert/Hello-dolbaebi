#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

float f = 15.625;

enum {RESET = 0, RED=31, GREEN, YELLOW};

void color(uint32_t color)
{
	if(color)
		printf("\033[0;%um",color);
	else
		printf("\033[0m");
}

void print_float_bin(float num)
{
	uint32_t fi;
	memcpy(&fi,&num, 4);
	for(int32_t i=31; i>=0; i--)
	{
		if(i==30 || i==22)
			putchar(' ');
		putchar('0'+((fi>>i)&1));
	}
	color(RED);
	printf("\nS ");
	color(YELLOW);
	printf("E");
	color(GREEN);
	printf("          M\n");
	color(RESET);
}

int main()
{

	float f=-15.625, f1=0;
	uint32_t i;
	for(i=0, f1=0; i<10; i++, f1+=0.1);
	
	print_float_bin(f);
	printf("\n");
	print_float_bin(f1);
	printf("\n");
	
	printf("f=%f f1=%f\n", f, f1);
	if (fabs(f-f1)< 0.00001)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
