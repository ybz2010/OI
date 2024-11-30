#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
char s[2][maxn],t[2][maxn];
int l[2][maxn],r[2][maxn],bel[2][maxn],sc[2];
int cnt0[2][maxn],cnt1[2][maxn];
void pre(int x)
{
    memset(bel,0,sizeof bel);
    memset(sc,0,sizeof sc);
    memset(cnt0,0,sizeof cnt0);
    memset(cnt1,0,sizeof cnt1);
    int i = 1;
    while (i <= n)
    {
        if (t[x][i] == '1')
        {
            sc[x] ++;
            l[x][sc[x]] = i;
            while (i <= n && t[x][i] == '1')
            {
                bel[x][i] = sc[x];
                i ++;
            }
            r[x][sc[x]] = i - 1;
        }
        else
            while (i <= n && t[x][i] == '0')
                i ++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[x][i] == '0')
            cnt0[x][bel[x][i]] ++;
        else
            cnt1[x][bel[x][i]] ++;
    }
}
signed main()
{
    // freopen("edit.in","r",stdin);
    // freopen("edit.out","w",stdout);
    scanf("%d",&n);
    scanf("%s%s%s%s",s[0] + 1,s[1] + 1,t[0] + 1,t[1] + 1);
    pre(0),pre(1);
    int ans = 0,i = 1;
    while (i <= n)
    {
        while (i <= n && t[0][i] == '0')
        {
            if (t[1][i] == '1')
            {
                if (s[0][i] == '0' && cnt0[1][bel[1][i]])
                {
                    ans ++;
                    cnt0[1][bel[1][i]] --;
                }
                if (s[0][i] == '1' && cnt1[1][bel[1][i]])
                {
                    ans ++;
                    cnt1[1][bel[1][i]] --;
                }
            }
            else
                ans += (s[0][i] == s[1][i]);
            i ++;
        }
        while (i <= n && t[0][i] == '1')
        {
            int id = bel[0][i],j = l[0][bel[0][i]];
            while (j <= r[0][bel[0][i]])
            {
                while (j <= r[0][bel[0][i]] && t[1][j] == '0')
                {
                    if (s[1][j] == '0' && cnt0[0][bel[0][j]])
                    {
                        ans ++;
                        cnt0[0][bel[0][j]] --;
                    }
                    if (s[1][j] == '1' && cnt1[0][bel[0][j]])
                    {
                        ans ++;
                        cnt1[0][bel[0][j]] --;
                    }
                    j ++;
                }
                while (j <= r[0][bel[0][i]] && t[1][j] == '1')
                {
                    int id1 = bel[0][i],id2 = bel[1][j];
                    int L = max(l[0][id1],l[1][id2]);
                    int R = min(r[0][id1],r[1][id2]);
                    int len = R - L + 1;
                    int tmp = 
                }
            }
        }
    }
    return 0;
}