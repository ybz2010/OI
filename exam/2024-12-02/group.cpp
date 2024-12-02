#include<bits/extc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 1e9 + 7;
int n,k;
vector<ll>a;
void solve()
{
    scanf("%d%d",&n,&k);
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%lld",&a[i]);
    sort(a.begin(),a.end(),greater<int>());
    ll ans = 0;
    while (a.size() >= k)
    {
        int idx = 0;
        ll _min = inf;
        for (int i = 0; i < k; i++)
            _min = min(_min,a[i]);
        ans += _min;
        for (int i = 0; i < k; i++)
            a[i] -= _min;
	    for (int i = 0; i < a.size();)
	    {
	    	if (a[i] == 0)
	    		a.erase(a.begin() + i);
	    	else
	    		i ++;
	    }
        sort(a.begin(),a.end(),greater<int>());
        for (auto i : a)
            printf("%lld ",i);
        putchar('\n');
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}
/*
5
5 3
1 3 2 4 5
5 4
2 2 2 2 10000
5 5
2 3 4 5 6
5 1
2 3 4 5 6
5 2
3 3 4 4 10
*/