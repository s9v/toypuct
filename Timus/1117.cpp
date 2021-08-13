#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long i64;
const i64 INF = (1LL<<31);

i64 sender, recipient;
i64 bin[50]; i64 nbin;
i64 lib[50]; i64 nlib;

void init() {
	i64 x = 2;
	i64 y = 0;
	while (1) {
		/*
		cerr << nlib << " :\n";
		cerr << "Length : " << x << "\n";
		cerr << "Sum : " << y << "\n";
		getchar();
		*/
		
		bin[nbin++] = x;
		lib[nlib++] = y;
		
		if (x >= INF) break;
		
		x = 2*x + 2;
		y = 2*(y + nbin);
	}
}

i64 f(int k) {
	i64 res = 0;
	i64 etc = 0;
	k--;
	
	for (int i = nbin-1; i >= 0; i--) {
		int mid = etc + bin[i]/2;
		
		if (k <= mid-1) {
			continue;
		} else if (mid <= k && k <= mid+1) {
			res = res + lib[i-1] + i*(k-mid+1);
			break;
		} else if (mid+2 <= k) {
			etc = mid+1;
			res = res + lib[i-1] + i*2;
		}
	}
	
	return res;
}

int main() {
//	cerr << INF << "\n";
	init();
	
	cin >> sender;
	cin >> recipient;
//	cerr << f(sender);
	cout << (int)abs(f(recipient) - f(sender));
	
	return 0;
}
