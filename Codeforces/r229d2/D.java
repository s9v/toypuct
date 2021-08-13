import java.io.IOException;
<<<<<<< HEAD
import java.util.*;
import java.math.*;
=======
import java.util.Scanner;
import java.util.*;
import java.math.BigInteger;
>>>>>>> 0af8961ec5948623f1ee4de948de5b9adbcc5859

public class D
{
	public static void main(final String args[]) throws IOException
	{
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		int res = 0;
		
		int dir[][] = {
			{+0,-1},
			{+0,+1},
			{-1,+0},
			{+1,+0}
		};
		
		int pnt[][] = new int[50*50][3]; // x, y, dt
		int pnts = 0;
		int dt[][] = new int[50][50];
		int pr[][][] = new int[50][50][2]; // x, y
		
		int q[][] = new int[50*50][2];
		int qtail = 0;
		int qhead = 0;
		
		q[qhead][0] = 0;
		q[qhead][1] = 0;
		qhead++;
		
		dt[0][0] = 1;
		res += dt[0][0];
		pr[0][0][0] = -1;
		pr[0][0][1] = -1;
		pnt[pnts][0] = 0;
		pnt[pnts][1] = 0;
		pnt[pnts][2] = dt[0][0];
		pnts++;
		
		while (qtail < qhead && pnts < k)
		{
			int x = q[qtail][0];
			int y = q[qtail][1];
			
			for (int o = 0; o < 4; o++)
			{
				int nx = x+dir[o][0];
				int ny = y+dir[o][1];
				
				if (0 <= nx && nx <= n-1 && 0 <= ny && ny <= m-1 && dt[nx][ny] == 0)
				{
					q[qhead][0] = nx;
					q[qhead][1] = ny;
					qhead++;
					
					dt[nx][ny] = dt[x][y]+1;
					res += dt[nx][ny];
					pr[nx][ny][0] = x;
					pr[nx][ny][1] = y;
					pnt[pnts][0] = nx;
					pnt[pnts][1] = ny;
					pnt[pnts][2] = dt[nx][ny];
					pnts++;
					
					if (pnts == k)
						break;
				}
			}
			
			qtail++;
		}
		
		Arrays.sort(pnt, 0, k, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o2[2], o1[2]);
			}
		});
		
		/*
		for (int i = 0; i < k; i++)
			System.err.println((pnt[i][0]+1) + " " + (pnt[i][1]+1) + " " + pnt[i][2]);
		*/
		
		System.out.println(res);
		
		int tmp[][] = new int[50*50][2];
		int tmps;
		
		for (int i = 0; i < k; i++)
		{
			int x = pnt[i][0];
			int y = pnt[i][1];
			
			tmps = 0;
			
			while (x != -1 && y != -1)
			{
				//System.err.print("(" + (x+1) + "," + (y+1) + ")" + " ~ ");
				
				tmp[tmps][0] = x+1;
				tmp[tmps][1] = y+1;
				tmps++;
				
				int nx = pr[x][y][0];
				int ny = pr[x][y][1];
				x = nx;
				y = ny;
			}
			//System.err.println();
			
			for (int j = tmps-1; j >= 0; j--)
				System.out.print("(" + tmp[j][0] + "," + tmp[j][1] + ")" + " ");
			System.out.println();
		}
	}
}
