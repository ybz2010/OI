#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    int cnt = 1,pos = 1;
    while (pos < n)
    {
        cnt ++;
        pos = pos + 1 << 1;
    }
    printf("%d\n",cnt);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}