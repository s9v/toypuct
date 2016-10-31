#include <bits/stdc++.h>
#define ln(S) (S).length()
#define mp make_pair
#define pb push_back
using namespace std;

int n;
int a[10000];

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a+n);
	
	for (int k = 0; k <= n; k++)
	{
		if ((n-k >= n || n-k < 0 || a[n-k] >= k) && (n-k-1 >= n || n-k-1 < 0 || a[n-k-1] <= k)) {
			cout << k;
			return 0;
		}
	}

	return 0;
}
