import java.util.*;

public class BeakJoon9375
{
    protected static Scanner scan = null;      //�Է¹��� ��ĳ�� ��ü ����.
	
	public static void main(String[] args)
	{
		scan = new Scanner(System.in);
        
		int testcase = scan.nextInt();
		   //�ǻ��� �� ������ �Է�.
		int i, j;
		
		for(i = 0; i < testcase; i++)       //�ǻ��� �� ������ŭ HashMap�� ���� �����ϴ� ���� �ݺ�.
		{
			HashMap<String, Integer> hash = new HashMap<>();  //HashMap ��ü ����.(���� ����, �̸� ���� ������ ������ ���� �ߺ��� �ȵǹǷ� �� �ڷᱸ���� ����.)
			int clothNumber = scan.nextInt();   
			
			for(j = 0; j < clothNumber; j++)
			{
				String clothName = scan.next();
			    String clothType = scan.next();
			
			    if(hash.containsKey(clothType))
			    {
				    int clothTypeCount = hash.get(clothType);
				    hash.put(clothType, clothTypeCount + 1);
			    }
			
			    else
			        hash.put(clothType, 1);
			}
			
			//HashMap�� ��ȸ�� ���� Set, Iterator ��ü ����
			Set<String> keys = hash.keySet(); 
			Iterator<String> it = keys.iterator();
			
			int possibleday = 1;         //�������� ��� �ִ� �ϼ� ����.
			
			/* ����ڷκ��� �� ������ �� ������ �Է¹����� �𸣹Ƿ�, ����� ���� ã�� ��� ���
			      ���غ��� ���� �� �ִ� �ǻ��� ��� ��츦 ���� �� , �������� ��� ���� �� ���� ��츦 ��.
			 */
			while(it.hasNext())
			{
				String key = it.next();
				possibleday *= (hash.get(key) + 1);   //+1�� �ش� �ǻ� ������ �� �Դ� ��쵵 ����Ѵٴ� �ǹ�.
			}
			
			System.out.println(possibleday - 1);
		}
    }
}
