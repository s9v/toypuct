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

struct Line {
	int A, B, C;
};

int a, b;
Line l, k;

int main()
{
	scanf("%d %d", &a, &b);
	
	fora (w, 1, 1000)
	fora (h, 1, 1000)
	if (a*a == h*h + w*w)
	{
		l.A = h;
		l.B = -w;
		l.C = 0;
		
		k.A = -l.B;
		k.B = l.A;
		k.C = -k.A*w-k.B*h;
		
		double foo = sqrt(k.A*k.A + k.B*k.B);
		double bar = k.B*b/foo;
		double lol = k.A*b/foo;
		
		if (foo == (int)foo && bar == (int)bar && lol == (int)lol)
		{
			if (w-bar != 0 && h+lol != 0)
			{
				printf("YES\n");
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", w, h);
				printf("%d %d\n", (int)(w-bar), (int)(h+lol));
				return 0;
			}
			else if (w+bar != 0 && h-lol != 0)
			{
				printf("YES\n");
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", w, h);
				printf("%d %d\n", (int)(w+bar), (int)(h-lol));
				return 0;
			}
		}
	}
	
	printf("NO\n");
	
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
