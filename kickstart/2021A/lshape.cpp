#include <iostream>
using namespace std;

int grid[1000][1000];
int ltr[1000][1000];
int rtl[1000][1000];
int ttb[1000][1000];
int btt[1000][1000];

long long solve() {
  int R, C;
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> grid[i][j];
    }
  }

  // partial sums
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (j-1 < 0 || !grid[i][j]) {
        ltr[i][j] = grid[i][j];
      }
      else {
        ltr[i][j] = ltr[i][j-1] + 1;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = C-1; j >= 0; j--) {
      if (j+1 >= C || !grid[i][j]) {
        rtl[i][j] = grid[i][j];
      }
      else {
        rtl[i][j] = rtl[i][j+1] + 1;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (i-1 < 0 || !grid[i][j]) {
        ttb[i][j] = grid[i][j];
      }
      else {
        ttb[i][j] = ttb[i-1][j] + 1;
      }
    }
  }

  for (int i = R-1; i >= 0; i--) {
    for (int j = 0; j < C; j++) {
      if (i+1 >= R || !grid[i][j]) {
        btt[i][j] = grid[i][j];
      }
      else {
        btt[i][j] = btt[i+1][j] + 1;
      }
    }
  }

  long long lcnt = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      for (const auto &a: {ltr[i][j], rtl[i][j]}) {
        for (const auto &b: {ttb[i][j], btt[i][j]}) {
          lcnt += max(0, min(a, b/2) - 1);
          lcnt += max(0, min(a/2, b) - 1);
        }
      }
    }
  }

  return lcnt;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << "\n";
  }

  return 0;
}
