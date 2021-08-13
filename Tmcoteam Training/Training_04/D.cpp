#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long llint;

llint lcm(llint a, llint b)
{
	return a/__gcd(a, b)*b;
}

int main()
{
	int n, t;
	llint x[50];

	while (true)
	{
		cin >> n >> t;

		if (n == 0 && t == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> x[i];

		for (int i = 0; i < t; i++)
		{
			llint ti;
			cin >> ti;

			llint sm = 0;
			llint lg = LLONG_MAX;
			for (int a = 0; a < n; a++)
			for (int b = a+1; b < n; b++)
			for (int c = b+1; c < n; c++)
			for (int d = c+1; d < n; d++)
			{
				llint l = lcm(lcm(x[a], x[b]), lcm(x[c], x[d]));

				sm = max(sm, ti/l*l);
				lg = min(lg, (ti+l-1)/l*l);
			}

			cout << sm << " " << lg << "\n";
		}
	}

	return 0;
}
