#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,mid;
int a[maxn],b[maxn];
vector<int>v1,v2;
void calc2()
{
    for (int i = 1; i <= n; i++)
        if (a[i] > mid)
            v1.push_back(i);
    for (int i = 1; i <= n; i++)
        if (b[i] <= mid)
            v2.push_back(i);
    int ans = 0;
    for (int i = 0; i < (int)v1.size(); i++)
        ans += abs(v1[i] - v2[i]);
    cout << ans;
}
void calc1()
{
    for (int i = 1; i <= n; i++)
        if (a[i] >= mid)
            v1.push_back(i);
    for (int i = 1; i <= n; i++)
        if (b[i] <= mid)
            v2.push_back(i);
    int ans1 = 0;
    for (int i = 0; i < (int)v1.size(); i ++)
        ans1 += abs(v1[i] - v2[i]);
    v1.clear(),v2.clear();
    for (int i = 1; i <= n; i++)
        if (a[i] > mid)
            v1.push_back(i);
    for (int i = 1; i <= n; i++)
        if (b[i] < mid)
            v2.push_back(i);
    int ans2 = 0;
    for (int i = 0; i < (int)v1.size(); i ++)
        ans2 += abs(v1[i] - v2[i]);
    cout << min(ans1,ans2);

}
signed main()
{
    scanf("%lld",&n);
    mid = (n + 1) / 2;
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld",b + i);
    if (n & 1)
        calc1();
    else
        calc2();
    return 0;
}