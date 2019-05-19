#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char* argv[])
{
	int count;
	scanf("%d", &count);

	int* SanggeunArray = (int*)malloc(sizeof(int)*count);
	int* SajangArray = (int*)malloc(sizeof(int)*count);

	for (int i = 0; i < count; i++)
		scanf("%d", SanggeunArray + i);
	for (int i = 0; i < count; i++)
		scanf("%d", SajangArray + i);

	int j = 0;
	int finish;
	for (finish = -1; finish < count - 3; finish++)
	{
		int i = j;
		while (SanggeunArray[i] != SajangArray[j])
			i++;

		int index = i - j;
		if (index == 0);

		else
		{
			if (index % 2 == 0)
			{
				while (i != j)
				{
					swap(SanggeunArray + i, SanggeunArray + i - 2);
					swap(SanggeunArray + i, SanggeunArray + i - 1);
					i -= 2;
				}
			}

			else
			{
				while (i - j > 1)
				{
					swap(SanggeunArray + i, SanggeunArray + i - 2);
					swap(SanggeunArray + i, SanggeunArray + i - 1);
					i -= 2;
				}

				swap(SanggeunArray + i, SanggeunArray + i - 1);
				swap(SanggeunArray + i + 1, SanggeunArray + i);
			}
		}
		j++;
	}

	if (SanggeunArray[finish + 1] == SajangArray[j])
		printf("Possible\n");
	else
		printf("Impossible\n");

	free(SanggeunArray);
	free(SajangArray);
	return 0;
}