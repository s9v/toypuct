// 1701. Ostap and Partners
// DSU solution

#include <iostream>
#include <cassert>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAXSETS = 50000+10;
struct DSU
{
	int par[MAXSETS];
	int mxd[MAXSETS];
	int dff[MAXSETS]; // wage[x] == wage[par[x]] - dff[x]
	
	void init(const int &n)
	{
		for (int i = 0; i < n; i++)
			par[i] = i;
	}
	void minion(int a, int b, int diff) // aaaaaargh [!] 
	{
		int x = findset(a);
		int y = findset(b);
		
		if (rand()&1)
		{
			swap(x, y);
			swap(a, b);
			diff *= -1;
		}
		
		par[y] = x;
		dff[y] = diff + (dff[a] - dff[b]);
		mxd[x] = max(mxd[x], mxd[y] + dff[y]);
	}
	int findset(const int &x) {
		int newpar = (par[x] == x ?x :findset(par[x]));
		dff[x] += dff[par[x]];
		return par[x] = newpar;
	}
};

int n, m;
DSU wset;

int main()
{
	srand((unsigned)time(NULL));
	
	cin >> n >> m;
	wset.init(n);
	
	for (int foo = 0; foo < m; foo++)
	{
		int a, b, diff;
		cin >> a >> b >> diff;
		
		if (wset.findset(a) == wset.findset(b))
		{
			if (wset.dff[b] - wset.dff[a] != diff)
			{
				cout << "Impossible after " << foo+1 << " statements";
				return 0;
			}
		}
		else
		{
			wset.minion(a, b, diff);
			
			int par0 = wset.findset(0);
			
			if (wset.mxd[par0] - wset.dff[0] != 0)
			{
				cout << "Impossible after " << foo+1 << " statements";
				return 0;
			}
		}
	}
	
	cout << "Possible\n";
	
	for (int i = 0, par; i < n; i++)
	{
		par = wset.findset(i);
		cout << wset.mxd[par] - wset.dff[i] << "\n";
		
		if (i == 0)
			assert(wset.mxd[par] - wset.dff[i] == 0);
	}
	
	return 0;
}
