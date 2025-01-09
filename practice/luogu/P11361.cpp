#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
char s1[maxn],s2[maxn];
char t1[maxn],t2[maxn];
int bel1[maxn],bel2[maxn],sc;
int cnt1[maxn][2],cnt2[maxn][2];
void init()
{
    memset(s1,0,sizeof s1);
    memset(s2,0,sizeof s2);
    memset(t1,0,sizeof t1);
    memset(t2,0,sizeof t2);
    memset(bel1,0,sizeof bel1);
    memset(bel2,0,sizeof bel2);
    memset(cnt1,0,sizeof cnt1);
    memset(cnt2,0,sizeof cnt2);
}
void solve()
{
    init();
    scanf("%d",&n);
    scanf("%s%s",s1 + 1,s2 + 1);
    scanf("%s%s",t1 + 1,t2 + 1);
    sc = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (t1[i] != t1[i - 1])
            bel1[i] = ++sc;
        else
            bel1[i] = bel1[i - 1];
        cnt1[bel1[i]][s1[i] == '1'] ++;
    }
    sc = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (t2[i] != t2[i - 1])
            bel2[i] = ++sc;
        else
            bel2[i] = bel2[i - 1];
        cnt2[bel2[i]][s2[i] == '1'] ++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (t1[i] == '0' && t2[i] == '0')
        {
            if (s1[i] == s2[i])
                ans++;
            continue;
        }
        else if (t1[i] == '0')
        {
            if (cnt2[bel2[i]][s1[i] == '1'])
            {
                cnt2[bel2[i]][s1[i] == '1'] --;
                ans ++;
            }
        }
        else if (t2[i] == '0')
        {
            if (cnt1[bel1[i]][s2[i] == '1'])
            {
                cnt1[bel1[i]][s2[i] == '1'] --;
                ans ++;
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        if (t1[i] == '1' && t2[i] == '1')
        {
            if (cnt1[bel1[i]][0] && cnt2[bel2[i]][0])
            {
                cnt1[bel1[i]][0] --;
                cnt2[bel2[i]][0] --;
                ans ++;
            }
            else if (cnt1[bel1[i]][1] && cnt2[bel2[i]][1])
            {
                cnt1[bel1[i]][1] --;
                cnt2[bel2[i]][1] --;
                ans ++;
            }
        }
    }
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
// 纯tm大模拟加贪心呗