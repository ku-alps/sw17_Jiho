#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char cArray[1000];           //���ڸ� �Է¹��� ���� �迭 ����
	int strLength;               //���ڿ��� ����

	do
	{
		scanf("%s", cArray);     
		strLength = strlen(cArray);   //���ڿ��� ���� ����.

		if (strLength == 1);     

		else
		{
			while (strLength != 1)   //���ڿ��� ���̰� 1��(���ڸ� ����) �� ������ �ݺ�.
			{
				int value = 0;
				for (int i = 0; i < strLength; i++)
					value += (cArray[i] - '0');  //�� ���ڸ� ������ ��ȯ�� ����.

				itoa(value, cArray, 10);   //���� ���� ���ڿ��� ��ȯ.
				strLength = strlen(cArray);
			}
		}
        
		if(cArray[0] != '0')        //���� ���� 0�� �ƴ� ��� ���� ���.
		    printf("%s\n", cArray);
	} while (cArray[0] != '0');
	
	return 0;
}