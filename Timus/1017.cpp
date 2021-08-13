#include <iostream>

using namespace std;

typedef long long i64;

i64 n;
i64 res;
i64 dp[510][510];

int main() {
	cin >> n;
	
//	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-j][j-1];
		}
	}
	
	for (int i = 0; i < n; i++) {
		res += dp[n][i];
//		cerr << "dp[ " << n << " ][ " << i << " ] = " << dp[n][i] << "\n";
	}
	
	cout << res;
	
	return 0;
}
