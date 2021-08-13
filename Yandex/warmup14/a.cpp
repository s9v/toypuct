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
 int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
// int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* { END } */

char chess[8][8];
char tmp1[5];
char tmp2[5];
char tmp3[5];
pi wking;
pi wrook;
pi bking;

string foo[2][2] = {
	{"Stalement", "Normal"},
	{"Checkmate", "Check"}
};

bool attackByKing(pi bking, pi wking)
{
	forn (o, 8)
	{
		int nx = wking.first + dir[o][0];
		int ny = wking.second + dir[o][1];
		
		if (0 <= nx && nx < 8 &&
			0 <= ny && ny < 8 &&
			bking == mp(nx, ny))
			return 1;
	}
	
	return 0;
}

bool attackByRook(pi bking, pi wrook)
{
	if (bking == wrook)
		return 0;
	
	if (bking.first == wrook.first)
	{
		bool flag = 1;
		
		for (int j = min(bking.second, wrook.second); j <= max(bking.second, wrook.second); j++)
		if (mp(bking.first, j) == wking)
		{
			flag = 0;
			break;
		}
		
		if (flag)
			return 1;
	}
	
	if (bking.second == wrook.second)
	{
		bool flag = 1;
		
		for (int i = min(bking.first, wrook.first); i <= max(bking.first, wrook.first); i++)
		if (mp(i, bking.second) == wking)
		{
			flag = 0;
			break;
		}
		
		if (flag)
			return 1;
	}
	
	return 0;
}

int main()
{
	cin >> tmp1;
	cin >> tmp2;
	cin >> tmp3;
	
	wking = mp(tmp1[1]-'1', tmp1[0]-'a');
	wrook = mp(tmp2[1]-'1', tmp2[0]-'a');
	bking = mp(tmp3[1]-'1', tmp3[0]-'a');
	
	if (attackByKing(bking, wking))
	{
		cout << "Strange";
		return 0;
	}
	
	int cnt = 0;
	forn (o, 8)
	{
		int nx = bking.first + dir[o][0];
		int ny = bking.second + dir[o][1];
		
		if (0 <= nx && nx < 8 && 0 <= ny && ny < 8)
			cnt += !attackByKing(mp(nx, ny), wking) && !attackByRook(mp(nx, ny), wrook);
	}
	
	// dbg(cnt);
	
	cout << foo[attackByKing(bking, wking) || attackByRook(bking, wrook)][cnt != 0];
	
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
