// cfcode v1.5

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
	if (x%2 == 0) return 0;
	for (int i = 3; i <= till; i += 2) if (x%i == 0) return 0;
	return 1;
}

/* { CONST } */
// const double Pi = acos(-1.0);
// int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
// int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* { END } */

struct triple { int first, second, third; };

triple mk3(const int &a, const int &b, const int &c)
{
	triple ret;
	ret.first = a;
	ret.second = b;
	ret.third = c;
	return ret;
}

int n, m;
vi gr[100000];
bool used[100000];
int tail[100000];
int tin[100000];
vector<triple> res;
int timer = 0;

void dfs(int v, int pr)
{
	used[v] = 1;
	tin[v] = timer++;
	
	stack<int> s0;
	
	for (auto w: gr[v])
	if (!used[w])
	{
		dfs(w, v);
		
		if (tail[w] == -1)
			s0.push(w);
		else
			res.pb(mk3(v,w,tail[w]));
	}
	else if (w != pr && tin[v] > tin[w])
		s0.push(w);
	
	while (sz(s0) > 1)
	{
		int w = s0.top();
		s0.pop();
		int u = s0.top();
		s0.pop();
		res.pb(mk3(w,v,u));
	}
	
	tail[v] = (sz(s0) == 1 ?s0.top() :-1);
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	
	dfs(0, -1);
	
	if (tail[0] != -1)
		printf("No solution");
	else
		for (int i = 0; i < sz(res); i++)
			printf("%d %d %d\n", res[i].first+1, res[i].second+1, res[i].third+1);
	
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
