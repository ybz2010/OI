#include <bits/stdc++.h>
#define inl inline
#define re register
typedef long double ld;
using namespace std;
const int maxn = 100005, inf = 1e9;
const double eps = 1e-14;
inl int Read()
{
    re int s = 0, f = 1;
    re char c;
    while (!isdigit(c = getchar()))
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        s = s * 10 + c - '0';
    return s * f;
}
int n, tot, head, tail, q[maxn], g[maxn];
ld dp[maxn];
inline ld x(int i){return (ld)1 / ld(n - i);}
inline ld y(int i){return (ld)dp[i] - (ld)i / ld(n - i);}
inline ld k(int i){return (ld)-i;}
inline ld slope(int i,int j){return (y(j) - y(i)) / (x(j) - x(i));}
inl bool check(double mid)
{
    head = tail = 1;
    for (re int i = 1; i <= n; ++i)
    {
        while (head < tail && slope(q[head],q[head + 1]) - k(i) > -eps)
            ++head;
        int j = q[head];
        dp[i] = dp[j] + ld(i - j) / ld(n - j) - mid; // 由于是求最大值，应减去额外贡献才能让分段越多代价越大
        g[i] = g[q[head]] + 1;
        while (head < tail && slope(q[tail - 1], q[tail]) <= slope(q[tail], i))
            --tail;
        q[++tail] = i;
    }
    return g[n] >= tot;
}
int main()
{
    n = Read();
    tot = Read();
    double l = 0.0, r = 1.0 * inf; // 因为 f 可取实数，所以二分的额外贡献也要取到实数
    while (r - l >= eps)
    {
        re double mid = (l + r) * 0.5;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    check(l);
    printf("%.9Lf\n", dp[n] + 1.0 * l * tot);
    return 0;
}