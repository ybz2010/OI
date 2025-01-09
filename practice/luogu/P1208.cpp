#include<bits/extc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n,m;
struct node{int p,a;}a[maxn];
bool operator<(node x,node y){return x.p < y.p;}
signed main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].p >> a[i].a;
    sort(a + 1,a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (m < a[i].a)
        {
            ans += m * a[i].p;
            break;
        }
        m -= a[i].a;
        ans += a[i].a * a[i].p;
    }
    cout << ans;
    return 0;
}