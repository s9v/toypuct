//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int N;
int a[10000];
int v[10000];
vector<pair<int, int> > ps;

bool emulate(int i) {
  ps.clear();

  fill(v, v+N, 0);

  v[N-1] = 1;
  v[i] = 1;
  int x = a[N-1];
  ps.push_back(make_pair(a[i], a[N-1]));

  for (int j = N-1; j >= 0; j--) {
    if (v[j])
      continue;

    int o = x - a[j];
    // cerr << o << " THIS \n";
    int l = lower_bound(a, a+N, o) - a;
    int k = l;
    while (k+1 < j && v[k] && a[l] == a[k+1]) 
      k++;

    if (k >= j || v[k] || a[k] != o)
      return false;

    ps.push_back(make_pair(a[k], a[j]));

    v[j] = 1;
    v[k] = 1;
    x = a[j];
  }

  return true;
}

void solve() {
  cin >> n;
  N = 2*n;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a, a+N);
  
  for (int i = 0; i < N-1; i++)
    if (emulate(i)) {
      cout << "YES\n";

      cout << ps[0].first + ps[0].second << "\n";

      for (int j = 0; j < ps.size(); j++)
        cout << ps[j].first << " " << ps[j].second << "\n";
      
      return;
    }

  cout << "NO\n";
}

int main() {
  ps.reserve(2000);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
