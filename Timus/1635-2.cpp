#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <cmath>
using namespace std;
int dp[4005];
string s;
int n;
bool pol[4005][4005] = {false};
int path[4005][2] = {0};
int rec (int k)
{
	if (dp[k] != -1)
		return dp[k];
	
	if (pol[0][k])
	{
		path[k][0] = 0;
		path[k][1] = 1;
		return 1;
	}
	int mn = INT_MAX;
	for (int i = 1; i <= k; i++)
	{
		if (pol[i][k])
		{
			int res1 = rec(i - 1) + 1;
			if(res1 < mn)
			{
				mn = res1;
				path[k][0] = i;
				path[k][1] = 1;
			}
		}
		else
		{
			int res2 = rec(i - 1) + k - i + 1;
			if(res2 < mn)
			{
				mn = res2;
				path[k][0] = i;
				path[k][1] = k - i + 1;
			}
		}
	}
	if(mn == INT_MAX)
		mn = 0;
	return dp[k] = mn;
}
int main()
{
	memset(dp,255,sizeof dp);
	//freopen ("input.txt","r",stdin);
	//freopen ("output.txt","w",stdout);
	int m;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		int l = i;
		int r = i;
		int l1 = i;
		int r1 = i + 1;
		while(l >= 0 && r < n)
			if(s[l] == s[r])
				pol[l--][r++] = true;
			else
				break;

		while(l1 >= 0 && r1 < n)
			if(s[l1] == s[r1])
				pol[l1--][r1++] = true;
			else
				break;
	}
	printf ("%d\n",rec(n - 1));
	int p = n - 1;
	vector<string> resans;
	while (p >= 0)
	{
		int t = path[p][1];
		int len = p - path[p][0] + 1;
		p = path[p][0] - 1;
		if(t == 1)
			resans.push_back(s.substr(p + 1,len));
		else
		{
			for (int i = t; i >= 1; i--)
			{
				char str[2] = {0};
				str[0]  = s[p + i];
				resans.push_back(string(str));
			}
		}
	}
	for (int i = resans.size() - 1; i >= 0; i--)
		cout << resans[i] << " ";

    return 0;
}
}
