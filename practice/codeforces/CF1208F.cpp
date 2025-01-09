#include<bits/extc++.h>
#define int long long
#define pii pair<int,int>
#define mkp make_pair
#define U ((1 << 21) - 1)
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1 << 21 | 5;
int n;
int a[maxn];
pii sum[maxm];
pii operator+(pii x,pii y)
{
    pii ret;
    if (x.first > y.first)
    {
        ret.first = x.first;
        ret.second = max(x.second,y.first);
    }
    else
    {
        ret.first = y.first;
        ret.second = max(x.first,y.second);
    }
    return ret;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        if (sum[a[i]].first < i)
        {
            sum[a[i]].second = sum[a[i]].first;
            sum[a[i]].first = i;
        }
        else
            sum[a[i]].second = max(sum[a[i]].second,i);
    }
    for (int i = 0; i < 21; i++)
        for (int k = 0; k < (1 << 21); k++)
            if (!(k & (1 << i)))
                sum[k] = sum[k] + sum[k ^ (1 << i)];
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int s = U ^ a[i],tmp = 0;
        for (int j = 21; ~j; j--)
            if ((s & (1 << j)) && sum[tmp + (1 << j)].second > i)
                tmp += (1 << j);
        ans = max(ans,tmp + a[i]);
    }
    printf("%lld",ans);
    return 0;
}