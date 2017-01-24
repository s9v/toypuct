#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int p, x, y;
    scanf("%d %d %d", &p, &x, &y);
    x -= 50; y -= 50;
    if (x == 0 && y == 0) {
      puts(p == 0 ? "white" : "black");
      continue;
    }
    if (x * x + y * y > 50 * 50) {
      puts("white");
      continue;
    }
    double angle = atan2(x, y);
    if (angle < 0) {
      angle += 2 * pi;
    }
    puts(angle <= 2 * pi * 0.01 * p ? "black" : "white");
    printf("angle = %lf\n\n", angle);
  }
  return 0;
}
