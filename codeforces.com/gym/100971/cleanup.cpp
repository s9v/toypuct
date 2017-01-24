#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, pair<int, int>> pxi[1000];

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		pxi[i].second.second = i;
		cin >> pxi[i].second.first;
		cin >> pxi[i].first;
	}

	sort(pxi, pxi+n);

	for (int i = 0; i < n; ++i)
	{
		cout << pxi[i].second.first << " ";
		cout << pxi[i].first << " i=";
		cout << pxi[i].second.second << "\n";
	}

	return 0;
}