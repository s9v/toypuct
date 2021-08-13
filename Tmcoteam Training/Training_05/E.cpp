#include <iostream>
using namespace std;
typedef long long llint;

llint a, b;

llint nike(llint a, llint b, llint x)
{
	if (a > b)
		return 0;
	return max(0LL, b/x - (a-1)/x);
}

int main()
{
	while (true)
	{
		cin >> a >> b;
		
		if (a == 0 && b == 0)
			break;
		
		long long res = 0;
		for (llint x = 1; x < 50000; x++)
		{
			res += nike(a, b, x);
			res += nike(max(a, 50000*x), b, x);
		}
		
		cout << res << "\n";
	}
	
	
	return 0;
}
