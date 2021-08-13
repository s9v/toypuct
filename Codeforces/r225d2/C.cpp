#include <iostream>
using namespace std;

int n;
bool a;
int ones;
long long res;

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		
		ones += a;
		res += (a == 0)*ones;
	}
	
	cout << res;
	
	return 0;
}
