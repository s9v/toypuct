#include <bits/stdc++.h>
#define ln(S) (S).length()
#define sz(V) (V).size()
#define pb push_back
using namespace std;

typedef vector<int> vi;

const int LARGE = 1e9;

int cut1[510];
int cut2[510];
int data[510][510];
int foo[510][510];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			scanf("%d", &foo[i][j]);
			
			data[i][j] = foo[i][j] ?LARGE :0;
		}

	for(int j = 0; j < m; j++) {
		scanf("%d", &cut1[j]);

		for (int i = 0; i < n; ++i) {
			data[i][j] = min(data[i][j], cut1[j]);
		}
	}

	for (int i = n-1; i >= 0; --i)
		scanf("%d", &cut2[i]);

	for (int i = 0; i < n; ++i) {
		for(int j = 0; j < m; j++) {
			data[i][j] = min(data[i][j], cut2[i]);
		}
	}

	for(int j = 0; j < m; j++) {
		int mx = 0;

		for (int i = 0; i < n; ++i) {
			mx = max(mx, data[i][j]);
		}

		if (mx != cut1[j]) {
			printf("-1");
			return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		int mx = 0;

		for(int j = 0; j < m; j++) {
			mx = max(mx, data[i][j]);
		}

		if (mx != cut2[i]) {
			printf("-1");
			return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			if (foo[i][j] == 0 && data[i][j] != 0) {
				printf("-1");
				return 0;
			}
			else if (foo[i][j] != 0 && data[i][j] == 0) {
				printf("-1");
				return 0;
			}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", data[i][j]);

			if (j != m-1)
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}