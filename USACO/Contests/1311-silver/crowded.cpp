#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int,int> pii;

int n, d;
pii cows[50010];
int x[50010];
int h[50010];
int crowded;

int rmq[50010][20];

void rmqinit() {
	for (int i = 0; i < n; i++)
		rmq[i][0] = h[i];
	
	for (int j = 1; (1<<j) <= n; j++)
		for (int i = 0; i+(1<<j)-1 < n; i++)
			rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
}

int getmax(int l, int r) {
	l = max(0, min(n-1, l));
	r = max(0, min(n-1, r));
	
	if (r < l)
		swap(l,r);
	
	int j;
	for (j = 0; (1<<j) <= (r-l+1); j++); // ;
	j--;
	
	return max(rmq[l][j], rmq[r-(1<<j)+1][j]);
}

int main() {
	ifstream fin("crowded.in");
	ofstream fout("crowded.out");
	
	fin >> n >> d;
	
	for (int i = 0; i < n; i++)
		fin >> cows[i].first >> cows[i].second;
	
	sort(cows, cows+n);
	
	for (int i = 0; i < n; i++) {
		x[i] = cows[i].first;
		h[i] = cows[i].second;
	}
	
	rmqinit();
	
	for (int i = 0; i < n; i++)
	{
		int l = lower_bound(x, x+n, x[i]-d) - x;
		int r = upper_bound(x, x+n, x[i]+d) - x - 1;
		
		if (getmax(l,i) >= 2*h[i] && getmax(i,r) >= 2*h[i])
			crowded++;
	}
	
	fout << crowded;
	
	fin.close();
	fout.close();
	return 0;
}
