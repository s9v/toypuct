#include <iostream>
#include <string>

using namespace std;

const int INF = (int)1e8;

string s;
int dp[110][110];
int prv[110][110];
char res[210]; int nres;

inline bool matches(char c1, char c2) {
	return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']'));
}

inline void add(char c) {
	res[nres++] = c;
}

inline void add2(char c) {
	if (c == '(' || c == ')')
		add('('), add(')');
	else
	if (c == '[' || c == ']')
		add('['), add(']');
}

void f(int L, int R) {
//	cerr << "f(" << L << "," << R << ")\n";
	if (R - L == 0)
		return;
		
	if (R - L == 1) {
		add2(s[L]);
		return;
	}
	
	if (prv[L][R] == -1) {
		add(s[L]);
		f(L+1, R-1);
		add(s[R-1]);
	} else {
		f(L, prv[L][R]);
		f(prv[L][R], R);
	}
}

/** Prev values
 * -1 -- {A}
 * +* -- AB
 * */

int main() {
	cin >> s;
	int ln = (int)s.length();
	
	for (int i = 0; i <= ln; i++)
		dp[i][i] = 0;
	
	for (int i = 0; i+1 <= ln; i++)
		dp[i][i+1] = 1;
	
	for (int l = 2; l <= ln; l++) {
		for (int i = 0; i+l <= ln; i++) {
			int L = i;
			int R = i+l;
			dp[L][R] = INF;
			
			if (dp[L][R] > dp[L+1][R-1] && matches(s[L], s[R-1])) {
				dp[L][R] = dp[L+1][R-1];
				prv[L][R] = -1;
			}
			
			for (int X = L+1; X < R; X++)
				if (dp[L][R] > dp[L][X] + dp[X][R]) {
					dp[L][R] = dp[L][X] + dp[X][R];
					prv[L][R] = X;
				}
		}
	}
	
	f(0, ln);
	
//	cerr << dp[0][ln] << "\n";
	for (int i = 0; i < nres; i++)
		cout << res[i];
	cout << "\n";
	
	/*
	for (int i = 0; i < ln; i++)
		for (int j = i+1; j <= ln; j++)
			cerr << "dp[ " << i << " ][ " << j << " ] = " << dp[i][j] << "\n";
	*/
	
	return 0;
}
