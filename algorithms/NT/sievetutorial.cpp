/*
 *
 *
 *
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define FORD(i, a, b) for (i = (a); i >= (b); i--)
#define REP(i, n) for (i = 0; i < (n); i++)
#define REPD(i, n) for (i = ((n)-1); i >= 0; i--)
#define CLR(x, with) memset((x), with, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PB push_back
#define INF 90000000

#ifndef ONLINE_JUDGE
	FILE* fi = freopen("input.txt", "r", stdin);
	//FILE* fo = freopen("out.txt", "w", stdout);
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template <class T> int SZ(T x) { return x.size(); }
template <class T> void getMax(T& a, T b) { if (b > a) a = b; }


const int MAXP = 6000001;
int primes[MAXP];
int cnt;

const int SIZE = 100000000/2/8+1;
unsigned int mark[1024]; // mark[n]==0 if n is prime

void Sieve1(int N)
{
	int i, j;
	for (i = 2; i <= N; i++)
		if (mark[i] == 0)
		{
			primes[cnt++] = i;
			for (j = i+i; j <= N; j += i) mark[j] = 1;
		}	
}

void Sieve2(int N)
{
	int i, j;
	primes[cnt++] = 2;
	for (i = 3; i <= N; i += 2) 
		if (mark[i] == 0)
		{
			primes[cnt++] = i;
			for (j = i+i+i; j <= N; j += 2*i) mark[j] = 1;
		}
}

void Sieve3(int N)
{
	int i, j;
	primes[cnt++] = 2;
	for (i = 3; i <= N; i += 2) 
		if (mark[(i>>1)-1] == 0)
		{
			primes[cnt++] = i;
			for (j = i+i+i; j <= N; j += i<<1) mark[(j>>1)-1] = 1;
		}
}

void Sieve4(int N)
{
	int i, j;	
	for (i = 3; i*i <= N; i += 2) 
		if (mark[(i>>1)-1] == 0)
		{
			for (j = i*i; j <= N; j += i<<1) mark[(j>>1)-1] = 1;
		}
	primes[cnt++] = 2;
	for (i = 3; i <= N; i += 2)
		if (mark[(i>>1)-1] == 0) primes[cnt++] = i;
}

void Sieve5(int N)
{
	int i, j;	
	for (i = 3; i*i <= N; i += 2) 
		if ( (mark[i>>4] & (1<<((i>>1)&7))) == 0 )
		{
			for (j = i*i; j <= N; j += i<<1) mark[j>>4] |= (1<<((j>>1)&7));
		}
	primes[cnt++] = 2;
	for (i = 3; i <= N; i += 2)
		if ( (mark[i>>4]&(1<<((i>>1)&7))) == 0) primes[cnt++] = i;
}

int start;

void UpdateSieve()
{
	int i, j;

	for (i = 0; i < 1024; i++) mark[i] = 0;

	// start from prime number 3 not 2
	for (i = 1; i < cnt; i++)
	{
		j = primes[i] * primes[i];
		if (j >= start+65536) break;
		
		// find odd multiple of this prime[i] in this interval
		if (j < start)
		{
			j = (start / primes[i]) * primes[i];
			if (j < start) j += primes[i];
			if ((j&1) == 0) j += primes[i];
		}
		// mark all multiples of this prime[i]
		for (j = (j-start); j < 65536; j += (primes[i]<<1))
			mark[j>>6] |= (1<<((j>>1)&31));
	}
	// add primes found in this interval
	for (i = start+1; i < start+65536; i += 2)
	{
		j = i - start;
		if ( (mark[j>>6] & (1<<((j>>1)&31))) == 0 ) primes[cnt++] = i;
	}
}

void Sieve(int N)
{
	int i, j;

	for (i = 3; i < 256; i += 2)
		if ( (mark[i>>6]&(1<<((i>>1)&31))) == 0 )
			for (j = (i*i)>>1; j < 32768; j += i)
				mark[j>>5] |= (1<<(j&31));

	cnt = 0; primes[cnt++] = 2;
	for (i = 3; i < 65536; i += 2)
		if ( (mark[i>>6]&(1<<((i>>1)&31))) == 0) primes[cnt++] = i;

	//REP(i, cnt) printf("%d\n", primes[i]);
	/*
		1.
		find all primes in [2..65536) and store in primes
	*/

	// find primes for each interval
	for (start = 65536; start < N; start += 65536)
	{
		UpdateSieve();
	}
}

int main()
{
	int N, K, res;
	cnt = 0;
	Sieve(100000000);
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &K);
		res = primes[K-1];
		printf("%d\n",res);
	}
	return 0;
}
