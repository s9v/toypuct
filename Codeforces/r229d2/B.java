import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;

public class B
{
	public static void main(final String args[]) throws IOException
	{
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		long a[] = new long[100000];
		long b[] = new long[100000];
		
		for (int i = 0; i < n; i++)
			a[i] = in.nextLong();
		
		for (int i = 0; i < n; i++)
			b[i] = in.nextLong();
		
		long res = 0;
		for (int i = 0; i < n; i++)
		{
			if (b[i] != 1 && (b[i]+1)/2 <= a[i])
				res += ((b[i]+1)/2) * (b[i]/2);
			else
				res--;
		}
		
		System.out.print(res);
	}
}
