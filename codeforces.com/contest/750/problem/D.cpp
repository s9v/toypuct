#include <bits/stdc++.h>
#define dbg(X) cerr << #X << " -> " << (X) << endl
using namespace std;

const int INF = 2e9 + 100;
const int MAXN = 310;

int n;
int t[30];

int dir[8][2] = {
	{-1,  0},
	{-1, -1},
	{ 0, -1},
	{+1, -1},
	{+1,  0},
	{+1, +1},
	{ 0, +1},
	{-1, +1}};

bool grid[MAXN][MAXN];

void flippaste(int x, int y, int dirpt) {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			int c = dir[dirpt][0];
			int d = dir[dirpt][1];
			double k = (d*(i-x) - c*(j-y))*1.0 / (d*d + c*c);
			int ii = int(i - 2*k*d);
			int jj = int(j + 2*k*c);
			
			if ((0 <= ii and ii < MAXN) and (0 <= jj and jj < MAXN))
				grid[i][j] = grid[i][j] or grid[ii][jj];
		}
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> t[i];
	
	int dirpt = 0;
	int x = 150;
	int y = 150;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < t[i]; j++) {
			x += dir[dirpt][0];
			y += dir[dirpt][1];
		}
		
		dirpt = (dirpt+1) % 8;
	}
	
	dirpt = (dirpt-1+8) % 8;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < t[i]; j++) {
			grid[x][y] = true;
			
			x -= dir[dirpt][0];
			y -= dir[dirpt][1];
		}
		
		dirpt = (dirpt-1+8) % 8;
		
		if (i != 0)
			flippaste(x, y, dirpt);
	}
	
	int cnt = 0;
	
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			cnt += grid[i][j];
	
	cout << cnt;
	
	return 0;
}
