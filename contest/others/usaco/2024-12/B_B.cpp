#include<bits/extc++.h>
using namespace std;
const int maxn = 1005;
int n,q;
int cnt1[maxn][maxn],cnt2[maxn][maxn],cnt3[maxn][maxn];
void solve()
{
    cin >> n >> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cnt1[i][j] = cnt2[i][j] = cnt3[i][j] = n;
    int x,y,z;
    while (q--)
    {
        cin >> x >> y >> z;
        cnt1[y][z] --;
        cnt2[x][z] --;
        cnt3[x][y] --;
        if (cnt1[y][z] == 0)
            cnt ++;
        if (cnt2[x][z] == 0)
            cnt ++;
        if (cnt3[x][y] == 0)
            cnt ++;
        cout << cnt << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}