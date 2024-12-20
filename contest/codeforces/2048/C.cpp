#include<bits/extc++.h>
using namespace std;
const int maxn = 5005;
int n,l,r;
char s[maxn];
bool a[maxn],_max[maxn],tmp[maxn];
void solve()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    l = 1,r = 1;
    for (int i = 1; i <= n; i++)
        a[i] = (s[i] == '1');
    for (int i = 1; i <= n; i++)    
    {
        memcpy(a,tmp,sizeof a);
        
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