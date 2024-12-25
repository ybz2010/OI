#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll gcd(ll a, ll b)
{
    ll temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main()
{
    ll l, r, g, n, m, flag;
    int T;
    cin >> T;
    while (T--)
    {
        flag = 0;
        cin >> n >> m >> g;
        l = (n - 1) / g + 1;
        r = m / g;
        if ((l == r && l != 1) || l > r)
        {
            cout << -1 << " " << -1 << endl;
        }
        else if (l == r && l == 1)
        {
            cout << l * g << " " << r * g << endl;
        }
        else
        {
            for (ll i = r - l; flag == 0 && i >= 1; i--)
            {
                for (ll j = l; flag == 0 && j + i <= r; j++)
                {
                    if (gcd(i, j) == 1)
                    {
                        flag = 1;
                        cout << j * g << " " << (i + j) * g << endl;
                    }
                }
            }
        }
    }
}