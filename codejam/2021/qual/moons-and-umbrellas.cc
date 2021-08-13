#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

// _????_
// _????C
// _????J
// C????_
// C????C
// C????J
// J????_
// J????C
// J????J

// char indices[] = {'_', 'C', 'J'};

inline int idx(char c) {
  if (c == '_')
    return 0;
  if (c == 'C')
    return 1;
  if (c == 'J')
    return 2;

  assert(false);
  return -1;
}

int dp[3][3][1001];

int solve() {
  int x, y;
  cin >> x >> y;

  string s;
  cin >> s;

  // precalc
  int cost[3][3] = {
    {0, 0, 0},
    {0, 0, x},
    {0, y, 0}
  };

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      dp[i][j][0] = cost[i][j];

  for (int l = 1; l <= s.length(); l++)
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        dp[i][j][l] = min(
          dp[i][1][l-1] + cost[1][j],
          dp[i][2][l-1] + cost[2][j]
        );
      }

  // calc
  int ans = 0;

  int len = 0;
  char start = '_';
  char end;
  for (int i = 0; i <= s.length(); ++i) {
    if (i < s.length() && s[i] == '?') {
      len++;
    } else {
      end = (i < s.length() ?s[i] :'_');
      int sidx = idx(start);
      int eidx = idx(end);

      ans += dp[sidx][eidx][len];

      len = 0;
      start = (i < s.length() ?s[i] :'_');
    }
  }

  return ans;
}

int main() {
  int tests;
  cin >> tests;

  for (int test = 1; test <= tests; ++test) {
    cout << "Case #" << test << ": " << solve() << endl;
  }

  return 0;
}

