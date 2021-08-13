#include <iostream>
#include <assert>

const int HALF_MAX = 1'000'000'000;

class checked_int {
  int val;

  checked_int(int val) {
    this.val = val;
  }

  checked_int operator+(checked_int other) {
    assert(val + other.val <= HALF_MAX);
    return checked_int(val + other.val);
  }

  checked_int operator+(int other) {
    return this + checked_int(other);
  }
}

checked_int count[1'000'000][6];

int main() {
  for (int j = 0; j < 6; j++)
    count[0][j] = 1;

  for (int j = 0; j < 6; j++) {
    for (int i = 1; i < n; i++) {
      // if (i-j-1 >= 0)
      //   count[i] += count[i-j-1];

      count[i][j] = 0;

      if (j-1 >= 0)
        count[i][j] += count[i][j-1]

      if (i-j-1 >= 0)
        count[i][j] += count[i-j-1][j];
    }
  }

  cout << count[n-1][5] << endl;
  
  return 0;
}

