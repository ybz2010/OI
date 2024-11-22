#include<bits/extc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
const int maxn = 100000 + 5;
const double st = 1e10,ed = 1e-3,d = 0.98;
random_device seed;
mt19937 rnd(seed() * 0x387C6720 % 0x6C65EB9B1413185D);
int n,e,t;
int ans = inf;
int x[maxn],a[maxn << 1],dis[maxn << 1];
int cost()
{
    int ret = 0;
    bool apr[maxn << 1] = {1,1};
    memset(dis,0,sizeof dis);
    for (int i = 2; i <= (n << 1 | 1); i++)
    {
        if (a[i] <= n)
        {
            if (apr[a[i] + n])
                return inf;
            dis[a[i]] = dis[a[i - 1]] + abs(x[a[i]] - x[a[i - 1]]);
            apr[a[i]] = 1;
        }
        if (n + 1 <= a[i])
        {
            if (!apr[a[i] - n])
                return inf;
            dis[a[i]] = max(dis[a[i - 1]] + abs(x[a[i]] - x[a[i - 1]]),dis[a[i] - n] + t);
            apr[a[i]] = 1;
        }
    }
    return dis[n << 1 | 1];
}
void sa()
{
    double t = st;
    while (t > ed)
    {
        if (clock() > 900)
        {
            cout << ans;
            exit(0);
        }
        int pos = rnd() % ((n << 1) - 1) + 1;
        swap(a[pos],a[pos + 1]);
        int tmp = cost() + x[a[1]];
        if (tmp < ans)
            ans = tmp;
        else if (tmp == inf || exp(tmp) > rnd())
            swap(a[pos],a[pos + 1]);
        t *= d;
    }
}
signed main()
{
    scanf("%lld%lld%lld",&n,&e,&t);
    for (int i = 1; i <= n; i++)
        scanf("%lld",x + i);
    for (int i = 1; i <= (n << 1); i++)
    {
        a[i] = i;// i表示第一次访问，i + n表示第二次访问。
        if (i > n)
            x[i] = x[i - n];
    }
    a[n << 1 | 1] = (n << 1 | 1);
    x[n << 1 | 1] = e;
    while (1)
        sa();
    return 0;
}