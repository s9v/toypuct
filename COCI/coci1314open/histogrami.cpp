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
#define  y1				thisisnotnonsenseasyoumaythinkaskmethenilltellyouwhatthisreallyis
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define  dbg(vari) cerr << #vari << " = " << (vari) << endl;

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
	if (x%2 == 0) return 0;
	for (int i = 3; i <= till; i += 2) if (x%i == 0) return 0;
	return 1;
}

/* { CONST } */
// const double Pi = acos(-1.0);
// int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
// int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* { END } */

int n, m, g;
pi h[100000];
pi s[1000];
int cumh[1000000];
i64 opt[2][1000][2];

i64 value(int mode, int hgt, int l, int r)
{
	i64 ret = 0;
	if (mode == 0)
	{
		for (int i = l; i < r; i++)
			ret += (cumh[i] == hgt);
		return ret;
	}
	else
	{
		for (int i = l; i < r; i++)
			ret += abs(cumh[i] - hgt);
		return ret;
	}
}

int main()
{
	cin >> n;
	cin >> m;
	cin >> g;
	
	for (int i = 0; i < n; i++)
		cin >> h[i].first >> h[i].second;
	
	for (int i = 0; i < n; i+=2)
		for (int j = h[i].first; j < h[i+1].first; j++)
			cumh[j] = h[i].second;
	
	for (int i = 0; i < m; i++)
		cin >> s[i].first >> s[i].second;
	
	sort(s, s+m);
	
	fill(opt[0][0], opt[2][0], -1);
	
	for (int i = 0; i < m; i++)
	{
		if (s[i].first == 0)
		{
			opt[0][i][1] = 0;
			opt[1][i][1] = 0;
		}
		else
		{
			for (int val = 0; val < 2; val++)
			for (int j = 0; j < m; j++)
			if (s[j].first <= s[i].first)
			{
				if (s[j].first == s[i].first && opt[val][j][0] != -1)
					opt[val][i][1] = min(opt[val][i][1], opt[val][j][0]);
				if (s[j].second == s[i].second && opt[val][j][1] != -1)
					opt[val][i][0] = min(opt[val][i][0], opt[val][j][1] + value(val, s[i].second, s[j].first, s[i].first));
			}
		}
	}
	
	i64 ans = 1e16;
	for (int i = 0; i < m; i++)
	if (s[i].first == s[m-1].first && opt[g][i][0] != -1)
		ans = min(ans, opt[g][i][0]);
	
	cout << ans;
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
//	cout << clock() - st;
//	getchar();
//	getchar();
	
	return EXIT_SUCCESS;
}
