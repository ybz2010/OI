#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
int n,k;
int in[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int a,b;
        cin >> a >> b;
        in[b] ++;
        in[a] ++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += n - in[i] - 1;
    cout << (ans >> 1);
    return 0;
}