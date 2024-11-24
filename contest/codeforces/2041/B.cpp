#include<bits/extc++.h>
#define int long long
using namespace std;
int w,b;
int idx;
void solve()
{
	scanf("%lld%lld",&w,&b);
	w += b;
	if (w > b)
		swap(w,b);
	idx = 1;
	printf("%.0lf\n",floor((sqrt(1 + 8 * b) - 1) / 2.0));
	return;
}
signed main()
{
	int t;
	scanf("%lld",&t);
	while (t--)
		solve();
	return 0;
}
