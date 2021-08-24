#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int tests;
  cin >> tests;

  for (int caseno = 1; caseno <= tests; ++caseno) {
    long long n;
    cin >> n;

    long double e = 0;
    
    if (n <= 2000'000'000LL) {
        for (long long i = 1; i <= n; i++) {
          e += 1.0 / i;
        }
    } else {
        e = logl(n) + 0.577215664 + 1/(2*n) - 1/(12*n*n);
    }

    cout.precision(12);
    cout << "Case #" << caseno << ": " << e << "\n";
  }

  return EXIT_SUCCESS;
}
