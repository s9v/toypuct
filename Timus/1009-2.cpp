# include <iostream>

using namespace std;

int dp[18][2];
int digit,base;

int main()
{
	cin >> digit >> base;
	
	dp[0][0] = 0;
	dp[0][1] = base-1;
	
	for (int i=1 ; i<=digit ; i++)
	{
		dp[i][0] = dp[i-1][1];
		dp[i][1] = (dp[i-1][0]+dp[i-1][1])*(base-1);
	}
	
	cout<<dp[digit-1][0]+dp[digit-1][1];
	
	return 0;
}
