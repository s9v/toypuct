#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, l, r, x[20], y[20], uses[1 << 20] = {};
double mem[1 << 20] = {}, a[20];

double bs(double f, int i)
{
    double t, x2, y2, alf = M_PI - a[i];
    x2 = (x[i] - f) * cos(alf) + y[i] * sin(alf);
    y2 = -(x[i] - f) * sin(alf) + y[i] * cos(alf);
    if(y2 >= 0.0)
        return r;
    return min(-x2 * y[i] / y2 + x[i], 1.0 * r);
    //printf("%0.4lf %d\n", f, i);
    /*double ta = f, tb = r, m;
    return f;
    for(int j = 0; j < 50 && tb - ta > 1e-9; ++j)
    {
        m = 0.5 * (ta + tb);
        double ca = ((f - x[i]) * (m - x[i]) + y[i] * y[i]) / sqrt((f - x[i]) * (f - x[i]) + y[i] * y[i]) / sqrt((m - x[i]) * (m - x[i]) + y[i] * y[i]);
        if(acos(ca) > a[i])
            tb = m;
        else
            ta = m;
    }
    return 0.5 * (ta + tb);*/
}

double calc(int mask)
{
    if(mem[mask] < 0)
        for(int i = 0; i < n; ++i)
            if((1 << i) & mask)
                mem[mask] = max(mem[mask], bs(calc(mask - (1 << i)), i));
    return mem[mask];
}

int main()
{
    scanf("%d%d%d", &n, &l, &r);
    r -= l;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d%lf", x + i, y + i, a + i);
        x[i] -= l;
        a[i] *= M_PI / 180;
    }
    for(int i = 1; i < (1 << n); ++i)
        mem[i] = -1e9;
    printf("%0.9lf\n", calc((1 << n) - 1));
    return 0;
}
