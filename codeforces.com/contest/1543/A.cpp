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
    long long a, b;
    cin >> a >> b;

    if (a > b) {
      swap(a, b);
    }

    if (a == b) {
      cout << "0 0\n";
    } else {
      cout << b-a << " " << min(b%(b-a), b-a - b%(b-a)) << "\n";
    }
  }

  return 0;
}
