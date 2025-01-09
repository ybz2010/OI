#include<bits/extc++.h>
using namespace std;
int n,t;
double ans;
struct node
{
    int m,v;
    double val;
}a[105];
bool operator<(node x,node y){return x.val < y.val;}
signed main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].m >> a[i].v;
        a[i].val = 1.0 * a[i].v / a[i].m;
    }
    sort(a + 1,a + n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (t >= a[i].m)
        {
            ans += a[i].v;
            t -= a[i].m;
        }
        else
        {
            ans += t * a[i].val;
            break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}