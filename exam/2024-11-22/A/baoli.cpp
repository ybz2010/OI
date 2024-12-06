#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5005;
int n,k;
int a[maxn],b[maxn];
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n * k; i++)
        b[i] = a[(i - 1) % n + 1];
    n *= k;
    int ans = 0;
    vector<pair<int,int> >v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (b[j] > b[i])
                ans ++;
    cout << ans;
    return 0;
}