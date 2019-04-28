#include <stdio.h>

int main(int argc, char* argv[])
{
	int count = 0;
	int exchangeNum;
	int remainder;
	int e, f, c = 0;

	scanf("%d %d %d", &e, &f, &c);

	exchangeNum = (e + f)/ c;
	remainder = (e + f) % c;
	count += exchangeNum;
	
    while (exchangeNum + remainder >= c)
	{
		int temp = exchangeNum + remainder;
	    exchangeNum = temp / c;
		remainder = temp % c;
		count += exchangeNum;
	}

    printf("%d\n", count);
	return 0;
}