#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

int a[500][500];
int b[500][500];
int p[500];
  int N;

bool is_ok() {
  for (int i = 0; i < N; i++) {
    for (int j= 0; j < N; j++) {
      c[i][j] = a[i][j] != -1 || (bit & (1 << (i*N + j))) > 0;
    }
  }

  for (int i = 0; i < N; i++) {
    
  }
}

long long solve() {
  cin >> N;

  if (N > 4)
    return 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> b[i][j];
    }
  }
  
  int _;
  for (int i = 0; i < N; i++)
    cin >> _;
  for (int i = 0; i < N; i++)
    cin >> _;

  for (int i = 0; i < N; i++) {
    p[i] = i;
  }

  long long S = accumulate(&b[0][0], &b[N-1][N-1] + 1, 0);
  long long M = 0;

  for (int bit = 0; bit < (1<<(N*N)); bit++) {
    if (is_ok(bit)) {
      for (int i = 0; i < N; i++)
        
      M = min(M, s);
    }
  }

  return S - M;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << "\n";
  }

  return 0;
}
