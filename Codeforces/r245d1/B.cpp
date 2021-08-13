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
// int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
// int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* { END } */

struct Pos {
	int i, j;
	Pos() {}
	Pos(int ii, int jj) : i(ii), j(jj) {}
	bool operator == (Pos another) const
	{
		return i == another.i && j == another.j;
	}
	void pr()
	{
		cerr << i << " , " << j << "\n";
	}
};

int n, m, res;
int cost[1011][1011];
int optM[1011][1011][2]; // man
int optW[1011][1011][2]; // woman

Pos dinM[2]  = {{0,-1},{-1,0}};
Pos doutM[2] = {{+1,0},{0,+1}};

Pos dinW[2]  = {{0,-1},{+1,0}};
Pos doutW[2] = {{-1,0},{0,+1}};

inline bool inside(const Pos &p)
{
	return 1 <= p.i && p.i <= n && 1 <= p.j && p.j <= m;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> cost[i][j];
	
	// lahub 0
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			optM[i][j][0] = cost[i][j] + max(optM[i-1][j][0], optM[i][j-1][0]);
	
	// lahub 1
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			optM[i][j][1] = cost[i][j] + max(optM[i+1][j][1], optM[i][j+1][1]);
	
	// lahubina 0
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			optW[i][j][0] = cost[i][j] + max(optW[i+1][j][0], optW[i][j-1][0]);
	
	// lahubina 1
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			optW[i][j][1] = cost[i][j] + max(optW[i-1][j][1], optW[i][j+1][1]);
	
	Pos inM, outM;
	Pos inW, outW;
	int cur;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	for (int a = 0; a < 2; a++)
	for (int b = 0; b < 2; b++)
	for (int c = 0; c < 2; c++)
	for (int d = 0; d < 2; d++)
	{
		inM = Pos(i + dinM[a].i, j + dinM[a].j);
		outM = Pos(i + doutM[b].i, j + doutM[b].j);
		inW = Pos(i + dinW[c].i, j + dinW[c].j);
		outW = Pos(i + doutW[d].i, j + doutW[d].j);
		
		if (inside(inM) && inside(outM) && inside(inW) && inside(outW) &&
			!(inM == inW) && !(inM == outW) && !(outM == inW) && !(outM == outW))
		{
			cur = 0;
			cur += optM[inM.i][inM.j][0];
			cur += optM[outM.i][outM.j][1];
			cur += optW[inW.i][inW.j][0];
			cur += optW[outW.i][outW.j][1];
			res = max(res, cur);
		}
	}
	
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
