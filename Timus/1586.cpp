#include <iostream>
#include <cmath>

using namespace std;

const int MOD = (int)1e9 + 9;

int  n, res;
int  dp[10010][10][10];
bool gr[10][10][10];

bool isprime(int key) {
	if (key <= 1) return 0;
	if (key == 2) return 1;
	if (key%2 == 0) return 0;
	
	int till = (int)sqrt(key+0.0);
	for (int i = 3; i <= till; i+=2)
		if (key%i == 0)
			return 0;
	
	return 1;
}

int main() {
	cin >> n;
	
	/*
	for (int i = 100; i < 1000; i++)
		if (isprime(i))
			res++;
	*/
	
	for (int i = 100; i < 1000; i++)
		if (isprime(i)) {
			dp[3][i%100/10][i%10/1]++;
			gr[i%1000/100][i%100/10][i%10/1] = 1;
//			cerr << i%1000/100 << " " << i%100/10 << " " << i%10/1 << "\n";
		}
	
	for (int i = 4; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				for (int h = 0; h < 10; h++)
					if (gr[h][j][k]) {
						dp[i][j][k] = (dp[i][j][k] + dp[i-1][h][j]) % MOD;
					}
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			res = (res + dp[n][i][j]) % MOD;
	
	cout << res;
	
	return 0;
}
