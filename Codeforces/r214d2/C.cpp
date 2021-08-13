#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct abc{
    int t, a;
}c[110];
int dp[2][200000];
int main(){
    int n, k, i, w, r;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) scanf("%d", &c[i].a);
    for (i = 0; i < n; i++){
        scanf("%d", &c[i].t);
        c[i].t = k * c[i].t - c[i].a;
    }
    r = 0, w = 1;
    memset(dp[r], -1, sizeof(dp[r]));
    dp[r][100000] = 0;
    for (i = 0; i < n; i++){
        memset(dp[w], -1, sizeof(dp[w]));
        for (int j = 0; j < 200000; j++){
            if (dp[r][j] < 0) continue;
            dp[w][j] = max(dp[w][j], dp[r][j]);
            int jj = j + c[i].t;
            if (jj >= 0 && jj < 200000){
                dp[w][jj] = max(dp[w][jj], dp[r][j] + c[i].a);
            }
        }
        swap(w, r);
    }
    if (dp[r][100000] == 0) dp[r][100000] = -1;
    printf("%d\n", dp[r][100000]);
    return 0;
}
