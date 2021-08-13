#include <iostream>
using namespace std;

int main() {
  int n;
  string X;
  string MH = "";
  cin >> n >> X;

  int left_a = n;
  int left_b = n;
  string S_a = "";
  string S_b = "";
  int used = 0;

  while (used < 2*n) {
    if (left_a >= left_b) {
      int argmax_i = used;
      for (int i = used+1; i <= 2*n - left_a; i++)
        if (X[argmax_i] < X[i])
          argmax_i = i;

      for (int i = used; i <= argmax_i - 1; i++) {
        S_b += X[i];
        MH += 'M';
        left_b--;
      }

      S_a += X[argmax_i];
      MH += 'H';
      left_a--;

      used = argmax_i + 1;
    } else {
      int argmax_i = used;
      for (int i = used+1; i <= 2*n - left_b; i++)
        if (X[argmax_i] < X[i])
          argmax_i = i;

      for (int i = used; i <= argmax_i - 1; i++) {
        S_a += X[i];
        MH += 'H';
        left_a--;
      }

      S_b += X[argmax_i];
      MH += 'M';
      left_b--;

      used = argmax_i + 1;
    }
  }

  cout << MH << endl;

  return 0;
}
