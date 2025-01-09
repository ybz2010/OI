#include<bits/extc++.h>
using namespace std;
int n,k;
int a[55];
void solve()
{
    scanf("%d%d",&n,&k);
    memset(a,0,sizeof a);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    sort(a + 1,a + n + 1,greater<int>());
    int sum = 0,i;
    for (i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum > k)
            break;
    }
    sum -= a[i];
    printf("%d\n",k - sum);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}