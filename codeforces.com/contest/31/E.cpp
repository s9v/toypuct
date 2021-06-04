#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long ten[19];
long long dp[2001][1001];
int prv[2001][1001];

int main() {
  int n;
  cin >> n;
  string A;
  cin >> A;
  reverse(A.begin(), A.end());
  for (int i = 0; i < 2*n; i++)
    A[i] -= '0';

  ten[0] = 1;
  for (int i = 1; i <= 18; i++)
    ten[i] = ten[i-1]*10;

  dp[1][0] = A[0];
  prv[1][0] = 0; // H
  dp[1][1] = A[0];
  prv[1][1] = 1; // M
  
  for (int i = 1; i+1 <= 2*n; i++) {
    for (int j = max(0, i-n); j <= min(i, n); j++) {
      long long homer = dp[i][j] + ten[i-j]*A[i];
      if (dp[i+1][j] <= homer) {
        dp[i+1][j] = homer;
        prv[i+1][j] = 0; // H
      }

      long long marge = dp[i][j] + ten[j]*A[i];
      if (dp[i+1][j+1] <= marge) {
        dp[i+1][j+1] = marge;
        prv[i+1][j+1] = 1; // M
      }
    }
  }

  int i = 2*n;
  int j = n;
  while (i > 0) {
    if (prv[i][j]) {
      cout << "M";
      i--;
      j--;
    }
    else {
      cout << "H";
      i--;
    }
  }
  cout << endl;

  return 0;
}

