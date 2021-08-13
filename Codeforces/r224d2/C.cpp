#include <iostream>
#include <algorithm>
#include <vector>
#define  sz(x)  (int)x.size()
#define  pb  push_back
#define  dbg(x)  cerr << #x << " : " << x << "\n"
using namespace std;
typedef vector<int> vi;

int n;
int a[100000];
vi  r;

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a, a+n);
	
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	
	if (a[0] == a[n-1])
	{
		cout << 1 << "\n";
		cout << a[0];
		return 0;
	}
	
	bool bad = 0;
	for (int i = 2; i < n; i++)
		if (a[0]-a[1] != a[i-1]-a[i])
		{
			bad = 1;
			break;
		}
	
	if (!bad)
	{
		r.pb(2*a[0]-a[1]);
		r.pb(2*a[n-1]-a[n-2]);
	}
	
	if (n == 2)
	{
		if (!((a[1]-a[0])&1))
			r.pb((a[1]+a[0])/2);
	}
	else
	{
		int cnt1 = 0;
		int cnt2 = 0;
		
		for (int i = 1; i < n; i++)
			if (a[1]-a[0] == a[i]-a[i-1])
				cnt1++;
		
		for (int i = 1; i < n; i++)
			if (a[2]-a[1] == a[i]-a[i-1])
				cnt2++;
		
		if (cnt1 == n-2 && a[1]-a[0] > 0)
		for (int i = 1; i < n; i++)
			if (2*(a[1]-a[0]) == (a[i]-a[i-1]))
				r.pb((a[i]+a[i-1])/2);
		
		if (cnt2 == n-2 && a[2]-a[1] > 0)
		for (int i = 1; i < n; i++)
			if (2*(a[2]-a[1]) == (a[i]-a[i-1]))
				r.pb((a[i]+a[i-1])/2);
	}
	
	sort(r.begin(), r.end());
	r.resize(unique(r.begin(), r.end())-r.begin());
	
	cout << sz(r) << "\n";
	
	for (int i = 0; i < sz(r); i++)
		cout << r[i] << " ";
	
	return 0;
}
