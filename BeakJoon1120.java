import java.io.IOException;
import java.util.Scanner;

public class BeakJoon1120 
{
    public static void main(String[] args) throws IOException
	{
		//���� �����
    	String str1 = new String();
		String str2 = new String();
		Scanner scan = new Scanner(System.in);
		//String ��ü�� ���ڿ� �Է�
		str1 = scan.next();
		str2 = scan.next();
        
		int max_sameCount = 0; //String ��ü �� �ִ�� ��ġ�� ������ ����
		//���ڿ� �� �ڵ�
		for(int i = 0; i < str2.length() - str1.length() + 1; i++)
		{
			int sameCount = 0; //String ��ü �� ��ġ�� ������ ����
			String subStr = str2.substring(i, i + str1.length()); //str2�� �κй��ڿ�
			//str1�� �κй��ڿ��� ��
			for(int j = 0; j < subStr.length(); j++)
				if(str1.charAt(j) == subStr.charAt(j))
					sameCount++;
			
			if(sameCount > max_sameCount)
				max_sameCount = sameCount;
		}
		
		System.out.println(str1.length() - max_sameCount);  //str1 ���̿��� �ִ�� ��ġ�� ���� �� ���� ���հ�.
		scan.close();
	}
}
