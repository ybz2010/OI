#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
bool check(int l,int r)
{
    gp_hash_table<int,int>apr;
    for (int i = l; i <= r; i++)
        apr[a[i]] ++;
    int len = (r - l + 1) >> 1;
    for (int i = l; i <= r; i++)
    {
        if (apr[a[i]] > len)
            return 1;
    }
    return 0;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (check(j,i))
                ans ++;
    cout << ans;
    return 0;
}