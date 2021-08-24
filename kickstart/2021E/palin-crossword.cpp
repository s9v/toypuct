#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

int nfound;
string grid[1100];
vector<pair<int, int>> adj[1100][1100];
bool vis[1100][1100];

void dfs(int x, int y, char c) {
  vis[x][y] = true;
  nfound += grid[x][y] == '.';
  grid[x][y] = c;

  for (auto neigh: adj[x][y]) {
    int xx, yy;
    tie(xx, yy) = neigh;

    if (!vis[xx][yy]) {
      dfs(xx, yy, c);
    }
  }
}

void solve(int caseno) {
  int N, M;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      adj[i][j].clear();
      vis[i][j] = false;
    }
  }

  for (int i = 0; i < N; i++) {
    cin >> grid[i];
  }

  for (int i = 0; i < N; i++) {
    int len = 0;
    for (int j = 0; j <= M; j++) {
      if (j == M || grid[i][j] == '#') {
        for (int k = 0; k < len/2; k++) {
          // i j-1-k  <==>  i j-len+k
          int j1 = j-1-k;
          int j2 = j-len+k;
          adj[i][j1].push_back(make_pair(i, j2));
          adj[i][j2].push_back(make_pair(i, j1));
        }

        len = 0;
      } else {
        len++;
      }
    }
  }

  for (int j = 0; j < M; j++) {
    int len = 0;
    for (int i = 0; i <= N; i++) {
      if (i == N || grid[i][j] == '#') {
        for (int k = 0; k < len/2; k++) {
          // i-1-k j  <==>  i-len+k j
          int i1 = i-1-k;
          int i2 = i-len+k;
          adj[i1][j].push_back(make_pair(i2, j));
          adj[i2][j].push_back(make_pair(i1, j));
        }

        len = 0;
      } else {
        len++;
      }
    }
  }

  nfound = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (isalpha(grid[i][j]) && !vis[i][j]) {
        dfs(i, j, grid[i][j]);
      }
    }
  }

  cout << "Case #" << caseno << ": " << nfound << "\n";
  for (int i = 0; i < N; i++) {
    cout << grid[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int tests;
  cin >> tests;

  for (int caseno = 1; caseno <= tests; ++caseno) {
    solve(caseno);
  }

  return EXIT_SUCCESS;
}
