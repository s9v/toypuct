import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;

public class timus1513
{
	public static void main(final String args[]) throws IOException
	{
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int k = in.nextInt();
		BigInteger dp[] = new BigInteger[30000];
		BigInteger sum = new BigInteger("1");
		BigInteger res = new BigInteger("0");
		
		for (int i = 0; i < 30000; i++)
			dp[i] = new BigInteger("0");
		dp[k] = new BigInteger("1");
		
		for (int i = 1; i <= n; i++)
		{
			dp[k+i] = sum;
			
			sum = sum.add(dp[k+i]);
			sum = sum.add(dp[i-1].negate());
		}
		
		for (int i = 0; i <= k; i++)
			res = res.add(dp[n+i]);
		
		System.out.print(res.toString());
	}
}
