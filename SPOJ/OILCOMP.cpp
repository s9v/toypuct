#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define sz(X) (int)(X).size()
#define pb push_back
#define mp make_pair
#define dbg(X) cerr << #X << " : " << X << endl
#define dbg2(X) cerr << X << endl
using namespace std;

time_t st = clock();

const int MAXM = 19;

struct good {
	int msk1;
	int msk2;
	good(int msk1, int msk2) : msk1(msk1), msk2(msk2) {}
};

int n, m;
vector<int> goods;
vector<good> pairs;
int opt[2][1<<20];
int pcc[2][1<<20]; // precalc
int rsc[20][20]; // resource

void demi(int x, int msk)
{
	if (x == MAXM) {
		//~ cerr << "GOOD MASK : " << bitset<2>(msk) << endl;
		goods.pb(msk);
	}
	else {
		demi(x+1, msk);
		if (x == 0 || (msk&(1<<(x-1))) == 0)
			demi(x+1, msk|(1<<x));
	}
}

int main()
{
	int ntests;
	//~ cin >> ntests;
	scanf("%d", &ntests);
	
	demi(0, 0);
	
	for (int i = 0; i < sz(goods); i++)
	for (int j = i+1; j < sz(goods); j++)
	{
		int x = goods[i];
		int y = goods[j];
		
		if ((x&y) == 0)
			pairs.pb(good(x, y));
	}
	
	dbg(sz(goods));
	dbg(sz(pairs));
	
	//~ for (int i = 0; i < sz(pairs); i++)
		//~ cerr << bitset<MAXM>(pairs[i].msk1) << "\n" << bitset<MAXM>(pairs[i].msk2) << "\n\n";
	
	/*for (int i_test = 0; i_test < ntests; i_test++)
	{
		scanf("%d %d", &m, &n);
		//~ cin >> m;
		//~ cin >> n;
		
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			//~ cin >> rsc[i][j];
			scanf("%d", &rsc[i][j]);
		
		//~ dbg(sz(pairs));
		
		fill(pcc[0], pcc[2], 0);
		fill(opt[0], opt[2], 0);
		
		for (int i = 1; i <= n; i++)
		{
			for (int msk = 0; msk < (1<<m); msk++)
				for (int bit = 0; bit < m; bit++)
					pcc[i&1][msk] += ((msk&(1<<bit)) > 0)*rsc[i-1][bit];
			
			for (int j = 0; j < sz(pairs); j++)
			{
				int a = i&1;
				int x = pairs[j].msk2;
				int b = (i-1)&1;
				int y = pairs[j].msk1;
				
				//~ dbg(i);
				//~ cerr << "x --> " << bitset<2>(x) << endl;
				//~ cerr << "y --> " << bitset<2>(y) << endl;
				//~ dbg(opt[a][x]);
				//~ dbg(opt[b][y]);
				//~ dbg(pcc[a][x]);
				//~ cerr << endl;
				
				opt[a][x] = max(opt[a][x], opt[b][y] + pcc[a][x]);
			}
		}
		
		int res = 0;
		for (int msk = 0; msk < (1<<m); msk++)
			res = max(res, opt[n&1][msk]);
		
		printf("Case %d: %d\n", i_test+1, res);
		//~ cout << "Case " << i_test+1 << ": " << res << "\n";
	}*/
	
	cerr << endl << 1.0*(clock()-st)/CLOCKS_PER_SEC;
	while (1) getchar();
}
