import java.io.IOException;
import java.util.*;

public class BeakJoon6378 
{
    public static void main(String[] args) throws IOException, NumberFormatException
	{
		 Scanner scan = new Scanner(System.in);  //��ĳ�� ��ü ���� �� ����.
         String str;  //���� ���� �Է¹��� ���ڿ� ��ü ����
		 
         while(!(str = scan.nextLine()).equals("0"))  //0�� �Է��� �� ���� ���� ���� ����.
		 {
             String[] strArr = str.split("");  //str�� ���ڴ����� �����Ͽ� String �迭�� ���� ����.
			 
			 if(strArr.length == 1);  //�Է¹��� ���ڰ� �� �ڸ��� ���
			 else  //�� �̻��� ���
			 {
	             while(strArr.length != 1)  //�� �ڸ� ������ �� ������ �ݺ�.
				 {
	    			 int value = 0;
	    			 
					 for(int i = 0; i < strArr.length; i++)
					     value += Integer.parseInt(strArr[i]);  //value ���� ����.
					 strArr = String.valueOf(value).split("");  //value ���� �� ���ھ� �����Ͽ� String �迭�� ����.
			     }
			 }
			
			 if(strArr[0] != "0")
				 System.out.println(strArr[0]);
		} 
        scan.close();
    }
}
