#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn];
int f[maxn];
signed main()
{
    freopen("different.in","r",stdin);
    freopen("different.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        char s[20];
        scanf("%s",s);
        for (int j = 0; j < m; j++)
            a[i] |= (s[j] == 'G') << j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp = a[i] ^ a[j];
            f[i] = max(f[i],(int)__popcount(tmp));
        }
        printf("%lld\n",f[i]);
    }
    return 0;
}
//孩子已经饿了四个小时了