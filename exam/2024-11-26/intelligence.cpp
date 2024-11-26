#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,k;
int a[maxn];
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int ans = 0;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        int sum = 0,gcd = 0;
        for (int j = i; j <= n; j++)
        {
            sum += a[j];
            gcd = __gcd(gcd,a[j]);
            if (j - i + 1 >= k)
                ans = max(ans,sum * gcd);
        }
    }
    cout << ans;
    return 0;
}