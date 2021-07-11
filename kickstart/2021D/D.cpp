#include <iostream>
#include <vector>
using namespace std;

typedef long long i64;

const i64 LARGE = 1000LL * 1000 * 1000 * 1000;
i64 pow[41];

struct FenwickTree {
  vector<int> bit;
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }

  void set(int idx, int val) {
    int delta = val - (sum(idx) - sum(idx-1));
    add(idx, delta);
  }
};

int V(i64 x) {
  int lo = 0, hi = 40;
  int ans = lo;

  while (lo <= hi) {
    int mi = (lo + hi)/2;
    if (x % pow[mi] == 0) {
      ans = max(ans, mi);
      lo = mi+1;
    } else {
      hi = mi-1;
    }
  }

  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int tests;
  cin >> tests;

  for (int caseno = 1; caseno <= tests; caseno++) {
    int n, q, p;
    cin >> n >> q >> p;

    vector<FenwickTree> fts(4, FenwickTree(n));
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int pos, val, val_mod;
      pos = i;
      cin >> val;
      val_mod = val % p;

      i64 val_pow = 1LL;
      i64 val_mod_pow = 1LL;
      for (int i = 0; i < 4; i++) {
        val_pow *= val;
        val_mod_pow *= val_mod;
        fts[i].set(pos, V(val_pow - val_mod_pow));
      }
    }

    pow[0] = 1;
    for (int i = 1; i <= 40; i++) {
      if (pow[i-1] != LARGE + 1 && pow[i-1]*p <= LARGE)
        pow[i] = pow[i-1]*p;
      else
        pow[i] = LARGE + 1;
    }

    cout << "Case #" << caseno << ": ";

    for (int query = 0; query < q; query++) {
      int type;
      cin >> type;

      if (type == 1) {
        int pos, val, val_mod;
        cin >> pos >> val;
        val_mod = val % p;

        i64 val_pow = 1LL;
        i64 val_mod_pow = 1LL;
        for (int i = 0; i < 4; i++) {
          val_pow *= val;
          val_mod_pow *= val_mod;
          fts[i].set(pos, V(val_pow - val_mod_pow));
        }
      } else if (type == 2) {
        int s, l, r;
        cin >> s >> l >> r;
        cout << fts[s-1].sum(l-1, r-1) << " ";
      }
    }

    cout << endl;
  }
  
  return 0;
}
