#include <iostream>
#include <algorithm>
using namespace std;

int T;
int n;

int main()
{
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		cin >> n;

		int res;
		cin >> res;
		for (int i = 1; i < n; i++)
		{
			int x;
			cin >> x;
			res = res/__gcd(res, x)*x;
		}

		cout << res << "\n";
	}

	return 0;
}
