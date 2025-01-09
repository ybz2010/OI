#include<bits/extc++.h>
using namespace std;
int n,k;
void solve()
{
    scanf("%d%d",&n,&k);
    vector<int>a(n + 5,0);
    int x = 1;
    for (int i = k; i <= n; i += k)
        a[i] = x++;
    for (int i = 1; i <= n; i++)
        if (!a[i])
            a[i] = x++;
    for (int i = 1; i <= n; i++)
        printf("%d ",a[i]);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}