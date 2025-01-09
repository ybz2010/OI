#include<bits/extc++.h>
#define int long long
using namespace std;
int L,R,g;
int l,r;
void solve()
{
    cin >> L >> R >> g;
    l = ceil(1.0 * L / g);
    r = floor(1.0 * R / g);
    if (l > r || (l == r && l != 1))
        cout << "-1 -1";
    else if (l == 1 && r == 1)
        cout << l * g << " " << r * g;
    else
    {
        bool fl = 1;
        for (int i = r - l; fl && i; i--)
        {
            for (int j = l; fl && j + i <= r; j++)
            {
                if (__gcd(i,j) == 1)
                {
                    cout << j * g << " " << (j + i) * g;
                    fl = 0;
                }
            }
        }
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}