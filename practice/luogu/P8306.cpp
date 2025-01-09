#include<bits/extc++.h>
using namespace std;
const int maxn = 3e6 + 5;
int n,q;
int tr[maxn][70],cnt[maxn],idx;
char s[maxn];
inline int toint(char x)
{
    if (x >= 'A' && x <= 'Z')
        return x - 'A' + 1;
    else if (x >= 'a' && x <= 'z')
        return x - 'a' + 26 + 1;
    else
        return x - '0' + 52 + 1;
}
inline void add(char str[])
{
    int pos = 0,len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int ch = toint(str[i]);
        if (!tr[pos][ch])
            tr[pos][ch] = ++idx;
        pos = tr[pos][ch];
        cnt[pos] ++;
    }
}
inline int find(char str[])
{
    int pos = 0,len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int ch = toint(str[i]);
        if (!tr[pos][ch])
            return 0;
        pos = tr[pos][ch];
    }
    return cnt[pos];
}
void solve()
{
    for (int i = 0; i <= idx; i++)
        for (int j = 1; j <= 65; j++)   
            tr[i][j] = 0;
    for (int i = 0; i <= idx; i++)
        cnt[i] = 0;
    idx = 0;
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s);
        add(s);
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%s",s);
        printf("%d\n",find(s));
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