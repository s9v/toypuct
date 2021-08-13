#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int R, C;
bool vis[1000][1000];
int  dst[1000][1000];
char grd[1000][1001];
int dir[4][2] = {
	{+1,+0},
	{-1,+0},
	{+0,+1},
	{+0,-1}
};

void bfs(int i, int j) {
	queue<int> q;
	q.push(i);
	q.push(j);
	vis[i][j] = 1;
	dst[i][j] = 0;
	
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		
		for (int o = 0; o < 4; o++)
		{
			int nx = x+dir[o][0];
			int ny = y+dir[o][1];
			
			if (0 <= nx && nx <= R-1 && 0 <= ny && ny <= C-1 && !vis[nx][ny] && grd[nx][ny] == '.') {
				dst[nx][ny] = dst[x][y]+1;
				vis[nx][ny] = 1;
				q.push(nx);
				q.push(ny);
			}
		}
		
	}
}

int main() {
	cin >> T;
	
	while (T--) {
		cin >> C >> R;
		
		for (int i = 0; i < R; i++)
			cin >> grd[i];
		
		fill(vis[0], vis[1000], 0);
		fill(dst[0], dst[1000], 0);
		
		bool term = 0;
		for (int i = 0; i < R && !term; i++)
			for (int j = 0; j < C && !term; j++)
				if (grd[i][j] == '.') {
					bfs(i,j);
					term = 1;
				}
		
		int mx = *max_element(dst[0], dst[1000]);
		
		term = 0;
		for (int i = 0; i < R && !term; i++)
			for (int j = 0; j < C && !term; j++)
				if (dst[i][j] == mx) {
					fill(vis[0], vis[1000], 0);
					fill(dst[0], dst[1000], 0);
					bfs(i,j);
					term = 1;
				}
		
		cout << "Maximum rope length is " << *max_element(dst[0], dst[1000]) << ".\n";
	}
	
	
	return 0;
}
