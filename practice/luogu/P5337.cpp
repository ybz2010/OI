#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
char s1[maxn];
struct mat
{
    int a[26][26];
    mat(int x = 0)
    {
        memset(a,0,sizeof a);
        for (int i = 0; i < 26; i++)
            a[i][i] = x;
    };
    mat operator*(mat x)
    {
        mat ret(0);
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                for (int k = 0; k < 26; k++)
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * x.a[k][j] % mod) % mod;
        return ret;
    }
}base;
template<typename type>type binpow(type x,int y)
{
    type ret(1);
    while (y)
    {
        if (y & 1)
            ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}
signed main()
{
    scanf("%lld",&n);
    scanf("%s",s1 + 1);
    int len = strlen(s1 + 1);
    for (int i = 1; i < len; i++)
        base.a[s1[i] - 'a'][s1[i + 1] - 'a'] = 1;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            base.a[i][j] ^= 1;
    base = binpow(base,n - 1);
    int ans = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            ans = (ans + base.a[i][j]) % mod;
    printf("%lld",ans);
    return 0;
}