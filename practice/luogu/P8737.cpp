#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 3005;
const int mod = 1e9 + 7;
int n,m,w;
int fac[maxn],inv[maxn];
int f[maxn][maxn];
bool ipr[maxn];
vector<int>pr;
struct node
{
    int x,y,z;
}st,en,p1,p2;
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
void init()
{
    for (int i = 2; i <= 3000; i++)
    {
        if (!ipr[i])
            pr.push_back(i);
        for (auto j = pr.begin(); j != pr.end() && *j * i <= 3000; j++)
        {
            ipr[*j * i] = 1;
            if (i % *j == 0)
                break;
        }
    }
    int up = max(max(n,m),w);
    f[0][0] = 1;
    for (int i = 1; i <= up; i++)
        for (int j = 1; j <= i >> 1; j++)
            for (auto k = pr.begin(); k != pr.end() && *k <= i; k++)
                f[i][j] = (f[i][j] + f[i - *k][j - 1]) % mod;
    up *= 3;
    fac[0] = 1;
    for (int i = 1; i <= up; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[up] = Inv(fac[up]);
    for (int i = up - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int dp(node x,node y)
{
    int dx = y.x - x.x;
    int dy = y.y - x.y;
    int dz = y.z - x.z;
    if (dx < 0 || dy < 0 || dz < 0)
        return 0;
    int ret = 0;
    for (int sum = 0; sum <= (dx >> 1) + (dy >> 1); sum++)
    {
        int sum1 = 0;
        for (int i = 0; i <= sum; i++)
            if (int j = sum - i; i <= (dx >> 1) && j <= (dy >> 1))
                sum1 = (sum1 + f[dx][i] * inv[i] % mod * f[dy][j] % mod * inv[j] % mod) % mod;
        int sum2 = 0;
        for (int k = 0; k <= (dz >> 1); k++)
            sum2 = (sum2 + f[dz][k] * inv[k] % mod * fac[sum + k] % mod) % mod;
        ret = (ret + sum1 * sum2 % mod) % mod;
    }
    return ret;
}
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&w);
    st = {1,1,1};
    en = {n,m,w};
    scanf("%lld%lld%lld",&p1.x,&p1.y,&p1.z);
    scanf("%lld%lld%lld",&p2.x,&p2.y,&p2.z);
    init();
    if (p2.x <= p1.x && p2.y <= p1.y && p2.z <= p1.z)
		swap(p1, p2);
    int ans1 = dp(st,en);
    int ans2 = dp(st,p1) * dp(p1,en) % mod;
    int ans3 = dp(st,p2) * dp(p2,en) % mod;
    int ans4 = dp(st,p1) * dp(p1,p2) % mod * dp(p2,en) % mod;
    int ans = (((ans1 + ans4) % mod - (ans2 + ans3) % mod) % mod + mod) % mod;
    printf("%lld",ans);
    return 0;
}