import java.util.*;
import java.io.IOException;

public class BaekJoon4386
{
    protected static Scanner scan = null;
    
	public static void main(String[] args) throws IOException, NumberFormatException
	{
		int count = scan.nextInt();
		HashMap<Double, Double> hash = new HashMap<Double, Double>();
        double[][] vertexArray = new double[count][2];
        
        for(int i = 0; i < count; i++)
        {
        	vertexArray[i][0] = scan.nextDouble();
        	vertexArray[i][1] = scan.nextDouble();
        }
        
        for(int i = 0; i < count - 1; i++)
        {
        	ArrayList<Double> resultList = new ArrayList<Double>();
        	for(int j = i; j < count; j++)
        	{
        		double differXY = FindDifferXY(vertexArray[i][0], vertexArray[j][0], vertexArray[i][0], vertexArray[j][1]);
        		resultList.add(differXY);
        		double minValue = Collections.min(resultList);
        		int index = resultList.indexOf(minValue);
        		double key = CutfloatNum(CutfloatNum(vertexArray[index+1][0] + CutfloatNum(vertexArray[index+1][1])));
        		hash.put(key, minValue);
        	}
        	
        	resultList = null;
        }
        
        Set<Double> keys = hash.keySet();
        Iterator<Double> it = keys.iterator();
        double result = 0;
        
        while(it.hasNext())
        {
            Double key = it.next();
            result = CutfloatNum(result + hash.get(key));
        }
        
        System.out.println(result);
        hash = null;
	}

	public static double FindDifferXY(double x1, double x2, double y1, double y2)
	{
		double differX = CutfloatNum(Math.abs(x2 - x1));
		double differY = CutfloatNum(Math.abs(y2 - y1));
		double differXY = CutfloatNum(Math.sqrt(Math.pow(differX, 2) + Math.pow(differY, 2)));
		return differXY;
	}
	
	public static double CutfloatNum(double num)
	{
		num *= 100;
		double realnum = (int)num / 100.0;
		return realnum;
	}
}