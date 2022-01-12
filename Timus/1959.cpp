#include <iostream>
#include <set>
using namespace std;

int n, m;
int t[100100];
int p[100100];
int cnt[100100];
set<pair<int, int>> pq;

void update_cnt(int ch, int delta) {
    auto it = pq.find(make_pair(cnt[ch], ch));
    if (it != pq.end())
        pq.erase(it);

    cnt[ch] += delta;
    pq.insert(make_pair(cnt[ch], ch));
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> p[i];

    for (int i = 0; i < n; i++) {
        if (i < m) {
            update_cnt(p[i], +1);
        }
        if (n-m+1 <= i) {
            update_cnt(p[i-n+m-1], -1);
        }

        if (t[i] == 0) {
            t[i] = pq.rbegin()->second;
        }
    }

    pq.clear();

    for (int i = 0; i < m; i++) {
        if (i == 0) {
            for (int j = 0; j < n-m+1; ++j)
                update_cnt(t[j], +1);
        } else {
            update_cnt(t[i-1], -1);
            update_cnt(t[n-m+i], +1);
        }

        if (p[i] == 0) {
            p[i] = pq.rbegin()->second;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << t[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < m; ++i)
        cout << p[i] << " ";
    cout << "\n";

    return 0;
}
