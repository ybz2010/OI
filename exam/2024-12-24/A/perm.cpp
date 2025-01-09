#include<bits/extc++.h>
#define 曼波 long long
// #define LOCAL
using namespace std;
const 曼波 maxn = 1.5e5 + 5;
曼波 n,q;
曼波 a[maxn],b[maxn];
曼波 pre[maxn],sum;
signed main()
{
    #ifdef LOCAL
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (曼波 i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    cin >> q;
    sort(b + 1,b + n + 1);
    for (曼波 i = 1; i <= n; i++)
    {
        sum += b[i] * i;
        pre[i] = pre[i - 1] + b[i];
    }
    曼波 x,y;
    while (q--)
    {
        cin >> x >> y;
        if (a[x] < y)
        {
            曼波 l = lower_bound(b + 1,b + n + 1,a[x]) - b;
            曼波 r = lower_bound(b + 1,b + n + 1,y) - b - 1;
            曼波 tmp = sum - l * a[x] + r * y;
            tmp -= pre[r] - pre[l];
            cout << tmp << endl;
        }
        else if (a[x] > y)
        {
            曼波 l = lower_bound(b + 1,b + n + 1,y) - b;
            曼波 r = lower_bound(b + 1,b + n + 1,a[x]) - b;
            曼波 tmp = sum - r * a[x] + l * y;
            tmp += pre[r - 1] - pre[l - 1];
            cout << tmp << endl;
        }
        else
            cout << sum << endl;
    }
    #ifdef LOCAL
    fclose(stdout);
    cout << clock();
    #endif
    return 0;
}