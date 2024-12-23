#include<bits/extc++.h>
using namespace std;
int n,m;
signed main()
{
    cin >> n >> m;
    int cnt = 1,sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        if (sum > m)
        {
            cnt ++;
            sum = x;
        }
    }
    cout << cnt;
    return 0;
}