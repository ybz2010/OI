#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,lena,lenb,q;
int pos[maxn],toa[maxn],tob[maxn];
int disa[32][maxn][2],disb[32][maxn][2],dp[32][maxn][2];
struct city
{
    int h,id;
    int pre,nxt;
}a[maxn];
bool operator<(city x,city y){return x.h < y.h;}
void rm(int x)
{
    if (a[x].nxt)
        a[a[x].nxt].pre = a[x].pre;
    if (a[x].pre)
        a[a[x].pre].nxt = a[x].nxt;
}
int choose(int x,int y,int i)
{
    if (!x)
        return a[y].id;
    if (!y)
        return a[x].id;
    if (a[i].h - a[x].h > a[y].h - a[i].h)
        return a[y].id;
    else
        return a[x].id;
}
void calc(int st,int x)
{
    lena = lenb = 0;
    int now = 0;
    for (int i = 31; ~i; i--)
    {
        if (dp[i][st][now] && disa[i][st][now] + disb[i][st][now] <= x)
        {
            x -= disa[i][st][now] + disb[i][st][now];
            lena += disa[i][st][now];
            lenb += disb[i][st][now];
            if (i == 0)
                now = !now;
            st = dp[i][st][now];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].h;
        a[i].id = i;
    }
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[a[i].id] = i;
        a[i].pre = i - 1;
        a[i].nxt = i + 1;
    }
    a[1].pre = a[n].nxt = 0;
    for (int i = 1; i < n; i++)
    {
        int p = pos[i];
        int nxt = a[p].nxt,pre = a[p].pre;
        if (pre && (a[p].h - a[pre].h <= a[nxt].h - a[p].h || !nxt))
        {
            tob[i] = a[pre].id;
            toa[i] = choose(a[pre].pre,nxt,p);
        }
        else
        {
            tob[i] = a[nxt].id;
            toa[i] = choose(pre,a[nxt].nxt,p);
        }
        rm(p);
    }
    for (int i = 1; i <= n; i++)
    {
        if (toa[i])
        {
            dp[0][i][0] = toa[i];
            disa[0][i][0] = abs(a[pos[i]].h - a[pos[toa[i]]].h);
            disb[0][i][0] = 0;
        }
        if (tob[i])
        {
            dp[0][i][1] = tob[i];
            disb[0][i][1] = abs(a[pos[i]].h - a[pos[tob[i]]].h);
            disa[0][i][1] = 0;
        }
    }
    for (int i = 1; i < 32; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int now = 0; now < 2; now++)
            {
                int lst = now;
                if (i == 1)
                    lst = !lst;
                if (dp[i - 1][j][now])
                    dp[i][j][now] = dp[i - 1][dp[i - 1][j][now]][lst];
                if (dp[i][j][now])
                {
                    disa[i][j][now] = disa[i - 1][j][now] + disa[i - 1][dp[i - 1][j][now]][lst];
                    disb[i][j][now] = disb[i - 1][j][now] + disb[i - 1][dp[i - 1][j][now]][lst];
                }
            }
        }
    }
    int x,st,ans = 0;
    cin >> x;
    for (int i = 1; i <= n; i++)
    {
        static int ansa = 1,ansb = 0;
        calc(i,x);
        if (!lenb)
            lena = 1;
        if (lena * ansb < lenb * ansa || (lena * ansb == lenb * ansa && a[pos[i]].h > a[pos[ans]].h))
        {
            ansa = lena;
            ansb = lenb;
            ans = i;
        }
    }
    cout << ans << endl;
    cin >> q;
    while (q--)
    {
        cin >> st >> x;
        calc(st,x);
        cout << lena << " " << lenb << endl;
    }
    return 0;
}