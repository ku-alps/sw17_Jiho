#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char cArray[1000];           //숫자를 입력받을 문자 배열 선언
	int strLength;               //문자열의 길이

	do
	{
		scanf("%s", cArray);     
		strLength = strlen(cArray);   //문자열의 길이 측정.

		if (strLength == 1);     

		else
		{
			while (strLength != 1)   //문자열의 길이가 1이(한자리 숫자) 될 때까지 반복.
			{
				int value = 0;
				for (int i = 0; i < strLength; i++)
					value += (cArray[i] - '0');  //각 문자를 정수로 변환해 누적.

				itoa(value, cArray, 10);   //정수 값을 문자열로 변환.
				strLength = strlen(cArray);
			}
		}
        
		if(cArray[0] != '0')        //정수 값이 0이 아닐 경우 값을 출력.
		    printf("%s\n", cArray);
	} while (cArray[0] != '0');
	
	return 0;
}