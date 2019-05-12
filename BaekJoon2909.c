#include <stdio.h>

int main(int argc, char* argv[])
{
	int priceofCandy, numberofZero;
	scanf("%d %d", &priceofCandy, &numberofZero);

	int tmp = 1;
	for (int i = 0; i < numberofZero; i++)
	    tmp *= 10;
	
	int remainder;
        remainder = priceofCandy % tmp;

	if (remainder >= tmp / 2)
		priceofCandy = priceofCandy + (tmp - remainder); 
	else    priceofCandy -= remainder;
    
	printf("%d\n", priceofCandy);
	return 0;
}
