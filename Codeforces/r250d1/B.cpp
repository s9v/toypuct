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

int n, m;
int ani[100010];
pi ord[100010];

// tree info
vi gr[100010];
int pr[100010];

// pre - tree info
bool intree[100010];
priority_queue<pi> frd[100010];

int subsz[100010];

void nike(int v)
{
	for (auto w: gr[v])
	if (pr[v] != w)
	nike(w);
	
	subsz[v] = 1;
	
	for (auto w: gr[v])
		subsz[v] += subsz[w];
}

int main()
{
	cin >> n;
	cin >> m;
	
	fill(lst, lst+n, 0);
	
	for (int i = 0; i < n; i++)
	{
		cin >> ani[i];
		ord[i] = mp(ani[i], i);
	}
	
	sort(ord, ord+n);
	
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		//~ gr[x].pb(y);
		//~ gr[y].pb(x);
		frd[x].push(mp(ani[y], y));
		frd[y].push(mp(ani[x], x));
	}
	
	int treesz = 1;
	
	priority_queue<pi> pq;
	pq.push(mp(ani[0], 0));
	intree[0] = 1;
	
	while (treesz < n)
	{
		int v = pq.top().second;
		
		while (!frd[v].empty() && intree[frd[v].top().second])
			frd.pop();
		
		if (frd[v].empty())
		{
			pq.pop();
			continue;
		}
		
		gr[v].pb(frd[v].top());
		pr[frd[v].top()] = v;
		pq.push(frd[v].top());
		intree[frd[v].top()] = 1;
		
		treesz++;
	}
	
	nike(0);
	
	i64 tot = 0LL;
	
	for (int omg = n-1; omg >= 0; omg--)
	{
		int v = ord[omg].second;
		
	}
	
	
	prinf("%.8lf", 1.0*tot/(1LL*n*(n-1)));
	
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
