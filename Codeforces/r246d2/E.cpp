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

int n, m;
char res[200][200];
bool vis[50];

bool valid(int r1, int r2, int c1, int c2)
{
	if (!(0 <= r1 && r1 < n && r1 < r2 && r1 <= n && 0 <= c1 && c1 < m && c1 < c2 && c1 <= m))
		return 0;
	
	for (int i = r1; i < r2; i++)
		for (int j = c1; j < c2; j++)
			if (isalpha(res[i][j]))
				return 0;
	
	return 1;
}

char findmin(int r1, int r2, int c1, int c2)
{
	fill(vis, vis+26, 0);
	
	for (int i = r1; i < r2; i++)
	for (int j = c1; j < c2; j++)
	{
		for (int o = 0; o < 4; o++)
		{
			int ni = i+dir[o][0];
			int nj = j+dir[o][1];
			
			if (0 <= ni && ni < n && 0 <= nj && nj < m && res[ni][nj] != 0)
				vis[res[ni][nj]-'A'] = 1;
		}
	}
	
	for (int i = 0; i < 26; i++)
		if (!vis[i])
			return i+'A';
}

void color(int r1, int r2, int c1, int c2, char clr)
{
	for (int i = r1; i < r2; i++)
		for (int j = c1; j < c2; j++)
			res[i][j] = clr;
}

void nike(int r1, int r2, int c1, int c2)
{
	if (r2-r1 == c2-c1)
		color(r1, r2, c1, c2, findmin(r1, r2, c1, c2));
	else if (r2-r1 > c2-c1)
	{
		int plus = c2-c1;
		color(r1, r1+plus, c1, c1+plus, findmin(r1, r1+plus, c1, c1+plus));
		nike(r1+plus, r2, c1, c2);
	}
	else
	{
		int plus = r2-r1;
		color(r1, r1+plus, c1, c1+plus, findmin(r1, r1+plus, c1, c1+plus));
		nike(r1, r2, c1+plus, c2);
	}
}

int main()
{
	cin >> n >> m;
	
	nike(0, n, 0, m);
	
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		char lst = '-';
		for (int j = 0; j < m; j++)
		{
			if (isalpha(res[i][j]))
			{
				lst = res[i][j];
				continue;
			}
			
			for (char cur = 'A'; cur <= 'Z'; cur++)
			{
				if (cur == lst && res[i][j] == '#' && valid(i, i+cnt+1, j-cnt+1, j+1) && cur == (mn = findmin(i, i+cnt+1, j-cnt+1, j+1)))
				
				char mn;
				if (res[i][j] == '#' && )
				{
					
				}
			}
		}
	}
	
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
