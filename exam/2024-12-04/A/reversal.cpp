#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
int a[100010];
char s[100010],tmp[100010];
void calc()
{
    for (int i = 1; i <= n; i++)
        tmp[i] = s[i];
    for (int i = 1; i <= n; i += 2)
    {
        for (int j = a[i]; j <= a[i + 1]; j++)
        {
            if (tmp[j] == 'W')
                tmp[j] = 'B';
            else
                tmp[j] = 'W';
        }
    }
}
bool check()
{
    for (int i = 1; i <= n; i++)
        if (tmp[i] == 'B')
            return 0;
    return 1;
}
void solve()
{
    memset(s,0,sizeof s);
    scanf("%lld",&n);
    n <<= 1;
    scanf("%s",s + 1);
    for (int i = 1; i <= n; i ++)
        a[i] = i;
    int cnt = 0;
    do
    {
        bool fl = 0;
        for (int i = 1; i <= n; i += 2)
            if (a[i] > a[i + 1])
            {
                fl = 1;
                break;
            }
        if (fl)
            continue;
        calc();
        cnt += check();
    }while (next_permutation(a + 1,a + n + 1));
    printf("%lld\n",cnt);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}