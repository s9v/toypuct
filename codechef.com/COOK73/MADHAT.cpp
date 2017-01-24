#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int t;

vector<int> gr[100100];

int calc(int v) {
	int res = 1;

	for (auto w: gr[v]) {
		int tmp = calc(w);
		res = ( 1LL * tmp * res ) % MOD;
	}

	return res;
}

int main()
{
	cin >> t;

	while (t--)
	{
		int n;
		int c[100100];
		int p[100100];
		cin >> n;

		c[0] = n;
		for (int i = 1; i <= n; ++i)
			cin >> c[i];
		// c[n+1] = 0;

		stack<int> st;
		for (int i = 0; i <= n; ++i)
		{
			while (! st.empty() && st.top() + c[st.top()] < i)
				st.pop();

			p[i] = i + c[i];

			if (p[i] == n+1)
				p[i] = 0;
		}

		for (int i = 0; i <= n; ++i)
			gr[ p[i] ].push_back(i);

		cout << calc(0) << "\n";

		for (int i = 0; i <= n; ++i)
			gr[i].clear();
	}
}
