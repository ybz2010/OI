#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
int n;
int l[maxn],r[maxn];
int a[maxn],st[maxn],top;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    st[++top] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top && a[st[top]] > a[i])
            top --;
        if (!top)
            l[i] = st[top + 1];
        else
        {
            l[i] = r[st[top]];
            r[st[top]] = i;
        }
        st[++top] = i;
    }
    int ans1 = 0,ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        ans1 ^= i * (l[i] + 1);
        ans2 ^= i * (r[i] + 1);
    }
    cout << ans1 << " " << ans2;
    return 0;
}