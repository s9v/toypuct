#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int n;
int cnv[6000];
vector<int> gr[6000];
bool vis[6000];
int dp[6000][2];

void nike(int v)
{
	if (vis[v])
		return;

	vis[v] = true;
	for (size_t i = 0; i < gr[v].size(); i++)
	{
		int u = gr[v][i];
		nike(u);
	}

	dp[v][0] = 0; 
	for (size_t i = 0; i < gr[v].size(); i++)
	{
		int u = gr[v][i];
		dp[v][0] += max(dp[u][0], dp[u][1]);
	}

	dp[v][1] = max(cnv[v], 0);
	for (size_t i = 0; i < gr[v].size(); i++)
	{
		int u = gr[v][i];
		dp[v][1] += dp[u][0];
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> cnv[i];
	
	while (true)
	{
		int x, X;
		cin >> x >> X;

		if (x == 0 && X == 0)
			break;

		x--;
		X--;
		gr[X].push_back(x);
	}

	int lst = -1;
	for (int v = 0; v < n; v++)
		if (!vis[v])
		{
			nike(v);
			lst = v;
		}

	assert(lst != -1);

	cout << max(dp[lst][0], dp[lst][1]);

	return 0;
}
