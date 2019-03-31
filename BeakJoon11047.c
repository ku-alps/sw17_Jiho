#include <stdio.h>
#include <stdlib.h>

int* makeArray(int moneyCount)              //동전의 가치를 입력받을 int 배열 동적할당하는 함수
{
	int* moneyArray = NULL;

	if (moneyCount >= 1)
	     moneyArray = (int*)calloc(moneyCount, sizeof(int));

	return moneyArray;
}

int countMoney(int moneyCount, int money, int* pArray)           //최소로 필요한 동전의 갯수를 계산하는 함수
{
	int count = 0;
	
	if (pArray != NULL)                                          //유효성 검사(매개변수)
	{
		if (moneyCount > 0 && money > 0)                         //유효성 검사(매개변수)
		{
			int i;
			for (i = moneyCount - 1; i >= 0; i--)
			{
				count += money / pArray[i];
				money %= pArray[i];
			}
		}

		else
			printf("동전의 갯수와 입력한 금액이 양의 정수인지 확인하세요.\n");
	}

	else
		printf("유효한 배열이 아닙니다.\n");

	return count;
}

int main(int argc, char* argv[])
{
	int* pArray = NULL;           //int 배열을 동적할당 받을 변수 선언
	int moneyCount, count = 0;    //동전의 갯수 및 동전 갯수의 최솟값 변수 선언
	int money = 0;                //입력받을 금액 변수 선언

    scanf("%d %d", &moneyCount, &money);
    pArray = makeArray(moneyCount);

	for (int i = 0; i < moneyCount; i++)
		scanf("%d", (pArray + i));

	count = countMoney(moneyCount, money, pArray);
	printf("%d\n", count);

	free(pArray);
	return 0;
}
