#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ok(long long a, long long b, long long c) {
  return a-b == b-c;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int t;
  cin >> t;

  for (int caseno = 1; caseno <= t; caseno++) {
    long long a, b, c, d, /*e,*/ f, g, h, i;
    cin >> a >> b >> c;
    cin >> d >> f;
    cin >> g >> h >> i;

    int ans = 0;
    ans += ok(a, b, c);
    ans += ok(g, h, i);
    ans += ok(a, d, g);
    ans += ok(c, f, i);

    vector<long long> x;
    if ((a+i) % 2 == 0)
        x.push_back(a+i);
    if ((b+h) % 2 == 0)
      x.push_back(b+h);
    if ((c+g) % 2 == 0)
      x.push_back(c+g);
    if ((d+f) % 2 == 0)
      x.push_back(d+f);

    sort(x.begin(), x.end());

    int maxcnt = 0;
    int cnt = 1;
    for (int i = 1; i <= x.size(); i++) {
      if (i == x.size() || x[i-1] != x[i]) {
        maxcnt = max(maxcnt, cnt);
        cnt = 1;
      } else {
        cnt++;
      }
    }

    ans += maxcnt;
    cout << "Case #" << caseno << ": " << ans << endl;
  }
  
  return 0;
}
