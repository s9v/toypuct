#include <iostream>
using namespace std;
typedef long long llint;

llint a, b, c;
llint x, w;
llint k;
llint res = 0;

int main()
{
	cin >> a >> b >> w >> x >> c;
	
	llint lo = 0, hi = 2e12, t;
	while (lo <= hi) {
		t = (lo+hi)/2; // mid
		
		if (t*x-b < 0)
			k = 0;
		else
			k = (t*x-b + w-1)/w;
		
		if (c-t <= a-k) {
			res = t;
			hi = t-1;
		}
		else
			lo = t+1;
	}
	
	cout << res;
	
	return 0;
}
