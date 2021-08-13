#include <iostream>
#include <cmath>
using namespace std;
typedef long long llint;

llint n;

int main()
{
	while (true)
	{
		cin >> n;

		if (n == 0)
			break;

		llint sn = sqrt(n);

		llint res = n;
		for (llint x = 2; x <= sn; x++)
		{
			if (n/x*x != n)
				continue;

			res = res*(x-1)/x;

			while (n/x*x == n)
				n /= x;
		}

		if (n > 1)
			res = res*(n-1)/n;

		cout << res << "\n";
	}

	return 0;
}
