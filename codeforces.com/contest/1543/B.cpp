#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
    }

    cout << (sum%n) * (n - sum%n) << "\n";
  }

  return 0;
}
