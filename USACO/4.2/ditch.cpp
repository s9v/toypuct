/*
ID: merdank1
LANG: C++
PROB: ditch
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#define  sz(X)		(int)X.size()
#define  DBG(vari)	cerr<<#vari<<" = "<<(vari)<<endl;
using namespace std;
typedef vector<int> vi;
const int LRG = 1e9; // LARGE NUMBER

int n, m;
vi g[200];
int c[200][200];
int f[200][200];
int par[200];

int edikarp() {
	int source = 0;
	int sink = m-1;
	
	while (true) { // till there is no aug-path
		fill(par, par+m, -1);
		
		queue<int> q;
		q.push(source);
		par[source] = source;
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			
			for (int i = 0; i < sz(g[u]); i++) {
				int v = g[u][i];
				
				if (par[v] == -1 && c[u][v]-f[u][v] > 0) {
					q.push(v);
					par[v] = u;
				}
			}
		}
		
		if (par[sink] == -1)
			break;
		
		int curflow = LRG;
		for (int v = sink; v != source ; v = par[v])
			curflow = min(curflow, c[ par[v] ][v] - f[ par[v] ][v]);
		
		for (int v = sink; v != source ; v = par[v]) {
			f[ par[v] ][v] += curflow;
			f[v][ par[v] ] -= curflow;
		}
	}
	
	int maxflow = 0;
	for (int i = 0; i < sz(g[source]); i++)
		if (c[source][ g[source][i] ] > 0)
			maxflow += f[source][ g[source][i] ];
	
	return maxflow;
}

int main() {
	ifstream fin("ditch.in");
	ofstream fout("ditch.out");
	
	fin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int a, b, cap;
		fin >> a >> b >> cap;
		a--; b--;
		
		if (c[a][b] == 0) {
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		c[a][b] += cap;
	}
	
	fout << edikarp() << "\n";
	
	return 0;
}
