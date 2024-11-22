#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
int n;
char str[maxn][5];
bool fl;
int vi[maxn * 10];
int tr[maxn * 10][15],id = 1;
int toint(char ch){return ch - '0';}
void insert(char s[])
{
    int p = 1,len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        int ch = toint(s[i]);
        if (!tr[p][ch])
            tr[p][ch] = ++id;
        p = tr[p][ch];
        vi[p] ++;
    }
    if (vi[p] != 1)
    {
        cout << "YES\n";
        fl = 1;
    }
}
void solve()
{
    memset(tr,0,sizeof tr);
    memset(vi,0,sizeof vi);
    fl = 0;
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%s",str[i]);
    for (int i = 1; i <= n; i++)
    {
        insert(str[i]);
        if (fl)
            return;
    }
    cout << "NO\n";
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}