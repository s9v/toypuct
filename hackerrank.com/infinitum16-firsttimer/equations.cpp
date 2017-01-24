#include <bits/stdc++.h>
#define sqr(X) (X)*(X)
using namespace std;

typedef long long llint;

llint x, y, a1, b1;

llint gcdext(llint a, llint b, llint &x, llint &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	llint x1, y1;
	llint g = gcdext(b - b/a*a, a, x1, y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return g;
}

double f(llint r) {
	return sqrt(sqr(x - r*b1) + sqr(y + r*a1));
}

int main() {
	int q;

	scanf("%d", &q);

	// assert(q > 100);

	while (q--) {
		llint a, b, c;

		scanf("%lld %lld %lld", &a, &b, &c);

		llint g = gcdext(a, b, x, y);

		// assert(c % g == 0);

		llint k = c/g;

		x *= k;
		y *= k;

		a1 = a/g;
		b1 = b/g;

		llint r = x/b1;

		while (x - r*b1 <= 0) {
			r--;
		}
		
		while (f(r-1) < f(r)) {
			r--;
		}

		llint ansx = x - r*b1;
		llint ansy = y + r*a1;

		// assert(ansx >= 0);
		// assert(a*ansx + b*ansy == c);

		// printf("%lld %lld\n", x, y);
		printf("%lld %lld\n", ansx, ansy);
	}

	return 0;
}
