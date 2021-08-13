#include <iostream>
#include <queue>
using namespace std;

int vis[300][300];
int g[300][300];

int dir[4][2] = {
  {0, -1},
  {0, +1},
  {-1, 0},
  {+1, 0},
};

long long solve() {
  // g_ij, time, i, j
  priority_queue<tuple<int, int, int>> pq;

  fill(&vis[0][0], &vis[299][299] + 1, 0);

  int R, C;
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> g[i][j];
      pq.push({g[i][j], i, j});
    }
  }

  long long ans = 0;

  while (!pq.empty()) {
    int _, i, j;
    tie(_, i, j) = pq.top();
    pq.pop();

    // cerr << "»" << _ << " " << i << " " << j << endl;

    if (vis[i][j])
      continue;

    vis[i][j] = 1;

    for (int d = 0; d < 4; d++) {
      int ii = i + dir[d][0];
      int jj = j + dir[d][1];

      // cerr << "-»" << ii << " " << jj << " " << g[ii][jj] << "<" << g[i][j] << "-1 " << endl;

      if (0 <= ii && ii < R &&
          0 <= jj && jj < C &&
          !vis[ii][jj] &&
          g[ii][jj] < g[i][j] - 1)
      {
        ans += g[i][j] - 1 - g[ii][jj];
        g[ii][jj] = g[i][j] - 1;
        pq.push({g[ii][jj], ii, jj});
      }
    }
  }

  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << "\n";
  }

  return 0;
}
