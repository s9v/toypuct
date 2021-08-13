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

const int MOD = 1000000007;

int n;
int res = 1;
int C[600*30][600];
vi pr;

int main()
{
	C[0][0] = 1;
	fora (i, 1, 600*30-1)
	{
		C[i][0] = 1;
		
		if (i < 600)
			C[i][i] = 1;
		
		int till = min(i-1, 600-1);
		fora(j, 2, till) {
			C[i][j] = C[i-1][j]+C[i-1][j-1];
			C[i][j] -= C[i][j]/MOD*MOD;
		}
	}
	
	cout << C[3][2] << " is C3,2\n";
	
	cin >> n;
	
	forn (i, n) {
		int a;
		cin >> a;
		
		int sqa = sqrt(a);
		fora (x, 2, sqa)
		if (a/x*x == a) {
			while (a/x*x == a) {
				a /= x;
				pr.pb(x);
				cerr << x << " * ";
			}
		}
		
		if (a > 1) {
			pr.pb(a);
			cerr << a << " * ";
		}
		
		cerr << "\n";
	}
	
	sort(all(pr));
	
	int cnt = 1;
	fora (i, 1, sz(pr))
		if (i < sz(pr) && pr[i-1] == pr[i])
			cnt++;
		else {
			cerr << "CNT : " << cnt << "\n";
			res *= C[cnt+n-1][n-1];
			res -= res/MOD*MOD;
			
			cnt = 1;
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
