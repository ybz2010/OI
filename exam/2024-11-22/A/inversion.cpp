#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5005;
int n,k;
int a[maxn],cntl[maxn],cnt[maxn];
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] > a[i])
                cntl[i] ++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[j] > a[i])
                cnt[i] ++;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += k * cntl[i] + (k * (k - 1) >> 1) * cnt[i]; 
    printf("%lld",ans);
    return 0;
}