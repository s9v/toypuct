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
//~ #define  dbg(vari)		cerr << #vari << " = " << (vari) << endl
#define  dbg(vari)		cout << #vari << " = " << (vari) << endl

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

int N;
int n, m, k;
int p[4000];
bool vis[4000];
vi fst;

int main()
{
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		cin >> p[i];
	
	cin >> m;
	
	for (int i = 1; i <= N; i++)
	if (!vis[i]) {
		int cur = i;
		int nsize = 0;
		int mn = 1e6;
		do {
			mn = min(mn, cur);
			vis[cur] = 1;
			cur = p[cur];
			nsize++;
		} while (cur != i);
		
		k += nsize-1;
		fst.pb(mn);
	}
	
	sort(all(fst));
	
	//~ dbg(k);
	
	if (k >= m)
	{
		n = k-m;
		
		cout << n << "\n";
		
		for (int times = 0; times < n; times++)
		{
			fill(vis+1, vis+N+1, 0);
			for (int i = 1; i <= N; i++)
			if (!vis[i]) {
				vi cmt;
				int cur = i;
				do {
					vis[cur] = 1;
					cmt.pb(cur);
					cur = p[cur];
				} while (cur != i);
				
				if (sz(cmt) >= 2)
				{
					sort(all(cmt));
					cout << cmt[0] << " " << cmt[1] << " ";
					swap(p[cmt[0]], p[cmt[1]]);
					break;
				}
			}
		}
	}
	else if(k < m)
	{
		n = m-k;
		
		cout << n << "\n";
		
		for (int j = 1; j < sz(fst) && n > 0; j++)
		{
			cout << fst[0] << " " << fst[j] << " ";
			n--;
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
