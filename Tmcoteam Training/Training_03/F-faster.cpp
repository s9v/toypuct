#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define  space(x)	for (int i = 0; i < x; i++) cerr << " "
using namespace std;

int m, n;
int blue[500];
int red[500];

int dist[500];
int matchL[500];
int matchR[500];
bool vis[500];
int par[500];

bool bfs() {
	fill(dist, dist+500, -1);
	fill(par, par+500, -1);
	queue<int> Q;

	for (int u = 0; u < m; u++)
		if (matchL[u] < 0) {
			dist[u] = 0;
			Q.push(u);
		}

	bool unmatched = false;
	while ( ! Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (int v = 0; v < n; v++)
			if (__gcd(blue[u], red[v]) > 1) {
				int w = matchR[v];

				if (w >= 0 && dist[w] < 0) {
					dist[w] = dist[u] + 1;
					par[w] = u;
					Q.push(w);
				}

				if (w < 0)
					unmatched = true;
			}
	}

	return unmatched;
}

bool dfs(int u) {
	vis[u] = true;
	
	for (int v = 0; v < n; v++)
		if (__gcd(blue[u], red[v]) > 1) {
			int w = matchR[v];
			
			if (w < 0 || (!vis[w] && dist[w] == dist[u]+1 && dfs(w))) {
				matchR[v] = u;
				matchL[u] = v;
				return true;
			}
		}
	
	return false;
}

int hopcroft_karp() {
	fill(matchL, matchL+500, -1);
	fill(matchR, matchR+500, -1);
	
	int ret = 0;
	while (bfs()) {
		fill(vis, vis+500, 0);
		
		for (int u = 0; u < m; u++)
			if (matchL[u] < 0 && dfs(u))
					ret++;
	}
	
	return ret;
}

int main() {
	
	while (true) {
		scanf("%d %d", &m, &n);
		
		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < m; i++)
			scanf("%d", &blue[i]);
		
		for (int i = 0; i < n; i++)
			scanf("%d", &red[i]);
		
		printf("%d\n", hopcroft_karp());
	}
	
	return 0;
}
