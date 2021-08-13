/*
 * F - Cards
 * Bipartite Matching
 * O(T*V*E)
 * This solution TLEs :)
 *
 * */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;

int m, n, res;
int b[500];
int r[500];

int vis[500];
int matchR[500];

bool bpm(int u) {
	for (int v = 0; v < n; v++)
	if (__gcd(b[u], r[v]) > 1) {
		if (vis[v])
			continue;
		
		vis[v] = true;
		
		if (matchR[v] < 0 || bpm(matchR[v])) {
			matchR[v] = u;
			return true;
		}
	}
	
	return false;
}

int main()
{
	while (true) {
		cin >> m;
		cin >> n;
		
		if (m == 0 || n == 0)
			break;
		
		for (int i = 0; i < m; i++)
			cin >> b[i];
		
		for (int i = 0; i < n; i++)
			cin >> r[i];
		
		fill(matchR, matchR+500, -1);
		
		res = 0;
		for (int u = 0; u < m; u++) {
			fill(vis, vis+500, 0);
			
			if (bpm(u))
				res++;
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
