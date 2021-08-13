#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
                  
#include <functional>
#include <limits>
#include <numeric>
#include <complex>

#include <cassert>
#include <cmath>
#include <cmemory>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())

const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

const int N = 2000;

int n, m, mt[N], used[N], u;

vector<pt> edges;
vector<int> g[N];

bool read() {
	if (scanf("%d %d", &n, &m) != 2)
		return false;
    
    forn(i, m) {
		int u, v;
		assert(scanf("%d %d", &u, &v) == 2);
		u--, v--;
		edges.pb(mp(u, v));
	}

    return true;
}                            

inline bool kuhn(int s) {
 	if (used[s] == u)
 		return false;
 	used[s] = u;
 	forn(i, sz(g[s])) {
 	 	int to = g[s][i];
 	 	if (mt[to] == -1 || kuhn(mt[to])) {
 	 	 	mt[to] = s;
 	 	 	return true;
 	 	}
 	}

 	return false;
}

void solve() {
	int tans = INF;
	
	forn(it, n)
	{
		int cnt = 0;
		int ans = 0;
		int other = 0;
		
		forn(j, n)
			g[j].clear(), mt[j] = -1;
		
		forn(j, m)
		{
			if (edges[j].ft == it || edges[j].sc == it)
				cnt++;
			
			else
			{
			 	g[edges[j].ft].pb(edges[j].sc);
			 	other++;
			}
		}
		
		forn(i, n)
		{
		 	u++;
		 	kuhn(i);
		}

		int tsz = 0;

		forn(i, n)
			if (mt[i] != -1)
				tsz++;

		ans += 2 * (n - 1) + 1 - cnt + other - tsz + (n - 1) - tsz;
		
		tans = min(tans, ans);
	}

	cout << tans << endl;              
}

int main()
{

#ifdef gridnevvvit
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	
	assert(read());
	solve();
	
	// cerr << clock() << endl;
}
