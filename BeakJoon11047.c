#include <stdio.h>
#include <stdlib.h>

int* makeArray(int moneyCount)              //������ ��ġ�� �Է¹��� int �迭 �����Ҵ��ϴ� �Լ�
{
	int* moneyArray = NULL;

	if (moneyCount >= 1)
	     moneyArray = (int*)calloc(moneyCount, sizeof(int));

	return moneyArray;
}

int countMoney(int moneyCount, int money, int* pArray)           //�ּҷ� �ʿ��� ������ ������ ����ϴ� �Լ�
{
	int count = 0;
	
	if (pArray != NULL)                                          //��ȿ�� �˻�(�Ű�����)
	{
		if (moneyCount > 0 && money > 0)                         //��ȿ�� �˻�(�Ű�����)
		{
			int i;
			for (i = moneyCount - 1; i >= 0; i--)
			{
				count += money / pArray[i];
				money %= pArray[i];
			}
		}

		else
			printf("������ ������ �Է��� �ݾ��� ���� �������� Ȯ���ϼ���.\n");
	}

	else
		printf("��ȿ�� �迭�� �ƴմϴ�.\n");

	return count;
}

int main(int argc, char* argv[])
{
	int* pArray = NULL;           //int �迭�� �����Ҵ� ���� ���� ����
	int moneyCount, count = 0;    //������ ���� �� ���� ������ �ּڰ� ���� ����
	int money = 0;                //�Է¹��� �ݾ� ���� ����

    scanf("%d %d", &moneyCount, &money);
    pArray = makeArray(moneyCount);

	for (int i = 0; i < moneyCount; i++)
		scanf("%d", (pArray + i));

	count = countMoney(moneyCount, money, pArray);
	printf("%d\n", count);

	free(pArray);
	return 0;
}
