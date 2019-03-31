import java.util.*;

public class BeakJoon9375
{
    protected static Scanner scan = null;      //입력받을 스캐너 객체 선언.
	
	public static void main(String[] args)
	{
		scan = new Scanner(System.in);
        
		int testcase = scan.nextInt();
		   //의상의 총 개수를 입력.
		int i, j;
		
		for(i = 0; i < testcase; i++)       //의상의 총 개수만큼 HashMap에 값을 매핑하는 동작 반복.
		{
			HashMap<String, Integer> hash = new HashMap<>();  //HashMap 객체 생성.(옷의 종류, 이름 간에 정해진 순서가 없고 중복이 안되므로 이 자료구조를 선택.)
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
			
			//HashMap의 순회를 위한 Set, Iterator 객체 생성
			Set<String> keys = hash.keySet(); 
			Iterator<String> it = keys.iterator();
			
			int possibleday = 1;         //문제에서 물어본 최대 일수 변수.
			
			/* 사용자로부터 몇 가지의 옷 종류를 입력받을지 모르므로, 경우의 수를 찾는 방법 대신
			      신해빈이 입을 수 있는 의상의 모든 경우를 구한 후 , 공집합인 모든 옷을 안 입은 경우를 뺌.
			 */
			while(it.hasNext())
			{
				String key = it.next();
				possibleday *= (hash.get(key) + 1);   //+1은 해당 의상 종류를 안 입는 경우도 고려한다는 의미.
			}
			
			System.out.println(possibleday - 1);
		}
    }
}
