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

        long long min_a;
        if (ca < cb) {
            // min_a = a + max((b + mid) / cb * ca - max(ca - (b + mid) % cb - 1, 0LL), 0LL);
            min_a = (
                a + (b + mid) / cb * ca
                - ((b+mid)%cb+1 <= mid && (b + mid) / cb > 0) * max(ca - (b+mid)%cb-1, 0LL)
            );
        } else {
            min_a = a + max(mid - max(cb - b % cb - 1, 0LL), 0LL) + b / cb * ca;
        }

        // dbg(lo);
        // dbg(hi);
        // dbg(mid);
        // dbg(
        //     a + (b + mid) / cb * ca
        //     - ((b+mid)%cb+1 <= mid && (b + mid) / cb > 0) * (ca - (b+mid)%cb-1)
        // );
        // dbg(a + max(mid - max(cb - b % cb - 1, 0LL), 0LL) + b / cb * ca);
        // dbg(min_a);

        if (min_a >= fa) {
            ans = min(ans, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;            
        }

        // int new_lo = lo;
        // int new_hi = hi;
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

