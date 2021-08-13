#include <iostream>
#include <vector>
#include <assert>

class Problem {
  int n;
  int x;
  std::vector<int> d;

public:
  Problem(int n, int x, std::vector<int> d) {
    this.n = n;
    this.x = x;
    this.d = d;
  }

  // Documentation here...
  void solve() {
    // Compress d
    // compress_d();
    compress_d_inplace();

    if (d.size() == 1 && d[0] < 0)
      return make_pair(1, d[0]+1);

    // Calculate btm, top
    assert(0 < d.size());

    int start = d[0] < 0;
    if (0 < start)
      x += d[0];

    std::vector<long long> btm, top;
    for (int i = start; i < n; i += 2) {
      btm.push_back(x);
      x += d[i]
      top.push_back(x);
      if (i+1 < n)
        x += d[i+1];
    }
    n = btm.size();

    for ( ... ) {
      if ( ... ) {
        auto [lis, lis_count] = calc_lis(s, e);
      } else {
        ...
      }
    }


    return make_pair(lis, lis_count);
  }

private:
  void compress_d() {
    std::vector<int> tempd;

    for (int i = 0; i < n; i++) {
      if (!tempd.isempty() && ((d[i] > 0) ^ (tempd[i] > 0)) == 0) {
        tempd.back() += d[i];
      } else {
        tempd.push_back(d[i]);
      }
    }

    d = tempd;
  }

  void compress_d_inplace() {
    int j = 0;
    for (int i = 1; i < n; ++i) {
      if (d[i] == 0)
        continue;
      
      if ((d[j] > 0 ^ d[i] > 0) == 0) {
        d[j] += d[i];
      } else {
        d[++j] = d[i];
      }
    }
    d.resize(j+1);
  }

  void count_lis(int s, int e) {
    // Calculate levels
    std::vector<long long> lvl = btm;
    for (auto x : top)
      lvl.push_back(x);

    sort(lvl.begin(), lvl.end());
    lvl.resize(unique(lvl.begin(), lvl.end()) - lvl.begin());

    // Count LIS using DP
    int m = e - s + 1;
    int k = lvl.size();
    vector<vector<int>> dp(m, vector<int>(k, 0));

    for (int i = m-1; i >= 0; --i) {
      dp[i][k-1] = 1;
      
      for (int l = k-2; l >= 0; --l) {
        dp[i][l] = 0;
        int j;

        // + dp[ next(i+1, l) ][l] // skip
        j = i+1;
        while (j < m && (lvl[l] < btm[s+j] || top[s+j] < lvl[l]))
          j++;

        if (j != m)
          dp[i][l] += dp[j][l];

        // + dp[ next(i, l+1) ][l+1] // choose
        j = i;
        while (j < m && (lvl[l+1] < btm[s+j] || top[s+j] < l+1))
          j++;

        if (j != m)
          dp[i][l] += dp[j][l+1];

        // + downhill*dp[ next(i+1, l+1) ][l+1]; // skip, choose downhill
        if (i+1 < m && btm[s+i+1]+1 <= l && l <= top[s+i]-1) { // downhill
          j = i+1;
          while (j < m && (l+1 < btm[s+j] || top[s+j] < l+1))
            j++;

          if (j != m)
            dp[i][l] += dp[j][l+1];
        }
      }
    }
  }
}

int main() {
  // Read input
  int n;
  std::cin >> n;

  int x;
  std::cin >> x;

  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    std::cin >> d[i];
  }

  // Solve problem
  Problem problem(n, x, d);
  auto [lis, lis_count] = problem.solve();

  // Output solution
  std::cout << lis << " " << lis_count;

  return 0;
}

