#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll const maxq = 5e5 + 10;
ll t,n;
void mian() {
    scanf("%lld",&n);
    vector<ll>a(n + 5,0);
    vector<ll>sum(n + 5,0);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld",&a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    ll len = (n >> 1) + 1;
    ll max1 = sum[n],max2 = 0;
    for (ll i = 1; i + len - 1 <= n; i++) {
        ll j = (i + len - 1);
        ll tmp = sum[i - 1] + sum[n] - sum[j];
        if (tmp > max2)
            max2 = tmp,max1 = sum[n] - tmp;
    }
    printf("%lld %lld\n",max1,max2);
}
signed main() {
    scanf("%lld",&t);
    while (t--)
        mian();
    return 0;
}