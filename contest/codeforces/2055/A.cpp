#include<bits/extc++.h>
using namespace std;
int n,a,b;
void solve()
{
    scanf("%d%d%d",&n,&a,&b);
    if ((a + b) & 1)
        puts("NO");
    else
        puts("YES");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}