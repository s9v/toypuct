#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

typedef long long i64;
typedef pair<i64, i64> range;

struct item {
  range key;
  i64 prior;
  item * l, * r;
  item() { }
  item (range key, int prior)
    : key(key), prior(prior), l(nullptr), r(nullptr) { }
};
typedef item * pitem;

void split(pitem t, range key, pitem & l, pitem & r) {
  if (!t)
    l = r = nullptr;
  else if (key < t->key)
    split(t->l, key, l, t->l),  r = t;
  else
    split(t->r, key, t->r, r),  l = t;
}

void insert(pitem & t, pitem it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior)
    split(t, it->key, it->l, it->r),  t = it;
  else
    insert(it->key < t->key ? t->l : t->r, it);
}

void merge(pitem & t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r),  t = l;
  else
    merge(r->l, l, r->l),  t = r;
}

void erase(pitem & t, range key) {
  if (t->key == key) {
    pitem th = t;
    merge(t, t->l, t->r);
    delete th;
  }
  else
    erase(key < t->key ? t->l : t->r, key);
}

pitem find_l(pitem t, i64 s) {
  if (!t)
    return nullptr;

  if (t->key.first <= s) {
    pitem r = find_l(t->r, s);
    return r ? r : t;
  } else {
    return find_l(t->l, s);
  }
}

pitem find_r(pitem t, i64 s) {
  if (!t)
    return nullptr;

  if (s <= t->key.second) {
    pitem l = find_r(t->l, s);
    return l ? l : t;
  } else {
    return find_r(t->r, s);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int tests;
  cin >> tests;

  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

  for (int caseno = 1; caseno <= tests; caseno++) {
    int n;
    cin >> n;
    int m;
    cin >> m;

    pitem root = nullptr;
    for (int i = 0; i < n; i++) {
      i64 a, b;
      cin >> a >> b;
      pitem it = new item(make_pair(a, b), rng());
      insert(root, it);
    }

    cout << "Case #" << caseno << ": ";

    for (int i = 0; i < m; i++) {
      i64 s;
      cin >> s;

      pitem l = find_l(root, s);
      pitem r = find_r(root, s);
      // cerr << s << ":: ";
      // if (l)
      // cerr << l->key.first << "," << l->key.second << " (l) ";
      // if (r)
      // cerr << r->key.first << "," << r->key.second << " (r) ";
      // cerr << endl;

      if (l == r) {
        cout << s << " ";

        range key = l->key;
        erase(root, key);

        if (key.first <= s-1) {
          pitem it = new item(make_pair(key.first, s-1), rng());
          insert(root, it);
        }
        if (s+1 <= key.second) {
          pitem it = new item(make_pair(s+1, key.second), rng());
          insert(root, it);
        }
      } else {
        if (l && (!r || s - l->key.second <= r->key.first - s)) {
          cout << l->key.second << " ";

          range key = l->key;
          erase(root, key);
          key.second--;

          if (key.first <= key.second) {
            pitem it = new item(key, rng());
            insert(root, it);
          }
        } else {
          cout << r->key.first << " ";

          range key = r->key;
          erase(root, key);
          key.first++;

          if (key.first <= key.second) {
            pitem it = new item(key, rng());
            insert(root, it);
          }
        }
      }
    }
    
    cout << endl;
  }
  
  return 0;
}

