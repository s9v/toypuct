#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long llint;

string s;
int n;
int p, e;

int binpow(int a, int n)
{
	int ret = 1;

	while (n > 0)
	{
		if (n&1)
		{
			ret *= a;
			n--;
		}

		a *= a;
		n >>= 1;
	}

	return ret;
}

int main()
{
	while (true)
	{
		getline(cin, s);

		if (s == "0")
			break;

		istringstream sin(s);

		n = 1;
		while (sin >> p >> e)
			n *= binpow(p, e);

		n--;

		int sn = sqrt(n);
		vector< pair<int, int> > res;
		for (int i = 2; i <= sn; i++)
		{
			if (n/i*i != n)
				continue;

			int cnt = 0;
			while (n/i*i == n)
			{
				n /= i;
				cnt++;
			}

			res.push_back(make_pair(i, cnt));
		}

		if (n > 1)
			res.push_back(make_pair(n, 1));

		sort(res.begin(), res.end(), greater< pair<int, int> >());

		for (int i = 0; i < (int)res.size(); i++)
		{
			cout << res[i].first << " " << res[i].second;
			
			if (i != (int)res.size()-1)
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
