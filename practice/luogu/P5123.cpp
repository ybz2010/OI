#include<bits/extc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int n;
int a[maxn][7];
map<int,bitset<maxn> >mp;
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d",a[i] + j);
            mp[a[i][j]][i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bitset<maxn>tmp;
        for (int j = 1; j <= 5; j++)
            tmp |= mp[a[i][j]];
        ans += (n - tmp.count());
    }
    printf("%d",ans >> 1);
    return 0;
}