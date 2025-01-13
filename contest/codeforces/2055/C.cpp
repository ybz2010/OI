#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f;
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1005;
int n,m,sum,len;
char s[maxn << 1];
int a[maxn][maxn],sum1[maxn],sum2[maxn];
void solve()
{
    scanf("%lld%lld%s",&n,&m,s + 1);
    len = strlen(s + 1);
    fill(sum1 + 1,sum1 + m + 1,0);
    fill(sum2 + 1,sum2 + n + 1,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld",&a[i][j]);
            sum1[i] += a[i][j];
            sum2[j] += a[i][j];
        }
    }
    set<int>st1[maxn],st2[maxn];
    st1[1].insert(1),st2[1].insert(1);
    for (int i = 1,x = 1,y = 1; i <= len; i++)
    {
        if (s[i] == 'D')
            x++;
        else
            y++;
        st1[x].insert(y);
        st2[y].insert(x);
    }
    queue<pii>q;
    for (int i = 1; i <= n; i++)
        if (st1[i].size() == 1)
            q.push({i,0});
    for (int j = 1; j <= m; j++)
        if (st2[j].size() == 1)
            q.push({0,j});
    while (!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        if (!x)
        {
            if (st2[y].empty())
                continue;
            x = *st2[y].begin();
            a[x][y] = -sum2[y];
            sum1[x] += a[x][y];
            sum2[y] += a[x][y];
            st1[x].erase(y);
            st2[y].erase(x);
            if (st1[x].size() == 1)
                q.push({x,0});
            if (st2[y].size() == 1)
                q.push({0,y});
        }
        else
        {
            if (st1[x].empty())
                continue;
            y = *st1[x].begin();
            a[x][y] = -sum1[x];
            sum1[x] += a[x][y];
            sum2[y] += a[x][y];
            st1[x].erase(y);
            st2[y].erase(x);
            if (st1[x].size() == 1)
                q.push({x,0});
            if (st2[y].size() == 1)
                q.push({0,y});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%lld ",a[i][j]);
        putchar('\n');
    }
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}