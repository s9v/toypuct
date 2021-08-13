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

const i64 MOD = 1000000009;

int n;
int h;
i64 dp[200][2][30][30][30];

int main()
{
	/*
	int x;
	while (cin >> x)
		cout << ((x&1)^1) << " : feed\n";
	*/
	
	cin >> n;
	cin >> h;
	
	dp[1][1][0][0][0] = 4;
	
	fora (curN, 1, n-1)
	{
		fill(dp[(curN+1)%2][0][0][0], dp[(curN+1)%2+1][0][0][0], 0LL);
		
		fora (alive, 0, 1)
			fora (last1, 0, h)
				fora (last2, 0, h)
					fora (last3, 0, h)
					{
						{
							i64 &foo = dp[(curN+1)%2][alive][(last1+1)%h][(last2+1)%h][(last3+1)%h];
							foo += dp[curN][alive][last1][last2][last3];
							foo -= foo/MOD*MOD;
						}
						{
							i64 &foo = dp[(curN+1)%2][last1 > 0 || curN < h][alive][(last2+1)%h][(last3+1)%h];
							foo += dp[curN][alive][last1][last2][last3];
							foo -= foo/MOD*MOD;
						}
						{
							i64 &foo = dp[(curN+1)%2][last2 > 0 || curN < h][(last1+1)%h][alive][(last3+1)%h];
							foo += dp[curN][alive][last1][last2][last3];
							foo -= foo/MOD*MOD;
						}
						{
							i64 &foo = dp[(curN+1)%2][last3 > 0 || curN < h][(last1+1)%h][(last2+1)%h][alive];
							foo += dp[curN][alive][last1][last2][last3];
							foo -= foo/MOD*MOD;
						}
					}
	}
	
	i64 res = 0LL;
	
	fora (a, 0, h)
	fora (b, 0, h)
	fora (c, 0, h)
	{
		res += dp[n%2][1][a][b][c];
		res -= res/MOD*MOD;
		
		if (a > 0 || b > 0 || c > 0)
		{
			res += dp[n%2][0][a][b][c];
			res -= res/MOD*MOD;
		}
	}
	
	cout << res;
	
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
