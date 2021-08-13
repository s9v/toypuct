/*
 * NOTE: This is correct solution.
 * But it needs Long Arithmetic.
 * See timus1513.java instead for correct solution.
 * */

#include <iostream>
#include <numeric>
using namespace std;
typedef long long llint;

int n, k;
llint dp[2][10001];

int main()
{
	cin >> n >> k;
	
	dp[0][0] = 1;
	for (int a = 0; a <= n; a++)
	{
		for (int b = 0; b <= n; b++)
			cerr << dp[a%2][b] << " ";
		cerr << "\n";
		
		fill(dp[(a+1)%2], dp[(a+1)%2]+10001, 0);
		
		if (a != n)
		for (int b = 0; b <= k; b++)
		{
			if (b+1 <= k)
				dp[(a+1)%2][b+1] += dp[a%2][b];
			dp[(a+1)%2][0] += dp[a%2][b];
		}
	}
	
	cout << accumulate(dp[n%2]+0, dp[n%2]+k+1, 0LL);
	
	return 0;
}
