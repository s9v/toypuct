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

const int MAXST = 1048576;

struct Node {
	int n4;
	int n7;
	int n47;
	int n74;
	bool ext; // extra for children
	
	Node() : n4(0), n7(0), n47(0), n74(0), ext(0) { };
};

int n, m;
string digs;

struct AugSegTree {
	Node st[2*MAXST];
	
	void init(const string &s, int v = 0, int vl = 0, int vr = n-1) {
	//~ void init(const string &s, int v, int vl, int vr) {
		if (vl == vr) {
			st[v].n4 = (s[vl] == '4');
			st[v].n7 = (s[vl] == '7');
			st[v].n47 = 1;
			st[v].n74 = 1;
			st[v].ext = 0;
		}
		else {
			init(s,2*v+1,vl,(vl+vr)/2+0);
			init(s,2*v+2,(vl+vr)/2+1,vr);
			
			st[v].n4 = st[2*v+1].n4 + st[2*v+2].n4;
			st[v].n7 = st[2*v+1].n7 + st[2*v+2].n7;
			st[v].n47 = max(st[2*v+1].n4 + st[2*v+2].n47, st[2*v+1].n47 + st[2*v+2].n7);
			st[v].n74 = max(st[2*v+1].n7 + st[2*v+2].n74, st[2*v+1].n74 + st[2*v+2].n4);
			st[v].ext = 0;
		}
	}
	
	void update(int ql, int qr, int v = 0, int vl = 0, int vr = n-1, int ext = 1) {
	//~ void update(int ql, int qr, int v, int vl, int vr, int ext) {
		if (vr < ql || qr < vl)
			return;
		
		if (ql <= vl && vr <= qr) {
			if (ext) {
				//~ cerr << v << " * nomore\n";
				//~ dbg(ql);
				//~ dbg(qr);
				//~ dbg(vl);
				//~ dbg(vr);
				//~ cerr << "******** nomore\n";
				swap(st[v].n4, st[v].n7);
				swap(st[v].n47, st[v].n74);
			}
			st[v].ext ^= 1;
		}
		else {
			update(ql,qr,2*v+1,vl,(vl+vr)/2+0,ext^st[v].ext);
			update(ql,qr,2*v+2,(vl+vr)/2+1,vr,ext^st[v].ext);
			
			st[v].n4 = st[2*v+1].n4 + st[2*v+2].n4;
			st[v].n7 = st[2*v+1].n7 + st[2*v+2].n7;
			st[v].n47 = max(st[2*v+1].n4 + st[2*v+2].n47, st[2*v+1].n47 + st[2*v+2].n7);
			st[v].n74 = max(st[2*v+1].n7 + st[2*v+2].n74, st[2*v+1].n74 + st[2*v+2].n4);
			st[v].ext = 0;
		}
	}
};

AugSegTree ast;

void darow(int v = 0, int vl = 0, int vr = n-1)
{
	dbg(v);
	dbg(ast.st[v].n4);
	dbg(ast.st[v].n7);
	dbg(ast.st[v].n47);
	dbg(ast.st[v].n74);
	dbg(ast.st[v].ext);
	
	if (vl != vr)
	{
		darow(2*v+1, vl, (vl+vr)/2+0);
		darow(2*v+2, (vl+vr)/2+1, vr);
	}
}

int main()
{
	cin >> n >> m;
	cin >> digs;
	
	ast.init(digs);
	
	//~ darow();
	
	forn (fooquery, m) {
		string cmd;
		cin >> cmd;
		
		if (cmd == "switch") {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			ast.update(l, r);
			//~ darow();
		}
		else if (cmd == "count") {
			cout << ast.st[0].n47 << "\n";
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

/*
9
7
747747474
switch 8 9
count
switch 1 7
count
switch 1 1
switch 5 8
count
*/

/*
3 3
447
switch 3 3
switch 1 1
count
*/
