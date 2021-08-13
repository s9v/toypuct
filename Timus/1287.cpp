#include <iostream>
using namespace std;

int n;
char grid[1405][1405];
int dp[1405][1405][4];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> grid[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			dp[i][j][0] = (grid[i][j] == grid[i][j-1])*dp[i][j-1][0] + 1; // <
			dp[i][j][1] = (grid[i][j] == grid[i-1][j])*dp[i-1][j][1] + 1; // ^
			dp[i][j][2] = (grid[i][j] == grid[i-1][j-1])*dp[i-1][j-1][2] + 1; // ^
		}

	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--)
		{
			dp[i][j][3] = (grid[i][j] == grid[i-1][j+1])*dp[i-1][j+1][3] + 1; // ^
		}

	int res = 0;
	char x = '?';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			tmp = max(dp[i][j][0], dp[i][j][1]);
			tmp = max(tmp, dp[i][j][2]);
			tmp = max(tmp, dp[i][j][3]);

			if (res < tmp)
			{
				res = tmp;
				x = grid[i][j];
			}
			else if (res == tmp)
				if (grid[i][j] != x)
					x = '?';
		}

	cout << x << "\n";
	cout << res;
	return 0;
}
