#include <iostream>
using namespace std;

void solve() {
    int a, b, ca, cb, fa;
    cin >> a >> b >> ca >> cb >> fa;
    int x = max((max(fa - a, 0) + ca - 1) / ca * 1LL * cb - b, 0LL);
    cout << x << "\n";
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        solve();
    }

    return 0;
}
