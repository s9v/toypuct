#include <iostream>
using namespace std;

string s, t;
int cnt[30];
int idx[30];

int main() {
  ios_base::sync_with_stdio(false);

  int tests;
  cin >> tests;

  for (int caseno = 1; caseno <= tests; ++caseno) {
    fill(cnt, cnt+26, 0);

    cin >> s;
    
    for (auto c: s) {
      cnt[c - 'a']++;
    }

    int maxcnt = *max_element(cnt, cnt+26);

    cout << "Case #" << caseno << ": ";
    if (maxcnt*2 > s.length()) {
      cout << "IMPOSSIBLE";
    } else {
      t = "";
      t.reserve(s.length());

      for (int i = 0; i < 26; i++) {
        idx[i] = t.length();

        char c = i + 'a';
        for (int j = 0; j < cnt[i]; j++) {
          t += c;
        }
      }

      for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        cout << t[(idx[c] + cnt[c]-1 + maxcnt) % t.length()];
        cnt[c]--;
      }
    }
    cout << "\n";
  }

  return EXIT_SUCCESS;
}
