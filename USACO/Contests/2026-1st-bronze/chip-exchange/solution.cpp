#include <iostream>
using namespace std;

#define dbg(X) cerr << #X << ": " << X << "\n"

void solve() {
    long long a, b, ca, cb, fa;
    cin >> a >> b >> ca >> cb >> fa;

    long long lo = 0;
    long long hi = 1LL << 60;
    long long ans = 1LL << 60;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;

        long long min_a = min(
            a + (b + mid) / cb * ca - max(ca - (b + mid) % cb - 1, 0LL),
            (a + mid) + b / cb * ca - max(cb - b % cb - 1, 0LL)
        );

        if (min_a >= fa) {
            // dbg(mid);
            // dbg(a + mid + b / cb * ca);
            // dbg(a + (b + mid) / cb * ca);
            // dbg(a + (b + mid) / cb * ca + ((b + mid) % cb + 1 - ca));
            // dbg(min_a);
            // cerr << "\n";
            ans = min(ans, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;            
        }
    }

    cout << ans << "\n";
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        solve();
    }

    return 0;
}

