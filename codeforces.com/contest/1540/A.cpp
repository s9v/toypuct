#include <iostream>
#include <algorithm>
using namespace std;

int d[100100];

int main() {
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  
  while (T--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }

    sort(d, d+n);

    long long ans = 0LL;
    for (int i = 1; i < n; i++) {
      int k = d[i] - d[i-1];
      ans -= 1LL*i*(n-i)*k;
      ans += k;
    }

    cout << ans << endl;
  }
}
