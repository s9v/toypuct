// cfcode v1.6

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional> // greater<int>()
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

/* MACROS */

#define  all(A)			(A).begin() , (A).end()
#define  rall(A)		(A).rbegin() , (A).rend()
#define  sz(A)			(int)(A).size()
#define  pb				push_back
#define  ppb			pop_back
#define  mp				make_pair
#define  ln(X)			(int)(X).length()
#define  square(X)		((X)*(X))
#define  cube(X)		((X)*(X)*(X))
#define  y1				thisisnotnonsenseasyoumaythinkemailmeilltellyouwhatthisreallyis
#define  forn(i, n)		for (int i = 0; i < int(n); i++)
#define  forr(i, n)		for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define  dbg(vari)		cerr << #vari << " = " << (vari) << endl

//time_t st = clock();

using namespace std;

/* TYPE DEFINITIONS */
typedef		long long		i64;
typedef		vector<int>		vi;
typedef		pair<int,int>	pi;

/* TOOLS */
template <class T> void debug(T a,T b){ for (; a != b; a++) cerr << *a << ' '; cerr << endl; }

/* ALGEBRA */
template <class T> bool isprime(T x) {
	int till = (T)sqrt(x+.0);
	if (x <= 1) return 0;
	if (x == 2) return 1;
	if (x/2*2 == x) return 0;
	for (int i = 3; i <= till; i += 2) if (x/i*i == x) return 0;
	return 1;
}

/* { CONST } */
// const double Pi = acos(-1.0);
 int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
// int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* { END } */

struct Pos { int i, j; Pos(int i=0, int j=0) : i(i), j(j) {} };

int R, C;
char grd[1000][1000];
int dst[1000][1000];
int dst2[1000][1000];
Pos S;
Pos E;

void bfs(Pos P, int dst[1000][1000])
{
	queue<int> q;
	q.push(P.i);
	q.push(P.j);
	dst[P.i][P.j] = 1;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		
		forn (o, 4)
		{
			int nx = x+dir[o][0];
			int ny = y+dir[o][1];
			
			if (0 <= nx && nx < R && 0 <= ny && ny < C && dst[nx][ny] == 0 && grd[nx][ny] != 'T')
			{
				dst[nx][ny] = dst[x][y]+1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
}

int main()
{
	cin >> R;
	cin >> C;
	
	forn (i, R)
		forn (j, C)
		{
			cin >> grd[i][j];
			
			if (grd[i][j] == 'S')
				S = Pos(i, j);
			if (grd[i][j] == 'E')
				E = Pos(i, j);
		}
	
	bfs(S, dst);
	bfs(E, dst2);
	
	int res = 0;
	forn (i, R)
		forn (j, C)
			if ('1' <= grd[i][j] && grd[i][j] <= '9' && dst2[i][j] > 0 && dst2[i][j] <= dst[E.i][E.j])
				res += grd[i][j]-'0';
	
	cout << res;
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
//	cerr << clock() - st;
//	getchar();
//	getchar();
	
	return EXIT_SUCCESS;
}
