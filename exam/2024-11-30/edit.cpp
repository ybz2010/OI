#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,sc;
char s[2][maxn],t[2][maxn];
int cnt0[2][maxn],cnt1[2][maxn];
void solve()
{
    scanf("%d",&n);
    scanf("%s%s%s%s",s[0] + 1,s[1] + 1,t[0] + 1,t[1] + 1);
    bool apr0 = 0,apr1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[0][i] == '0')
            apr0 = 1;
        if (s[0][i] == '1')
            apr1 = 1;
        if (apr0 && apr1)
            break;
    }
    if ((!apr0) || (!apr1))
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += (s[0][i] == s[1][i]);
        printf("%d\n",ans);
    }
    else if (strcmp(t[0] + 1,t[1] + 1) == 0)
    {
        int i = 1,ans = 0;
        while (i <= n)
        {
            while (t[0][i] == '0')
            {
                ans += (s[0][i] == s[1][i]);
                i ++;
            }
            sc ++;
            while (t[0][i] == '1')
            {
                if (s[0][i] == '0')
                    cnt0[0][sc] ++;
                if (s[0][i] == '1')
                    cnt1[0][sc] ++;
                if (s[1][i] == '0')
                    cnt0[1][sc] ++;
                if (s[1][i] == '1')
                    cnt1[1][sc] ++;
                i ++;
            }
        }
        for (int i = 1; i <= sc; i++)
            ans += min(cnt0[0][i],cnt0[1][i]) + min(cnt1[0][i],cnt1[1][i]);
        printf("%d\n",ans);
    }
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}