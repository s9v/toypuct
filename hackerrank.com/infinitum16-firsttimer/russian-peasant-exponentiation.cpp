#include <bits/stdc++.h>
using namespace std;

int q;
int a, b, m;
long long k;

pair<int, int> mult(pair<int, int> x, pair<int, int> y) {
	int a = ((1LL * x.first * y.first) % m - (1LL * x.second * y.second) % m + m) % m;
	int b = ((1LL * x.first * y.second) % m + (1LL * x.second * y.first) % m) % m;
	return make_pair(a, b);
}

pair<int, int> powww(pair<int, int> x, long long n) {
	if (n == 1) {
		return x;
	}

	pair<int, int> t = powww(x, n/2);

	if (n & 1) {
		return mult(mult(t, t), x);
	}
	else {
		return mult(t, t);
	}
}

int main() {
	scanf("%d", &q);

	while (q--) {
		scanf("%d %d %lld %d", &a,  &b,  &k,  &m);

		pair<int, int> res = powww(make_pair(a, b), k);

		printf("%d %d\n", res.first, res.second);
	}

	return 0;
}