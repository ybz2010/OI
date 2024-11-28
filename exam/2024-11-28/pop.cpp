#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n;
int a[maxn],b[maxn];
bool check(int x,int y,int op)
{
    if (x > op)
        return y < n - op;
    else
        return y > n - op;
}
int calc(int x)
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!check(a[i],b[i],x))
        {
            cout << 1;
            int j = i;
            while (!check(a[j],b[j],x))
            {
                cout << 2;
                swap(a[j],a[j + 1]);
                j++,ret ++;
            }
        }
    }
    return ret;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld",b + i);
    if (n & 1)
        cout << min(calc((n - 1) >> 1),calc((n + 1) >> 1));
    else
        cout << calc(n << 1);
    return 0;
}