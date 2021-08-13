/*
 * G - Gopher II
 * Hopcraft Karp
 * O(sqrt(V)*E)
 *
 * */

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct Point {
	double x, y;
	
	void read() {
		cin >> x >> y;
	}
	
	double dist(Point other) {
		return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
	}
};

int n, m;
double sec, vel;
int res;
Point goph[100];
Point hole[100];

int matchL[100];
int matchR[100];

bool vis[100];
int dist[100];

bool bfs() {
	fill(dist, dist+100, -1);
	queue<int> Q;
	
	for (int u = 0; u < n; u++)
		if (matchL[u] < 0) {
			dist[u] = 0;
			Q.push(u);
		}
	
	bool unmatched = false; // if there exists unmatched node at Right
	while ( ! Q.empty()) {
		int u = Q.front();
		Q.pop();
		
		for (int v = 0; v < m; v++)
			if (goph[u].dist(hole[v])/vel <= sec) {
				int w = matchR[v];

				if (w >= 0 && dist[w] < 0) {
					dist[w] = dist[u]+1;
					Q.push(w);
				}
				
				if (w < 0)
					unmatched = true;
			}
	}
	
	return unmatched;
}

bool dfs(int u) {
	for (int v = 0; v < m; v++)
		if (goph[u].dist(hole[v])/vel <= sec) {
			if (vis[v])
				continue;

			vis[v] = true;
			int w = matchR[v];

			if (w < 0 || (dist[w] == dist[u]+1 && dfs(w))) {
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}

	return false;
}

void bpm() {
	fill(matchL, matchL+100, -1);
	fill(matchR, matchR+100, -1);
	
	while (bfs()) {
		fill(vis, vis+100, 0);

		for (int u = 0; u < n; u++)
			if (matchL[u] < 0 && dfs(u))
				res++;
	}
}

int main()
{
	while (cin >> n) {
		cin >> m;
		cin >> sec;
		cin >> vel;
		
		res = 0;
		
		for (int i = 0; i < n; i++)
			goph[i].read();
		
		for (int i = 0; i < m; i++)
			hole[i].read();
		
		bpm();
		
		cout << n-res << "\n";
	}
	
	return 0;
}
