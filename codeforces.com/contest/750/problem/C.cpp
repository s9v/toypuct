#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 100;

int n;

int max2(int a, int b) {
	if (a == -INF)
		return b;
	
	if (b == -INF)
		return a;
	
	return max(a, b);
}

int min2(int a, int b) {
	if (a == -INF)
		return b;
	
	if (b == -INF)
		return a;
	
	return min(a, b);
}

int main() {
	cin >> n;
	
	int llim = -INF;
	int ulim = -INF;
	
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		//~ cerr << "-> " << llim << " .. " << ulim << "\n";
		
		int c, d;
		cin >> c >> d;
		
		if (d == 1)
			llim = max2(llim, 1900-sum);
		else if (d == 2)
			ulim = min2(ulim, 1899-sum);
		
		sum += c;
	}
	
	if (ulim == -INF)
		cout << "Infinity";
	else if (llim > ulim)
		cout << "Impossible";
	else
		cout << ulim + sum;
	
	return 0;
}
