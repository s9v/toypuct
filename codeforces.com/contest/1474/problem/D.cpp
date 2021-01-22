//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cinttypes>
using namespace std;

int n;
int a[200100];
long long d[200100];
long long m[200100];

bool solve() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }

  d[0] = 0;
  for (int i = 0; i+1 < n; i++)
    d[i+1] = a[i] - d[i];

  m[n-1] = d[n-1];
  m[n-2] = d[n-2];
  for (int i = n-3; i >= 0; i--)
    m[i] = min(d[i], m[i+2]);

  if (d[n-1] == a[n-1] && m[0] >= 0 && m[1] >= 0)
    return true;
    
  for (int i = 0; i+1 < n; i++) {
    if (d[i] < 0)
      break;

    if (d[i+1] - a[i] + a[i+1] < 0)
      continue;

    if (i+2 < n && m[i+2] + 2*a[i] - 2*a[i+1] < 0)
      continue;

    if (i+3 < n && m[i+3] - 2*a[i] + 2*a[i+1] < 0)
      continue;

    if (i+1 == n-1) {
      if (d[n-1] - a[n-2] + a[n-1] == a[n-2])
        return true;
    }
    else {
      if ((n-1)%2 == (i+2)%2
          && d[n-1] + 2*a[i] - 2*a[i+1] == a[n-1])
        return true;
      else if ((n-1)%2 == (i+3)%2
          && d[n-1] - 2*a[i] + 2*a[i+1] == a[n-1])
        return true;
    }
  }

  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    // solve();
    printf("%s\n", solve() ?"YES" :"NO");
  }

  return 0;
}
