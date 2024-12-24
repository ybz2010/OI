#include<bits/extc++.h>
#define ll long long
// #define test
using namespace std;
const int maxn = 1.5e5 + 5;
int n,q;
ll a[maxn],b[maxn];
ll pre[maxn],sum;
signed main()
{
    #ifdef test
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    cin >> q;
    sort(b + 1,b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum += b[i] * i;
        pre[i] = pre[i - 1] + b[i];
    }
    int x,y;
    while (q--)
    {
        cin >> x >> y;
        if (a[x] < y)
        {
            int l = lower_bound(b + 1,b + n + 1,a[x]) - b;
            int r = lower_bound(b + 1,b + n + 1,y) - b - 1;
            ll tmp = sum - l * a[x] + r * y;
            tmp -= pre[r] - pre[l];
            cout << tmp << endl;
        }
        else if (a[x] > y)
        {
            int l = lower_bound(b + 1,b + n + 1,y) - b;
            int r = lower_bound(b + 1,b + n + 1,a[x]) - b;
            ll tmp = sum - r * a[x] + l * y;
            tmp += pre[r - 1] - pre[l - 1];
            cout << tmp << endl;
        }
        else
            cout << sum << endl;
    }
    #ifdef test
    fclose(stdout);
    cout << clock();
    #endif
    return 0;
}