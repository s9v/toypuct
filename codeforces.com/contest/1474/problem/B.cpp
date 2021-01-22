#include <iostream>
using namespace std;

bool is_prime(int x) {
  for (int i = 2; i*i <= x; i++)
    if (x%i == 0)
      return false;
  return true;
}

void solve() {
  int d;
  cin >> d;

  long long a = 1;
  int last = 1;
  for (int i = 1; i < 3; i++) {
    int j = last + d;

    while (!is_prime(j)) j++;

    a *= j;
    last = j;
  }

  cout << a << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
