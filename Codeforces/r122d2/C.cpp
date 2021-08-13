#include <iostream>
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
using namespace std;

int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};

int n;
int m;
char krt[100][100];
int cnt[100][100];
int all;
int res = 1e9;

int main()
{
	cin >> n >> m;
	
	forn (i, n)
	forn (j, m)
	{
		cin >> krt[i][j];
		all += (krt[i][j] == '#');
	}
	
	forn (i, n)
	forn (j, m)
	if (krt[i][j] == '#')
	{
		int cnt = 0;
		
		forn (o, 4)
		{
			int ni = i+dir[o][0];
			int nj = j+dir[o][1];
			
			if (0 <= ni && ni < n && 0 <= nj && nj < m)
				cnt += (krt[ni][nj] == '#');
		}
		
		if (all-cnt > 1)
			res = min(res, cnt);
	}
	
	forn (i, n)
	forn (j, m)
	if (krt[i][j] == '#') {
		krt[i][j] = '.';
		
		forn (i, n)
		forn (j, m)
		{
			if (!vis[i][j])
				dfs(i, j);
		}
		
		krt[i][j] = '#';
	}
	
	cout << (res == 1e9 ?-1 :res);
	
	return 0;
}
