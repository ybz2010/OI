#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2.5e4 + 5;
int n,t;
pair<int,int>a[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1,a + n + 1);
    int i = 0,st = 1,cnt = 0;
    while (i <= n)
    {
        int r = 0;
        while (i <= n && a[i].first <= st)
        {
            r = max(r,a[i].second);
            i ++;
        }
        if (r < st)
            break;
        cnt ++;
        if (r >= t)
        {
            cout << cnt;
            return 0;
        }
        st = r + 1;
    }
    cout << "-1";
    return 0;
}