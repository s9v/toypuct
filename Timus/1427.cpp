#include <iostream>
#include <string>
#define  ln(A) (int)A.length()
#define  sz(A) (int)A.size()
using namespace std;
const int LRG = 1e9;

int sm, lg;
string s;
int ill[100005];
int dp[100005];

inline bool isill(char c)
{
	return !(isalpha(c) || c == ' ');
}

int main()
{
	cin >> sm >> lg;
	getline(cin, s); // dummy scan
	getline(cin, s);
	
	for (int i = 1; i <= ln(s); i++)
		ill[i] = ill[i-1]+isill(s[i-1]);

	fill(dp, dp+100005, LRG);
	dp[0] = 0;
	for (int i = 1, j, lst = 0; i <= ln(s); i++)
	{
		dp[i] = LRG;
		if (!isill(s[i-1]))
		{
			j = max(i - min(lg, i-lst), 0);
			dp[i] = dp[j]+1;
		}

		j = max(i-sm, 0);
		dp[i] = min(dp[i], dp[j]+1);

		if (isill(s[i-1]))
			lst = i;
	}

	cout << dp[ln(s)];

	/*
	cerr << "\n";
	for (int i = 1; i <= ln(s); i++)
		cerr << dp[i] << "";
	*/

	return 0;
}
