#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cost(int n, vector<int> &L) {
    int cost = 0;
    for (int i = 0; i < n-1; i++) {
        int minj = i;
        
        for (int j = i; j < n; j++) {
            if (L[j] < L[minj])
                minj = j;
        }
        
        reverse(L.begin() + i, L.begin() + minj + 1);
        
        cost += minj - i + 1;
    }
    
    return cost;
}

void solve() {
  int n, c;
  cin >> n >> c;
  
  vector<int> v;
  
  for (int i = 1; i <= n; i++)
    v.push_back(i);
  
  do {
      if (cost(n, v) == c) {
          for (int i = 0; i < n; i++)
            cout << v[i] << " ";
            
          return;
      }
  } while (next_permutation(v.begin(), v.end()));
  
  cout << "IMPOSSIBLE";
}

int main() {
  int tests;
  cin >> tests;

  for (int test = 1; test <= tests; ++test) {
    cout << "Case #" << test << ": ";
    solve();
    cout << endl;
  }
  
  return 0;
}

