#include <bits/stdc++.h>
#define sz(X) (int)(X).size()
using namespace std;

int a, b;
int a1, b1;
int a2, b2;

bool isok(int w, int h) {
	return (w <= a && h <= b) || (w <= b && h <= a);
}

int main() {
	scanf("%d %d", &a, &b);
	scanf("%d %d", &a1, &b1);
	scanf("%d %d", &a2, &b2);

	bool ans = 0;

	ans |= isok(a1 + a2, max(b1, b2));
	ans |= isok(a1 + b2, max(b1, a2));
	ans |= isok(b1 + b2, max(a1, a2));
	ans |= isok(b1 + a2, max(a1, b2));

	printf("%s\n", (ans ?"YES" :"NO"));

	return 0;
}