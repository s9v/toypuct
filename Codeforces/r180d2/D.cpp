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

int n, m;
int k;
int a[100000];
int b[100000];
vi newa;
vi newb;
vi newc;

int main()
{
	cin >> n >> m;
	cin >> k;
	
	forn (i, n)
		cin >> a[i];
	
	forn (i, m)
		cin >> b[i];
	
	sort(a, a+n);
	sort(b, b+m);
	
	newa.reserve(100000);
	newb.reserve(100000);
	newc.reserve(200000);
	
	for (int i = 0, j = 0; i < n || j < m;) {
		if (i < n && j < m) {
			if (a[i] < b[j]) {
				newc.pb(a[i]);
				newa.pb(a[i]);
				i++;
			}
			else if (a[i] > b[j]) {
				newc.pb(b[j]);
				newb.pb(b[j]);
				j++;
			}
			else {
				i++;
				j++;
			}
		}
		else {
			if (i < n) {
				newc.pb(a[i]);
				newa.pb(a[i]);
				i++;
			}
			if (j < m) {
				newc.pb(b[j]);
				newb.pb(b[j]);
				j++;
			}
		}
	}
	
	sort(all(newa));
	sort(all(newb));
	sort(all(newc));
	
	int cntb = 0;
	forr (i, sz(newc)) {
		if (binary_search(all(newb) , newc[i])) {
			cntb++;
		}
		else {
			cntb--;
		}
		
		if (cntb < 0) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";
	
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
