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

int n1, n2, n3;
vi gr[3][100000];
int n[3];
int perm[] = {0, 1, 2};
vi* mygr;
int myn;
vi* gr1;
vi* gr2;
vi* gr3;
vi grx[300000];
i64 dst[300000];
i64 dst2[300000];
//int par[300000];
//int nch[300000];
i64 nag[300000];
//int net[300000];
i64 ans = 0;

void dfs(int v, int pr)
{
	nag[v] = 1;
	
	for (auto u: mygr[v])
		if (u != pr) {
			dfs(u, v);
			
			dst[v] += dst[u] + nag[u];
			nag[v] += nag[u];
		}
}

void dfs2(int v, int pr)
{
	if (pr != -1)
		dst2[v] = dst2[pr] + (myn-nag[v]) - (nag[v]);
	else
		dst2[v] = dst[v];
	
	for (auto u: mygr[v])
	{
		if (u != pr)
			dfs2(u, v);
	}
}

int coolguy(vi *_mygr, int _myn)
{
	mygr = _mygr;
	myn = _myn;
	
	fill(dst, dst+300000, 0);
	fill(dst2, dst2+300000, 0);
	fill(nag, nag+300000, 0);
	
	dfs(0, -1);
	dfs2(0, -1);
	/*
	cerr << "dst : ";
	forn (i, myn)
		cerr << dst[i] << " ";
	cerr << "\n";
	
	cerr << "dst2 : ";
	forn (i, myn)
		cerr << dst2[i] << " ";
	cerr << "\n";
	
	cerr << "nag : ";
	forn (i, myn)
		cerr << dst[i] << " ";
	cerr << "\n";
	forn (i, myn)
		cerr << "=====";
	cerr << "\n";
	*/
	return max_element(dst2, dst2+myn)-dst2;
}

void dummynike()
{
	
}

int main()
{
	cin >> n[0];
	cin >> n[1];
	cin >> n[2];
	
	forn(i, n[0]-1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		gr[0][a].pb(b);
		gr[0][b].pb(a);
	}
	
	forn(i, n[1]-1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		gr[1][a].pb(b);
		gr[1][b].pb(a);
	}
	
	forn(i, n[2]-1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		gr[2][a].pb(b);
		gr[2][b].pb(a);
	}
	//getchar();
	
	do {
		gr1 = gr[perm[0]];
		gr2 = gr[perm[1]];
		gr3 = gr[perm[2]];
		
		n1 = n[perm[0]];
		n2 = n[perm[1]];
		n3 = n[perm[2]];
		
		int cg1 = coolguy(gr1, n1);
		int cg2 = coolguy(gr2, n2);
		int cg3 = coolguy(gr3, n3);
		
		// grx = gr1 + gr2 + (cg1 -- cg2)
		
		forn (i, n1)
		{
			grx[i+0] = gr1[i];
			forn (j, gr1[i].size())
				grx[i+0][j] += 0;
		}
		
		forn (i, n2)
		{
			grx[i+n1] = gr2[i];
			forn (j, gr2[i].size())
				grx[i+n1][j] += n1;
		}
		
		grx[cg1].pb(n1+cg2);
		grx[n1+cg2].pb(cg1);
		
		int cgx = coolguy(grx, n1+n2);
		
		forn (i, n3)
		{
			grx[i+n1+n2] = gr3[i];
			forn (j, gr3[i].size())
				grx[i+n1+n2][j] += n1+n2;
		}
		
		grx[cgx].pb(n1+n2+cg3);
		grx[n1+n2+cg3].pb(cgx);
		
		coolguy(grx, n1+n2+n3);
		
		i64 res = accumulate(dst2, dst2+n1+n2+n3, 0LL);
		
		//cerr << res << " :res\n\n";
		
		ans = max(ans, res);
		//getchar();
		
		//dummynike();
	} while (next_permutation(perm, perm+3));
	
	cout << ans/2;
	
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
