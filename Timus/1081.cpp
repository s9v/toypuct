#include <iostream>
#include <cstdio>

using namespace std;

#define DBG(x) cerr << #x << " : " << x << "\n";

int n, k;
int dp[50][2];

void f(int ln, int ex) {
//	cerr << ln << " : " << ex << "\t\t[";
	if (ex+1 <= k && k <= ex+dp[ln][0]) {
		cout << 0;
//		cerr << "]\n";
		
		if (ln > 1)
			f(ln-1, ex);
	} else if (ex+dp[ln][0]+1 <= k && k <= ex+dp[ln][0]+dp[ln][1]) {
		cout << 1;
//		cerr << "]\n";
		
		if (ln > 1)
			f(ln-1, ex+dp[ln][0]);
	}
}

int main() {
	cin >> n;
	cin >> k;
	
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
//		cerr << "dp[ " << i << " ][ " << 0 << " ] = " << dp[i][0] << "\n";
//		cerr << "dp[ " << i << " ][ " << 1 << " ] = " << dp[i][1] << "\n";
	}
	
	/*
	for (int i = 1; i <= dp[n][0] + dp[n][1]; i++) {
		cerr << "\t" << i << "\t:\t";
		k = i;
		f(n,0);
		cerr << "\n";
		getchar();
	}
	*/
	
//	DBG(dp[n][0] + dp[n][1]);
	
	if (1 <= k && k <= dp[n][0] + dp[n][1])
		f(n,0);
	else
		cout << -1;
	
	return 0;
}
