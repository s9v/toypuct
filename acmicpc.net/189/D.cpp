#include <bits/stdc++.h>
#define ln(S) (S).length()
#define sz(V) (V).size()
#define pb push_back
using namespace std;

typedef vector<int> vi;

int d;

int main() {
	scanf("%d", &d);

	d = d % 100;

	if (d == 0) {
		printf("0");
		return 0;
	}

	for (int i = 1; i <= 7; i++) {
		if (d == 0) {
			printf("0");
			return 0;
		}
		else if (d <= i*5) {
			printf("%d", (d-1)/5 + 1);
			return 0;
		}
		else if (d <= 2*i*5) {
			d -= i*5;
			printf("%d", i - d/5);
			return 0;
		}
		else {
			d -= 2*i*5;
		}
	}

	return 0;
}