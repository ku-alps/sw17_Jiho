import java.io.IOException;
import java.util.Scanner;

public class BeakJoon1120 
{
    public static void main(String[] args) throws IOException
    {
        //변수 선언부
    	String str1 = new String();
	String str2 = new String();
	Scanner scan = new Scanner(System.in);
	//String 객체에 문자열 입력
	str1 = scan.next();
	str2 = scan.next();
        
	int max_sameCount = 0; //String 객체 간 최대로 겹치는 문자의 갯수
	//문자열 비교 코드
	for(int i = 0; i < str2.length() - str1.length() + 1; i++)
	{
		int sameCount = 0; //String 객체 간 겹치는 문자의 갯수
		String subStr = str2.substring(i, i + str1.length()); //str2의 부분문자열
		//str1과 부분문자열을 비교
		for(int j = 0; j < subStr.length(); j++)
		    if(str1.charAt(j) == subStr.charAt(j))
			sameCount++;
			
		if(sameCount > max_sameCount)
		    max_sameCount = sameCount;
	}
		
	System.out.println(str1.length() - max_sameCount);  //str1 길이에서 최대로 겹치는 수를 뺀 것이 차잇값.
	scan.close();
    }
}
