#include<bits/extc++.h>
#define int unsigned long long
using namespace std;
int n,m,k;
struct mat
{
    int a[125][125];
    mat(){memset(a,0,sizeof a);};
    void base()
    {
        memset(a,0,sizeof a);
        for (int i = 0; i <= 120; i++)
            a[i][i] = 1;
    }
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i <= n * 3; i++)
            for (int j = 0; j <= n * 3; j++)
                for (int k = 0; k <= n * 3; k++)
                    ret[i][j] += x[i][k] * y[k][j];
        return ret;
    }
}base[64];
int toint(int x,int y){return x + (y - 1) * n;}
bool check(mat x)
{
    int sum(0);
    for (int i = 1; i <= n; i++)
    {
        sum += x[i][0] - 1;
        if (sum >= k)
            return 1;
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    base[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        base[0][i][0] = base[0][i][i + n] = base[0][i + n][i + 2 * n] = 1;
    for (int i = 1,u,v,w; i <= m; i++)
    {
        cin >> u >> v >> w;
        base[0][toint(u,w)][v]++;
    }
    signed i;
    for (i = 1; ; i++)
    {
        if (i >= 64)
        {
            cout << "-1";
            return 0;
        }
        base[i] = base[i - 1] * base[i - 1];
        if (check(base[i]))
            break;
    }
    i--;
    int ans = 0;
    mat now,tmp;
    now.base();
    for (; i >= 0; i--)
    {
        tmp = now * base[i];
        if (!check(tmp))
        {
            now = tmp;
            ans += (1ll << i);
        }
    }
    cout << ans;
    return 0;
}