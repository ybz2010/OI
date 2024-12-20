#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn],ls[maxn],rs[maxn];
int st[maxn],top;
int rt,irt[maxn];
void dfs(int u)
{
    if (!u)
        return;
    cout << u << " ";
    dfs(ls[u]),dfs(rs[u]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        a[x] = i;
    }
    st[++top] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top && a[st[top]] > a[i])
            top --;
        if (!top)
            ls[i] = st[top + 1];
        else
        {
            ls[i] = rs[st[top]];
            rs[st[top]] = i;
        }
        st[++top] = i;
    }
    for (int i = 1; i <= n; i++)
        irt[ls[i]] = irt[rs[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!irt[i])
        {
            rt = i;
            break;
        }
    }
    dfs(rt);
    return 0;
}