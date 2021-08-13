/*
 * Strongly Connected Components
 * 
 * */

#include <iostream>
#include <algorithm>
#include <functional>
#define  sz(X)    (int)X.size()
using namespace std;
typedef vector<int> vi;

vi g[1000000];
vi gr[1000000];
vi ord;
vi res;
int cnt;
bool vis[1000000];
int V, E;

void dfs1(int nd) {
	vis[nd] = 1;
	for (int i = 0; i < sz(g[nd]); i++) {
		int to = g[nd][i];
		
		if (vis[to]) continue;
		
		dfs1(to, nd);
	}
	
	ord.push_back(nd);
}

void dfs2(int nd, int pr = -1) {
//	cerr << nd+1 << " ";
	vis[nd] = 1;
	cnt++;
	
	for (int i = 0; i < sz(gr[nd]); i++) {
		int to = gr[nd][i];
		
		if (to == pr || vis[to]) continue;
		
		dfs2(to, nd);
	}
}

int main() {
	cin >> V;
	cin >> E;
	
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	
	for (int i = 0; i < V; i++)
		if ( ! vis[i])
			dfs1(i);
	
	fill(vis, vis+V, 0);
	
	for (int i = sz(ord)-1; i >= 0; i--)
		if ( ! vis[ord[i]]) {
			cnt = 0;
			dfs2(ord[i]);
			res.push_back(cnt);
//			cerr << " <-- C\n";
		}
	
	sort(res.begin(), res.end(), greater<int>());
	
	cout << sz(res) << "\n";
	
	for (int i = 0; i < sz(res); i++)
		cout << res[i] << "\n";
	
	return 0;
}
