#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;
	int* numArray = NULL;
	int i, j = 0;

	scanf("%d", &count);
	numArray = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++)
	{
		int value;
		scanf("%d", &value);
		numArray[i] = value;
	}

	for (i = 0; i < count - 1; i++)
	{
		int minIndex = i;
		for (j = i + 1; j < count; j++)
		{
			if (numArray[minIndex] > numArray[j])
				minIndex = j;
		}

		if (minIndex != i)
		{
			int temp = numArray[i];
			numArray[i] = numArray[minIndex];
			numArray[minIndex] = temp;
		}
	}

	for (int i = 0; i < count; i++)
		printf("%d\n", numArray[i]);
	
	return 0;
}