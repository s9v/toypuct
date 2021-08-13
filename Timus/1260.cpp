# include <iostream>

using namespace std;

typedef long long i64;

i64 n, res;
i64 dp[60][2][3];

int main()
{
	cin >> n;
	
	if(n <= 3) {
		if(n == 1) cout << 1;
		if(n == 2) cout << 1;
		if(n == 3) cout << 2;
		return 0;
	}
	
	dp[4][0][0] = 0;
	dp[4][0][1] = 1;
	dp[4][1][0] = 1;
	dp[4][1][1] = 1;
	dp[4][1][2] = 1;
	
	for (int x=5; x<=n; x++) {
		dp[x][0][0] = dp[x-1][0][1];
		dp[x][0][1] = dp[x-1][0][0] + dp[x-1][1][0];
		dp[x][1][0] = dp[x-1][1][1];
		dp[x][1][1] = dp[x-1][1][1] + dp[x-1][1][2];
		dp[x][1][2] = dp[x-1][1][0];
	}
	
	res = 0;
	for (int i=0; i<2; i++)
		for (int j=0; j<3; j++)
			res += dp[n][i][j];
	
	cout << res;
	cout << "\n";
	return 0;
}
