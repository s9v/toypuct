#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long double e, v;
const long double EPS = 10e-12;

void duo(long double cm, long double p, long double sofar, int r) {
  e += sofar * p * (r+1);

  if (cm < EPS) {
    return;
  }

  if (cm-v < EPS) {
    duo(0, p + cm, sofar * cm, r+1);
  } else {
    duo(cm - v, p + v, sofar * cm, r+1);
  }
}

void tri(long double c, long double m, long double p, long double sofar, int r) {
  e += sofar * p * (r+1);

  if (c-v < EPS) {
    duo(m + c/2, p + c/2, sofar * c, r+1);
  } else {
    tri(c-v, m+v/2, p+v/2, sofar * c, r+1);
  }

  if (m-v < EPS) {
    duo(c + m/2, p + m/2, sofar * m, r+1);
  } else {
    tri(c+v/2, m-v, p+v/2, sofar * m, r+1);
  }
}


int main() {
  std::ios::sync_with_stdio(false);
  cout.precision(12);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long double c, m, p;
    cin >> c >> m >> p >> v;

    e = 0;
    tri(c, m, p, 1, 0);
    cout << e << "\n";
  }

  return 0;
}
