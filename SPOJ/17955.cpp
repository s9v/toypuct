// 17955. Lalith Dosa

#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9+10;

int n, lis; // act. NOT lis BUT l"non-decreasing"s
int a[1000000];
int e[1000001];

int main()
{
	//cerr << "Buzinga\n";
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		a[i] -= i; // trick iz here
	}
	
	e[0] = -INF;
	fill(e+1, e+1000001, INF);
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= 0)
			continue;
		
		int idx = upper_bound(e, e+1000001, a[i]) - e;
		e[idx] = min(e[idx], a[i]);
	}
	
	for (lis = 1; lis <= n && e[lis] != INF; lis++);
	
	lis--;
	
	cout << n-lis;
	
	return 0;
}
