#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1 << 18 | 5;
int n;
struct Nahida
{
    int a,b;
    Nahida():a(0),b(0){};
    friend Nahida operator+(const Nahida &x,const Nahida &y)
    {
        Nahida ret;
        if (x.a > y.a)
        {
            ret.a = x.a;
            ret.b = max(x.b,y.a);
        }
        else
        {
            ret.a = y.a;
            ret.b = max(x.a,y.b);
        }
        return ret;
    }
}a[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 0; i < (1 << n); i++)
    {
        scanf("%lld",&a[i].a);
        a[i].b = -inf;
    }
    for (int i = 0; i < n; i++)
        for (int k = 0; k < (1 << n); k++)
            if (k & (1 << i))
                a[k] = a[k] + a[k ^ (1 << i)];
    int ans = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        ans = max(ans,a[i].a + a[i].b);
        printf("%lld\n",ans);
    }
    return 0;
}