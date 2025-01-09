#include <bits/extc++.h>
#define int long long
#define inf 1e18 + 1919810
using namespace std;
const int maxn = 2e7 + 10;
int q, x, y, cnt = 1;
int ls[maxn], rs[maxn], val[maxn];
int w(int y, int x)
{
    if (x == 0 && y == 0)
        return 1;
    int p = max(abs(x), abs(y)), res = (2 * p - 1) * (2 * p - 1);
    if (x == p && y != -p)
        return res + p + y;
    if (y == p)
        return res + 3 * p - x;
    if (x == -p)
        return res + 5 * p - y;
    return res + 7 * p + x;
}
int que(int rt, int l, int r, int x)
{
    val[rt]--;
    if (l == r)
        return x;
    int mid = (l + r) >> 1;
    if (!ls[rt])
        ls[rt] = ++cnt, val[ls[rt]] = mid - l + 1;
    if (!rs[rt])
        rs[rt] = ++cnt, val[rs[rt]] = r - mid;
    if (val[ls[rt]] >= x)
        return que(ls[rt], l, mid, x);
    else
        return mid - l + 1 + que(rs[rt], mid + 1, r, x - val[ls[rt]]);
}
signed main()
{
    scanf("%lld", &q);
    val[1] = inf;
    while (q--)
    {
        scanf("%lld%lld", &x, &y);
        int num = w(x, y);
        printf("%lld\n", que(1, 1, inf, num));
    }
    return 0;
}