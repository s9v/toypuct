import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;

public class C
{
	public static void main(final String args[]) throws IOException
	{
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int k = in.nextInt();
		int w = in.nextInt();
		
		int ps[][] = new int[10][100010];
		
		String v = in.next();
		
		for (int i = 0; i < n; i++)
			ps[i%k][i/k+1] = ps[i%k][i/k] + (v.charAt(i) == '1' ?1 :0);
		
		for (int test = 0; test < w; test++)
		{
			int l = in.nextInt();
			int r = in.nextInt();
			l--;
			r--;
			int res = 0;
			
			for (int i = 1; i < k; i++)
				res += ps[(r-k+i)%k][(r-k+i)/k+1] - ps[(l+i-1)%k][(l+i-1)/k+1] + (v.charAt(l+i-1) == '1' ?1 :0);
			
			res += (r-l+1)/k;
			res -= ps[r%k][r/k+1] - ps[(l+k-1)%k][(l+k-1)/k+1] + (v.charAt(l+k-1) == '1' ?1 :0);
			
			System.out.println(res);
		}
	}
}
