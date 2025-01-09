#include<bits/extc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int maxn = 1005;
int n,m;
char s[maxn][maxn];
int toint(char ch)
{
    switch (ch)
    {
    case 'n':
        return 1;
    case 'a':
        return 2;
    case 'r':
        return 3;
    case 'e':
        return 4;
    case 'k':
        return 5;
    default:
        return 114514;
    }
}
void next(int &x)
{
    if (x == 5)
        x = 1;
    else
        x ++;
}
void solve()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%s",s[i] + 1);
    vector<int>dp(6,-inf),tmp;
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp = dp;
        for (int j = 1; j <= 5; j++)
        {
            if (dp[j] == -inf)
                continue;
            int score = 0,nxt = j;
            for (int k = 1; k <= m; k ++)
            {
                int x = toint(s[i][k]);
                if (x == 114514)
                    continue;
                if (nxt == x)
                {
                    next(nxt);
                    score ++;
                }
                else
                    score --;
            }
            tmp[nxt] = max(tmp[nxt],dp[j] + score);
        }
        dp = tmp;
    }
    int ans = 0;
    for (int i = 1; i <= 5; i++)
        ans = max(ans,dp[i] - (i - 1 << 1));
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}