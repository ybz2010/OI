#include<bits/extc++.h>
#define ll long long
#define mod 998244353
using namespace std;
const int maxn = 2e6 + 5;
int randseed,n,m,q;
int stu[maxn],idx,fw[maxn];
int ex[maxn],ey[maxn],eu[maxn],ev[maxn];
int x[maxn],y[maxn],t[maxn],u[maxn],v[maxn],id[maxn];
struct edge{
	int t,u,v,id,idx;
	bool operator<(edge x){return t < x.t;}
}a[maxn];
unsigned int rnd()
{
	unsigned int r;
	r = randseed = randseed * 1103515245 + 12345;
	return (r << 16) | ((r >> 16) & 0xFFFF);
}
void init()
{
	cin>>n>>m>>q>>randseed;
	for (int i=1;i<=m;i++) {x[i]=rnd()%n+1; y[i]=rnd()%n+1;}
	for (int i=1;i<=q;i++) {a[i].t=rnd()%m+1; a[i].u=rnd()%n+1; a[i].v=rnd()%n+1;a[i].id=rnd()%n+1;a[i].idx = i;}
}
signed main()
{
	init();
	for (int i = 1; i <= n; i++)
		stu[i] = i;
	idx = 1;
	sort(a + 1,a + q + 1);
	for (int i = 1; i <= m; i++)
	{
		ex[i] = stu[x[i]];
		ey[i] = stu[y[i]];
		swap(stu[x[i]],stu[y[i]]);
		while (idx <= q && a[idx].t == i)
		{
			a[idx].u = stu[a[idx].u];
			a[idx].v = stu[a[idx].v];
			idx ++;
		}
	}
	for (int i = 1; i <= n; i++)
		fw[stu[i]] = i;
	ll ans = 0;
	for (int i = 1; i <= q; i++)
	{
		if (ex[a[i].t] == a[i].id)
			a[i].id = ey[a[i].t];
		else if (ey[a[i].t] == a[i].id)
			a[i].id = ex[a[i].t];
		if (a[i].v == a[i].id)
			a[i].id = a[i].u;
		else if (a[i].u == a[i].id)
			a[i].id = a[i].v;
		ans = (ans + (ll)a[i].idx * fw[a[i].id] % mod) % mod;
	}
	cout << ans;
	return 0;
}
