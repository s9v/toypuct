#include <iostream>
#include <functional>
#include <algorithm>
#include <cassert>
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
using namespace std;

int n;
int k;
int dyn[510][510];
int par[510][510];
int val[510][510];
int ppl[510][510];

int main()
{
	fill(par[0], par[510], -1);
	
	cin >> n;
	cin >> k;
	
	fora (i, 1, n-1)
		fora (j, i+1, n)
			cin >> ppl[i][j];
	
	forb (i, n, 2)
	{
		val[i][i] = 0;
		
		forb (j, i-1, 1)
		{
			val[j][i] = val[j+1][i];
			
			fora (h, i, n)
				val[j][i] += ppl[j][h];
		}
	}
	
	fora (i, 2, n)
	{
		dyn[i][1] = val[1][i];
		fora (j, 2, min(i-1, k))
		{
			forb (h, i-1, j)
			{
				if (dyn[i][j] < dyn[h][j-1] + val[h][i])
				{
					dyn[i][j] = dyn[h][j-1] + val[h][i];
					par[i][j] = h;
				}
			}
		}
	}
	
	int res = 0;
	int resi = -1;
	
	fora (i, 1, n)
	if (res < dyn[i][k]) {
		res = dyn[i][k];
		resi = i;
	}
	
	cout << res << "\n";
	
	int cur = resi;
	forb (i, k, 1)
	{
		cout << cur << " ";
		assert(cur != -1);
		cur = par[cur][i];
	}
	
	return 0;
}
