#include<bits/extc++.h>
#define eps 1e-8
using namespace std;
int n,m;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp = floor(sqrt(1.0 * i * j));
            if (abs(tmp * tmp - i * j) < eps)
                cnt ++;
        }
    }
    cout << cnt;
    return 0;
}