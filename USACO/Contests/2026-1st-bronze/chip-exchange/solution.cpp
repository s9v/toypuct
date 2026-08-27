#include <iostream>
using namespace std;

#define dbg(X) cerr << #X << ": " << X << "\n"

void solve() {
    long long a, b, ca, cb, fa;
    cin >> a >> b >> ca >> cb >> fa;

    long long lo = 0;
    long long hi = 1LL << 30;
    long long ans = 1LL << 30;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;

        long long min_a = min(
            a + max((b + mid) / cb * ca - max(ca - (b + mid) % cb - 1, 0LL), 0LL),
            max((a + mid) - max(cb - b % cb - 1, 0LL), 0LL) + b / cb * ca
        );

        // dbg(lo);
        // dbg(hi);
        // dbg(mid);

        // dbg(a + (b + mid) / cb * ca - max(ca - (b + mid) % cb - 1, 0LL));
        // dbg((a + mid) + b / cb * ca - max(cb - b % cb - 1, 0LL));
        // dbg(min_a);

        if (min_a >= fa) {
            // dbg(a + mid + b / cb * ca);
            // dbg(a + (b + mid) / cb * ca);
            // dbg(a + (b + mid) / cb * ca + ((b + mid) % cb + 1 - ca));
            ans = min(ans, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;            
        }

        // int new_lo = lo;
        // int new_hi = lo;
        // dbg(new_lo);
        // dbg(new_hi);
        // cerr << "\n";
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

