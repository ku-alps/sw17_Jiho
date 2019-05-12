#include <stdio.h>
#include <stdlib.h>

void quickSort(int* array, int start, int end)
{
    if (start >= end)
	return;
	
    int i = start + 1;
	int j = end;
	int pivot = start;
	int temp;

	while (i <= j)
	{
		while (array[i] <= array[pivot] && i <= end)
			i++;
		while (array[j] >= array[pivot] && j > start)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		else
		{
			temp = array[pivot];
			array[pivot] = array[j];
			array[j] = temp;
		}
	}
	
    quickSort(array, start, j - 1);
    quickSort(array, j + 1, end);
}

int main(int argc, char* argv[])
{
	int count;
	scanf("%d", &count);

	int* array = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		int input;
		scanf("%d", &input);
		array[i] = input;
	}

	quickSort(array, 0, count - 1);
	for (int i = 0; i < count; i++)
		printf("%d\n", array[i]);

	free(array);
	return 0;
}
