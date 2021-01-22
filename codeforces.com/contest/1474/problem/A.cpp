//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;

  string b;
  cin >> b;

  int last = -1;
  for (int i = 0; i < n; i++) {
    int cur = (b[i] - '0') + 1;

    if (cur == last) {
      cout << 0;
      cur--;
    } else {
      cout << 1;
    }

    last = cur;
  }

  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
