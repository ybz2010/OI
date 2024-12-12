#include<bits/extc++.h>
using namespace std;
int n,q;
int a[200005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> q;
    while (q--)
    {
        int op,p,x;
        cin >> op;
        if (op == 1)
        {
            cin >> p >> x;
            a[p] = x;
        }
        else
        {
            cin >> x;
            for (int i = 1; i <= n; i++)
                a[i] = max(a[i],x);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}