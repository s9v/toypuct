#include <iostream>
using namespace std;

int n;
int list[100];

void solve() {
  int c;
  cin >> n >> c;

  if ((n-1)*n/2 < c) {
    cout << "IMPOSSIBLE";
    return;
  }

  // construct
  int s = 0;
  bool r = false;

  for (int i = 1; i <= n; i++) {
    if (i-1 <= c) {
      if (r) {
        list[s] = i;
        s++;
        // construct(i+1, c-i+1, s+1, !reverse);
      }
      else {
        list[s+n-i] = i;
        // construct(i+1, c-i+1, s, !reverse);
      }
      c -= i-1;
      r ^= 1;
    } else {
      int ss = s;
      for (int j = i+1; j <= n; ++j) {
        if (j-i-1 == c)
          list[ss++] = i;
        list[ss++] = j;
      }

      if (r)
        reverse(list+s, list+s+n-i+1);
    }
  }

  for (int i = 0; i < n; i++)
    cout << list[i] << " ";
}

int main() {
  int tests;
  cin >> tests;

  for (int test = 1; test <= tests; ++tests) {
    cout << "Case #" << test << ": ";
    solve();
    cout << endl;
  }
  
  return 0;
}

