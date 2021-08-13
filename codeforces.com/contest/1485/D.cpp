#include <iostream>
#include <array>
using namespace std;

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }

  return a;
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  int n, m;
  cin >> n >> m;
  array<array<int, 500>, 500> a;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  // int L = 1;
  // for (int i = 1; i <= 16; i++) {
  //   L = lcm(L, i);
  // }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 1) {
        cout << 720720 << " ";
      }
      else {
        cout << 720720 + a[i][j] * a[i][j] * a[i][j] * a[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}

