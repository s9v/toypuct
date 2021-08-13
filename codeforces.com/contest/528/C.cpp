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

struct Treap {
  pitem root;

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
}

int main() {
  std::ios_base::sync_with_stdio(false);

  
  return 0;
}

