import java.io.IOException;
import java.util.*;

public class BeakJoon6378 
{
    public static void main(String[] args) throws IOException, NumberFormatException
	{
		 Scanner scan = new Scanner(System.in);  //스캐너 객체 선언 및 정의.
         String str;  //정수 값을 입력받을 문자열 객체 선언
		 
         while(!(str = scan.nextLine()).equals("0"))  //0을 입력할 때 까지 무한 루프 동작.
		 {
             String[] strArr = str.split("");  //str을 문자단위로 분해하여 String 배열에 각각 저장.
			 
			 if(strArr.length == 1);  //입력받은 숫자가 한 자리인 경우
			 else  //그 이상인 경우
			 {
	             while(strArr.length != 1)  //한 자리 정수가 될 때까지 반복.
				 {
	    			 int value = 0;
	    			 
					 for(int i = 0; i < strArr.length; i++)
					     value += Integer.parseInt(strArr[i]);  //value 값을 누적.
					 strArr = String.valueOf(value).split("");  //value 값을 한 숫자씩 분해하여 String 배열에 저장.
			     }
			 }
			
			 if(strArr[0] != "0")
				 System.out.println(strArr[0]);
		} 
        scan.close();
    }
}
