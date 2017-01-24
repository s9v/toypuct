#include <bits/stdc++.h>
#define ln(S) (S).length()
#define sz(V) (V).size()
using namespace std;

bool is_arabic(string &s) {
	return isdigit(s[0]);
}

char one[4] = {'I', 'X', 'C', 'M'};
char five[4] = {'V', 'L', 'D', '?'};

int main() {
	int t;

	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		if (is_arabic(s)) {
			for (int i = 0; i < ln(s); ++i) {
				char c = s[i];

				if (c == '0') {
					// pass
				}
				else if (c <= '3') {
					for (int j = 0; j < c-'0'; ++j)
						cout << one[ln(s) - i - 1];
				}
				else if (c <= '8') {
					for (int j = 0; j < '5'-c; ++j)
						cout << one[ln(s) - i - 1];

					cout << five[ln(s) - i - 1];

					for (int j = 0; j < c-'5'; ++j)
						cout << one[ln(s) - i - 1];
				}
				else {
					for (int j = 0; j < '9'-c+1; ++j)
						cout << one[ln(s) - i - 1];

					cout << one[ln(s) - i];
				}

				// cerr << " ";
			}

			cout << "\n";
		}
		else {
			int res = 0;

			int mx = 0;

			int I = 1;
			int X = 10;
			int C = 100;
			int M = 1000;

			int V = 5;
			int L = 50;
			int D = 500;

			for (int i = ln(s)-1; i >= 0; --i)
			{
				if (s[i] == 'I') {
					res += (mx <= I ?+1 :-1) * I;
					mx = max(mx, I);
				}
				else if (s[i] == 'X') {
					res += (mx <= X ?+1 :-1) * X;
					mx = max(mx, X);
				}
				else if (s[i] == 'C') {
					res += (mx <= C ?+1 :-1) * C;
					mx = max(mx, C);
				}
				else if (s[i] == 'M') {
					res += (mx <= M ?+1 :-1) * M;
					mx = max(mx, M);
				}
				else if (s[i] == 'V') {
					res += (mx <= V ?+1 :-1) * V;
					mx = max(mx, V);
				}
				else if (s[i] == 'L') {
					res += (mx <= L ?+1 :-1) * L;
					mx = max(mx, L);
				}
				else if (s[i] == 'D') {
					res += (mx <= D ?+1 :-1) * D;
					mx = max(mx, D);
				}
			}

			cout << res << "\n";
		}
	}

	return 0;
}