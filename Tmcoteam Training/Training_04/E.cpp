#include <iostream>
using namespace std;
typedef long long llint;

int n;
bool prm[1000001];

int main()
{
	fill(prm, prm+1000001, 1);
	prm[0] = prm[1] = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!prm[i])
			continue;

		for (llint j = 1LL*i*i; j <= 1000000; j += i)
		{
			prm[j] = 0;
		}
	}

	while (true)
	{
		cin >> n;

		if (n == 0)
			break;

		int res = -1;
		for (int i = 0; i <= 1000000; i++)
			if (prm[i] && prm[n-i])
			{
				res = i;
				break;
			}
		
		if (res == -1)
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << n << " = " << res << " + " << n-res << "\n";
	}

	return 0;
}
