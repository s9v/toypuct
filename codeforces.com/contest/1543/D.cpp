#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, k;
int r;

int kor(int a, int b) {
  int pw = 1;
  int t = 0;

  while (a > 0 || b > 0) {
    t += (a%k + b%k)%k * pw;
    pw *= k;
    a /= k;
    b /= k;
  }

  return t;
}

int invkor(int a, int t) {
  int pw = 1;
  int b = 0;

  while (a > 0 || t > 0) {
    b += (k + t%k - a%k)%k * pw;
    pw *= k;
    a /= k;
    t /= k;
  }

  return b;
}

int main() {
  std::ios::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> k;

    int last = 0;
    bool inv = false;
    for (int cur = 0; cur < n; cur++) {
      if (!inv) {
        cout << kor(last, cur) << endl;
        last = cur;
      } else {
        cout << kor(last, invkor(cur, 0)) << endl;
        last = invkor(cur, 0);
      }

      cin >> r;

      if (r == -1)
        return 0;
      else if (r == 1)
        break;

      inv ^= true;
    }
  }

  return 0;
}
