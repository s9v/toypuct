#include <iostream>
using namespace std;
typedef long long llint;

int n;
llint f[401][401];
llint g[401][401];

int main()
{
	cin >> n;
	
	f[0][0] = g[0][0] = 1;
	for (int s = 1; s <= n; s++)
	{
		f[0][s] = 0;
		g[0][s] = 1;
	}
	
	f[1][0] = g[1][0] = 0;
	f[1][1] = g[1][1] = 1;
	for (int s = 2; s <= n; s++)
	{
		f[0][s] = 0;
		g[0][s] = 1;
	}
	
	for (int r = 2; r <= n; r++)
	{
		f[r][0] = g[r][0] = 0;
		
		for (int s = 1; s <= n; s++)
		{
			f[r][s] = 0;
			
			for (int k = 1; k <= r; k++)
			{
				f[r][s] += f[k-1][s-1]*g[r-k][s-1];
				f[r][s] += g[k-1][s-1]*f[r-k][s-1];
				f[r][s] -= f[k-1][s-1]*f[r-k][s-1];
			}
			
			g[r][s] = g[r][s-1] + f[r][s];
		}
	}
	
	for (int r = 0; r <= n; r++)
	{
		for (int s = 0; s <= n; s++)
		{
			cerr << f[r][s] << " ";
		}
		cerr << "\n";
	}
	
	return 0;
}
