#include <stdio.h>
#include <stdlib.h>

int copyArray[1000];

void merge(int array[], int start, int middle, int end)
{
	int i = start;
	int j = middle + 1;
	int k = i;

	while (i <= middle && j <= end)
	{
		if (array[i] <= array[j])
		{
			copyArray[k] = array[i];
			i++;
		}
		else 
		{
			copyArray[k] = array[j];
			j++;
		}

		k++;
	}

	if (i > middle)
	{
		while (j <= end)
		{
			copyArray[k] = array[j];
			j++;
			k++;
		}
	}

	else 
	{
		while (i <= middle)
		{
			copyArray[k] = array[i];
			i++;
			k++;
		}
	}

	for (int t = start; t <= end; t++)
		array[t] = copyArray[t];
}

void mergeSort(int array[], int start, int end)
{
	if (start < end)
	{
        int middle = (start + end) / 2;
		mergeSort(array, start, middle);
		mergeSort(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}

int main(void)
{
	int count = 0;
	int* numArray = NULL;
	int i, j = 0;

	scanf("%d", &count);
	numArray = (int*)malloc(sizeof(int) * count);

	for (i = 0; i < count; i++)
	{
		int value;
		scanf("%d", &value);
		numArray[i] = value;
	}
	
	mergeSort(numArray, 0, count - 1);

	for (int i = 0; i < count; i++)
		printf("%d\n", numArray[i]);

    free(numArray);
	return 0;
}