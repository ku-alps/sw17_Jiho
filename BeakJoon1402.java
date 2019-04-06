import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;

public class BeakJoon1402 
{
    public static void main(String[] args) throws IOException
    {
		Scanner scan = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        
        int testcase = scan.nextInt();
        Integer Sourcevalue = Integer.parseInt(scan.next());
        Integer Goalvalue = Integer.parseInt(scan.next());
        int sourcevalue = Sourcevalue.intValue();
        
        for(int i = 0; i < testcase; i++)
        {
        	int divisor = 2;
        	while(sourcevalue != 1)
        	{
        		while(divisor <= sourcevalue)
        	    {
        		  if(sourcevalue % divisor == 0)
        		  {
        			  sourcevalue /= divisor;
        			  arr.add((Integer)divisor);
        		  }
        		  
        		  else
        			  divisor++;
        	    }
        	}
        	
        	int addResult = 0;
        	for(int j = 0; j < arr.size(); j++)
        	    addResult += arr.get(j).intValue();
        	
        	if(addResult == Goalvalue.intValue())
        		System.out.println("yes");
        	else
        		System.out.println("no");
        }
        
        scan.close();
	}
}
