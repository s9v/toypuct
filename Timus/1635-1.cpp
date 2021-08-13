#include <iostream>
#include <string>

using namespace std;

const short int INF = 8000;

string s;
short int dp[4010];
short int pr[4010];
bool pl[4010][4010];

void f(int r) {
	if (r == 0)
		return;
	
	f(pr[r]);
	for (int i = pr[r]; i < r; i++)
		cout << s[i];
	cout << " ";
}

int main() {
	cin >> s;
	int ln = (int)s.length();
	
	
	for (int i = 0; i <= ln; i++) {
		pl[i][i] = 1;
		
		int L = i;
		int R = i;
		
		while (0 <= L && L <= ln-1 && 0 <= R && R <= ln-1 && s[L] == s[R]) {
			pl[L][R+1] = 1;
			L--;
			R++;
		}
		
		L = i;
		R = i+1;
		
		while (0 <= L && L <= ln-1 && 0 <= R && R <= ln-1 && s[L] == s[R]) {
			pl[L][R+1] = 1;
			L--;
			R++;
		}
	}
	
	dp[0] = 0;
	for (int i = 1; i <= ln; i++) {
		dp[i] = INF;
		
		for (int j = 0; j < i; j++)
			if (dp[i] > dp[j] + 1 && pl[j][i]) {
				dp[i] = dp[j] + 1;
				pr[i] = j;
			}
	}
	
	cout << dp[ln] << "\n";
	
	f(ln);
	
	return 0;
}
