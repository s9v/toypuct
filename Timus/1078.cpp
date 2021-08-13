#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
pair<int, pair<int,int> > p[500];
int dp[500];
int pr[500]; // previous/parent - for traceback

bool inside(int i, int j)
{
	return p[i].first < p[j].first && p[j].second.first < p[i].second.first;
}

bool by_length(const pair<int, pair<int,int> > &a, const pair<int, pair<int,int> > &b)
{
	if (a.second.first-a.first == b.second.first-b.first)
		return a.first < b.first;
	return a.second.first-a.first < b.second.first-b.first;
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first;
		cin >> p[i].second.first;
		p[i].second.second = i;
		
		if (p[i].first > p[i].second.first)
			swap(p[i].first, p[i].second.first);
	}
	
	sort(p, p+n, by_length);
	
	fill(pr, pr+n, -1);
	fill(dp, dp+n, 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (inside(i, j) && dp[i] < dp[j]+1)
			{
				dp[i] = dp[j]+1;
				pr[i] = j;
			}
	
	int cur = max_element(dp, dp+n)-dp;
	stack<int> q;
	int res = 0;
	while (cur != -1)
	{
		q.push(p[cur].second.second);
		cur = pr[cur];
		res++;
	}
	
	cout << res << "\n";
	while ( ! q.empty())
	{
		cout << q.top()+1 << " ";
		q.pop();
	}
	
	return 0;
}
