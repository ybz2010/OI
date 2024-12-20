#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    puts(n % 33 == 0 ? "YES" : "NO");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}