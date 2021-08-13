/*
 * Maximum Bipartite Matching
 * 
 * TIP:
 * In this code u, v and w variables are used for:
 * u --> v --> w
 * 
 * */

#include <algorithm>
#include <iostream>
#include <queue>
#define  

using namespace std;

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2;
int res;
vector<int> gr[MAXN1];

int matching[MAXN2];
int dist[MAXN1];

bool matched[MAXN1];
bool vis[MAXN1];

void bfs() {
	fill(dist, dist + n1, -1);
	queue<int> Q;
	
	for (int u = 0; u < n1; ++u)
		if (!matched[u]) {
			Q.push(u);
			dist[u] = 0;
		}
	
	while ( ! Q.empty()) {
		int u = Q.front();
		Q.pop();
		
		for (int i = 0; i < sz(gr[u]); i++) {
			int v = gr[u][i];
			int w = matching[v];
			
			if (w >= 0 && dist[w] < 0) {
				dist[w] = dist[u] + 1;
				Q.push(w);
			}
		}
	}
}

bool dfs(int u) {
	vis[u] = true;
	
	for (int i = 0; i < sz(gr[u]); i++) {
		int v = gr[u][i];
		int w = matching[v];
		
		if (w < 0 || (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {
			matching[v] = u;
			matched[u] = true;
			return true;
		}
	}
	
	return false;
}

void bpm() {
	fill(matched, matched + n1, false);
	fill(matching, matching + n2, -1);
	
	while (1) {
		bfs();
		fill(vis, vis + n1, false);
		
		int f = 0;
		for (int u = 0; u < n1; u++)
			if ( ! matched[u] && dfs(u))
				f++;
		
		res += f;
		
		if (f == 0)
			break;
	}
}

int main() {
	cin >> n1;
	cin >> n2;
	
	for (int u = 0; u < n1; u++) {
		int x;
		cin >> x;
		
		for (int i = 0; i < x; i++) {
			int v;
			cin >> v;
			gr[u].push_back(v);
		}
	}
	
	bpm();
	cout << "max matching : " << res;
}
