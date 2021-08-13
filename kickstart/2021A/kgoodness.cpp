#include <iostream>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int g = 0;
    for (int i = 0; i < n/2; i++)
        g += s[i] != s[n-1-i];
    
    return abs(g-k);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << "\n";
    }
    
    return 0;
}
