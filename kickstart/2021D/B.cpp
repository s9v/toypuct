#include <iostream>
#include <tuple>
#include <iterator>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

long long l[100100];
long long r[100100];
int ps[200100];

int main() {
  std::ios_base::sync_with_stdio(false);
  int tests;
  cin >> tests;

  for (int caseno = 1; caseno <= tests; caseno++) {
    int n;
    long long c;
    cin >> n;
    cin >> c;
    fill(ps, ps+2*n, 0);

    vector<long long> ord;
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
      
      ord.push_back(l[i]+1);
      ord.push_back(r[i]);
    }

    sort(ord.begin(), ord.end());
    ord.erase(unique(ord.begin(), ord.end()), ord.end());

    for (int i = 0; i < n; i++) {
      if (l[i] + 1 <= r[i] - 1) {
        int j;

        j = lower_bound(ord.begin(), ord.end(), l[i]+1) - ord.begin();
        ps[j]++;
        
        j = lower_bound(ord.begin(), ord.end(), r[i]) - ord.begin();
        ps[j]--;
      }
    }

    vector<tuple<int, long long>> cuts;
    long long ans = n;
    int sum = 0;
    for (int i = 0; i+1 < ord.size(); i++) {
      sum += ps[i];
      cuts.push_back(make_tuple(sum, ord[i+1] - ord[i]));
    }

    sort(cuts.begin(), cuts.end());
    for (int i = (int)cuts.size() - 1; i >= 0 && c > 0; i--) {
      long long cut = min(c, get<1>(cuts[i]));
      c -= cut;
      ans += cut * get<0>(cuts[i]);
    }
    
    cout << "Case #" << caseno << ": " << ans << endl;
  }
  
  return 0;
}
