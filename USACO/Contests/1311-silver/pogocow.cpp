#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int,int> pii;

int n, res;
pii pnt[1010];
int x[1010];
int p[1010];
int dp[1010][1010];


int answer() {
	int ret = 0;
	
	dp[n-1][n-1] = p[n-1];
	for (int i = n-2; i >= 0; i--) {
		int tmp = 0;
		
		for (int j = n-1; j > i; j--) {
			if (j < n-1)
				tmp = max(tmp, dp[i][j+1]);
			
			int pos = lower_bound(x, x+n, 2*x[j]-x[i]) - x;
			
			if (n-1 < pos)
				tmp = max(tmp, p[i] + p[j]);
			else
				tmp = max(tmp, dp[j][pos] + p[i]);
			
			dp[i][j] = tmp;
		}
		
		dp[i][i] = tmp;
		ret = max(ret, tmp);
	}
	
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << dp[i][j] << " ";
		cerr << "\n";
	}
	*/
	
	return ret;
}

int main() {
	ifstream fin("pogocow.in");
	ofstream fout("pogocow.out");
	
	fin >> n;
	
	for (int i = 0; i < n; i++)
		fin >> pnt[i].first >> pnt[i].second;
	
	sort(pnt, pnt+n);
	
	/*
	for (int i = 0; i < n; i++)
		cerr << pnt[i].first << " " << pnt[i].second << "\n";
	*/
	
	for (int i = 0; i < n; i++)
	{
		x[i] = pnt[i].first;
		p[i] = pnt[i].second;
	}
	
	res = answer();
	
	int tmp = x[n-1];
	for (int i = 0; i < n; i++)
		x[i] = tmp-x[i];
	
	reverse(x, x+n);
	reverse(p, p+n);
	
	res = max(res, answer());
	
	fout << res;
	
	fin.close();
	fout.close();
	return 0;
}
