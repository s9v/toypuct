#include <bits/stdc++.h>
using namespace std;

int main() {
	int total = 240;
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	total -= k;
	
	int res = 0;
	
	for (int i = 1; i <= n; i++)
	if (total < i*5)
		break;
	else {
		total -= i*5;
		res++;
	}
	
	cout << res;
	
	return 0;
}
