#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long ll;
using namespace std;
ll const maxn = 5e5 + 5;
struct edge {
    ll v,w;
    edge *nxt;
}*head[maxn];
ll n,m,a[maxn],dis[maxn];
ll u[maxn],v[maxn],w[maxn];
void adde(ll u,ll v,ll w) {
    auto tmp = new edge;
    tmp->v = v;
    tmp->w = w;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void spfa(ll st) {
    memset(dis,~0x3f,sizeof dis);
    bool vis[maxn] = {};
    queue<ll> q;
    dis[st] = 0;
    vis[st] = 1;
    q.push(st);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto i = head[u]; i; i = i->nxt) {
            ll v = i->v,w = i->w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v])
                    vis[v] = 1,q.push(v);
            }
        }
    }
}
void solve() {
    scanf("%lld%lld",&n,&m);
    for (ll i = 1; i <= n; i++)
        scanf("%lld",a + i);
    memset(head,0,sizeof head);
    sort(a + 1,a + n + 1);
    for (ll i = 1; i <= m; i++) {
        scanf("%lld%lld%lld",u + i,v + i,w + i);
        u[i] = lower_bound(a + 1,a + n + 1,u[i]) - a - 1;
        v[i] = upper_bound(a + 1,a + n + 1,v[i]) - a - 1;
        adde(u[i],v[i],w[i]);
    }
    for (ll i = 0; i < n; i++) {
        adde(i,i + 1,0);
        adde(i + 1,i,-1);
    }
    spfa(0);
    printf("%lld\n",n - dis[n]);
}
signed main() {
    ll t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}