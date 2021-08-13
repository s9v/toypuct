import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;

public class A
{
	public static void main(final String args[]) throws IOException
	{
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int sumr = 0;
		int sumc = 0;
		int Row[] = new int[200];
		int Col[] = new int[200];
		
		for (int i = 0; i < n; i++)
		{
			int x = in.nextInt();
			int y = in.nextInt();
			
			Row[x] = 1;
			Col[y] = 1;
		}
		
		for (int i = 0; i < 200; i++)
			sumr += Row[i];
		
		for (int i = 0; i < 200; i++)
			sumc += Col[i];
		
		System.out.print(Math.min(sumr, sumc));
	}
}
