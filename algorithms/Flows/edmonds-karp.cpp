/*
 * e-maxx.ru
 * Maximum Flow / Edmonds-Karp / O(N*M^2)
 * Modified by : Sylap Aliyev
 * Date : 10 Dec 2013
 * */

#include <iostream>
#include <queue>
using namespace std;
const int INF = 1e9;

int c[1000][1000];
int f[1000][1000];
int par[1000]; // parent in aug-path

int main()
{
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> c[i][j];
	
	// source = 0, sink = n-1
	
	while (true) { // till there is no aug-path
		fill(par, par+n, -1);
		
		queue<int> q;
		q.push(0);
		par[0] = 0;
		
		while (!q.empty()) { // bfs
			int u = q.front(); q.pop();
			
			for (int v = 0; v < n; v++)
				if (par[v] == -1 && c[u][v]-f[u][v] > 0) {
					q.push(v);
					par[v] = u;
				}
		}
		
		if (par[n-1] == -1) // <source> unreachable from <sink>
			break;
		
		int curflow = INF;
		for (int v = n-1; v != 0; ) {
			int u = par[v];
			curflow = min(curflow, c[u][v]-f[u][v]);
			v = u;
		}
		
		for (int v = n-1; v != 0; ) {
			int u = par[v];
			f[u][v] += curflow;
			f[v][u] -= curflow;
			v = u;
		}
	}
	
	int maxflow = 0;
	for (int i=0; i<n; i++)
		if (c[0][i])
			maxflow += f[0][i];
	
	cout << maxflow;
}
