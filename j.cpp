#include <bits/stdc++.h>
#define ln(S) (S).length()
#define mp make_pair
#define pb push_back
#define L first
#define R second
using namespace std;

typedef long long i64;
typedef pair<int, int> pi;

const int LARGE = 1e9;

int n;
int d;
pi seg[100100];
pi lefts[100100];
pi rights[100100];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &seg[i].L, &seg[i].R);

		if (seg[i].L > seg[i].R)
			swap(seg[i].L, seg[i].R);

		lefts[i].first = seg[i].L;
		lefts[i].second = i;

		rights[i].first = seg[i].R;
		rights[i].second = i;
	}

	sort(lefts, lefts+n);
	sort(rights, rights+n);

	scanf("%d", &d);

	// int ptl = 0;
	int ptr = 0;
	int inbound = 0;
	int ans = 0;

	for (int i = 0; i < n; ++i) { // i == ptl
		i64 boundl = lefts[i].first;
		i64 boundr = boundl + d;

		while (ptr < n && rights[ptr].first <= boundr) {
			if (boundl <= seg[rights[ptr].second].L)
				inbound++;

			ptr++;
		}

		ans = max(ans, inbound);

		if (seg[lefts[i].second].R <= boundr)
			inbound--;
	}

	printf("%d", ans);

	return 0;
}
