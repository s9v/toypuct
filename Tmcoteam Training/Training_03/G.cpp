/*
 * G - Gopher II
 * Bipartite Matching
 * O(V*E)
 *
 * */

#include <iostream>
#include <cmath>
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

bool bpm(int u)
{
	for (int v = 0; v < m; v++)
		if (goph[u].dist(hole[v])/vel <= sec) {
			if (vis[v])
				continue;
			
			vis[v] = true;
			
			if (matchR[v] < 0 || bpm(matchR[v])) {
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
	
	return false;
}

int main()
{
	while (cin >> n) {
		cin >> m;
		cin >> sec;
		cin >> vel;
		
		res = n;
		
		for (int i = 0; i < n; i++)
			goph[i].read();
		
		for (int i = 0; i < m; i++)
			hole[i].read();
		
		fill(matchL, matchL+100, -1);
		fill(matchR, matchR+100, -1);
		
		for (int i = 0; i < n; i++) {
			fill(vis, vis+100, 0);
			
			if (bpm(i))
				res--;
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
