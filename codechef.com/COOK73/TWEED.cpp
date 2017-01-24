#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
	cin >> t;

	while (t--)
	{
		int n;
		int a[60];
		string first;
		cin >> n >> first;

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		cout << (first == "Dee" && n == 1 && a[0] % 2 == 0 ?"Dee" :"Dum") << "\n";
	}
}
