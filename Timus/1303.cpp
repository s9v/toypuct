#include <iostream>
#include <algorithm>

using namespace std;

const int INF = (int)1e8;

struct point {
	int x, y;
};

struct info {
	int y, i;
};

struct recun {
	int u, p;
};

int m;
int dp[5010];
int out[5010]; int nout;
point points[100010]; int npts;
info infos[5010];
recun pr[5010];

bool cmpspec(int a, int b) {
	return points[a].x < points[b].y;
}

int main() {
	cin >> m;
	
	for (int i = 0; i < 5010; i++)
		infos[i].y = -INF;
	
	fill(dp, dp+5010, INF);
	
	int etcx, etcy;
	while (1) {
		cin >> etcx >> etcy;
		if (etcx == 0 && etcy == 0) break;
		
		points[npts].x = etcx;
		points[npts].y = etcy;
		npts++;
		etcx = min(m, max(0,etcx));
		etcy = min(m, max(0,etcy));
		
		if (infos[etcx].y < etcy) {
			infos[etcx].y = etcy;
			infos[etcx].i = npts-1;
		}
	}
	
//	cerr << npts << " = NPTS\n";
	
	dp[0] = 0;
	for (int i = 0; i < m; i++) {
		int Y = infos[i].y;
		int I = infos[i].i;
		
//		cerr << "#" << i << " : Y=" << Y << " I=" << I << "\n";
		
		for (int j = i+1; j <= Y; j++)
			if (dp[j] > dp[i] + 1) {
				dp[j] = dp[i] + 1;
				pr[j].u = I;
				pr[j].p = i;
			}
	}
	
	if (dp[m] == INF) {
		cout << "No solution\n";
		return 0;
	}
	
	cout << dp[m] << "\n";
	
	int x = m;
	
	while (x > 0) {
		int U = pr[x].u;
		int P = pr[x].p;
		out[nout++] = U;
		
		x = P;
	}
	
	sort(out, out+nout, cmpspec);
	
	for (int i = 0; i < nout; i++)
		cout << points[out[i]].x << " " << points[out[i]].y << "\n";
	
	return 0;
}
