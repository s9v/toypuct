#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#define  sz(X)	(int)X.size()
using namespace std;

int n, f, d;
int res;
int source;
int sink;
int cost[400][400];
int flow[400][400];

vector<int> gr[400];

bool vis[400];
int par[400];

void flood() {
	while (1) {
		fill(vis, vis+400, 0);
		fill(par, par+400, -1);
		queue<int> q;
		q.push(source);
		vis[source] = 1;
		par[source] = source;
		
		while ( ! q.empty()) {
			int u = q.front();
			q.pop();
			
			for (int i = 0; i < sz(gr[u]); i++) {
				int v = gr[u][i];
				
				if (vis[v])
					continue;
				
				if (cost[u][v]-flow[u][v] > 0) {
					par[v] = u;
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		
		if (par[sink] == -1)
			return;
		
		int curflow = 1000000000;
		for (int v = sink; v != source ; v = par[v]) {
			int u = par[v];
			curflow = min(curflow, cost[u][v]-flow[u][v]);
		}
		
		for (int v = sink; v != source ; v = par[v]) {
			int u = par[v];
			flow[u][v] += curflow;
			flow[v][u] -= curflow;
		}
		
		res += curflow;
	}
}

int main()
{
	cin >> n >> f >> d;
	
	for (int i = 1; i <= n; i++) {
		int fi, di;
		cin >> fi >> di;
		
		/*
		assert(fi > 0);
		assert(di > 0);
		*/
		
		for (int j = 0; j < fi; j++) {
			int fid;
			cin >> fid;
			if (cost[fid][f+i] == 0)
				gr[fid].push_back(f+i);
			cost[fid][f+i] = 1;
		}
		
		for (int j = 0; j < di; j++) {
			int did;
			cin >> did;
			if (cost[f+i][f+n+did] == 0)
				gr[f+i].push_back(f+n+did);
			cost[f+i][f+n+did] = 1;
		}
		
		//cerr << "done.\n";
	}
	
//	cerr << "all done.";
	
	source = 0;
	sink = f+d+n+1;
	for (int i = 1; i <= f; i++) {
		gr[source].push_back(i);
		cost[source][i] = 1;
	}
	for (int i = 1; i <= d; i++) {
		gr[f+n+i].push_back(sink);
		cost[f+n+i][sink] = 1;
	}
		
	flood();
	
	cout << res << "\n";
	
	return 0;
}
