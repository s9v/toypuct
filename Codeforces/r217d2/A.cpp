#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define  DBG(X) cerr << #X << " --> " << X << "\n";
using namespace std;

int r1, c1;
int r2, c2;
int a, b, c;

int dir[4][2] {
	{-1,-1},
	{+1,-1},
	{-1,+1},
	{+1,+1}
};
int m[8][8];
bool v[8][8];

int main() {
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	
	a = 2;
	
	if (r1 == r2)
		a--;
	if (c1 == c2)
		a--;
	
	queue<int> q;
	v[r1-1][c1-1] = 1;
	q.push(r1-1);
	q.push(c1-1);
	
	while ( ! q.empty()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		
		for (int o = 0; o < 4; o++)
		{
			int nx = x + dir[o][0];
			int ny = y + dir[o][1];
			
			if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && !v[nx][ny]) {
				v[nx][ny] = 1;
				m[nx][ny] = m[x][y]+1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			cout << m[i][j] << " ";
		cout << "\n";
	}
	
	b = m[r2-1][c2-1];
	
	c = abs(r1-r2) + abs(c1-c2) - min(abs(r1-r2), abs(c1-c2));
	
	cout << a << " " << b << " " << c;
	
	return 0;
}
