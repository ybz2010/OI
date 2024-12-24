#include<bits/extc++.h>
#define int long long
using namespace std;
int n,d;
void solve()
{
    cin >> n >> d;
    cout << "1 ";
    if (n >= 3 || d % 3 == 0)
        cout << "3 ";
    if (d == 5)
        cout << "5 ";
    if (n >= 3 || d == 7)
        cout << "7 ";
    if (n >= 6 || d == 9 || (n >= 3 && d % 3 == 0))
        cout << "9 ";
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