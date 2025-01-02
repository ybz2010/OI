#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
class tri
{
    public:
    int x,y,r;
    tri(int x = 0,int y = 0,int r = 0):x(x),y(y),r(r){};
    int size(){return r * r;}
}a[15];
tri operator*(tri x,tri y)
{
    tri ret;
    ret.x = max(x.x,y.x);
    ret.y = max(x.y,y.y);
    ret.r = min(x.x + x.y + x.r,y.x + y.y + y.r) - ret.x - ret.y;
    return ret.r < 0 ? tri() : ret;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].r);
    int ans = 0;
    for (int k = 1; k < (1 << n); k++)
    {
        tri tmp = tri(0,0,inf);
        for (int i = 1; i <= n; i++)
        {
            if (k & (1 << (i - 1)))
                tmp = tmp * a[i];
        }
        int cnt = __builtin_popcount(k) - 1;
        int tans = tmp.size() << cnt;
        ans += (cnt & 1 ? -1 : 1) * tans;
    }
    printf("%.1lf",ans / 2.0);
    return 0;
}