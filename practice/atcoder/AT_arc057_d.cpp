#include<bits/extc++.h>
#define int long long
#define vector basic_string
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1005;
int n,m;
bool vis[maxn];
map<vector<int>,int>dp[maxn][maxn];
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = (ch == '-' ? -1 : 1); ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
int dfs(vector<int>v,int x,int y)
{
    if (y < 0)
        return 0;
    else if (x > m)
        return 1;
    else if(dp[x][y].count(v))
        return dp[x][y][v];
    else if (!vis[x])
        return dp[x][y][v] = y * dfs(v,x + 1,y - 1) % mod;
    int ret = 0,len = v.size();
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            vector<int>tmp;
            for (int k = 0; k < len; k++)
                if (k != i && k != j)
                    tmp.push_back(v[k]);
            tmp.push_back(v[i] + v[j]);
            sort(tmp.begin(),tmp.end());
            ret = (ret + v[i] * v[j] * dfs(tmp,x + 1,y + v[i] * v[j] - 1) % mod) % mod;
        }
    }
    return dp[x][y][v] = ret;
}
signed main()
{
    read(n);
    m = n * (n - 1) >> 1;
    int x;
    for (int i = 1; i < n; i++)
    {
        read(x);
        vis[x] = 1;
    }
    printf("%lld",dfs(vector<int>(n,1),1,0));
    return 0;
}