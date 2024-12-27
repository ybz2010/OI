#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e4 + 5;
const int maxm = 6e4 + 5;
int n,d;
int cnt[6],ans[6],tmp[maxm];
char s[maxn][6];
int hsh(char ch){return isdigit(ch) ? ch - '0' : ch - 'a' + 10;}
int hsh(char ch1,char ch2){return hsh(ch1) * 36 + hsh(ch2);}
int hsh(char ch1,char ch2,char ch3){return hsh(ch1) * 36 * 36 + hsh(ch2) * 36 + hsh(ch3);}
signed main()
{
    scanf("%lld%lld",&n,&d);
    for (int i = 1; i <= n; i++)
        scanf("%s",s[i] + 1);
    for (int x = 1; x <= 4; x++)
    {
        memset(tmp,0,sizeof tmp);
        for (int i = 1; i <= n; i++)
            tmp[hsh(s[i][x])] ++;
        for (int i = 0; i <= 6e4; i++)
            cnt[1] += (tmp[i] * (tmp[i] - 1)) >> 1;
    }
    for (int x = 1; x <= 4; x++)
    {
        for (int y = x + 1; y <= 4; y++)
        {
            memset(tmp,0,sizeof tmp);
            for (int i = 1; i <= n; i++)
                tmp[hsh(s[i][x],s[i][y])] ++;
            for (int i = 0; i <= 6e4; i++)
                cnt[2] += (tmp[i] * (tmp[i] - 1)) >> 1;
        }
    }
    for (int x = 1; x <= 4; x++)
    {
        for (int y = x + 1; y <= 4; y++)
        {
            for (int z = y + 1; z <= 4; z++)
            {
                memset(tmp,0,sizeof tmp);
                for (int i = 1; i <= n; i++)
                    tmp[hsh(s[i][x],s[i][y],s[i][z])] ++;
                for (int i = 0; i <= 6e4; i++)
                    cnt[3] += (tmp[i] * (tmp[i] - 1)) >> 1;
            }
        }
    }
    ans[3] = cnt[3];
    ans[2] = cnt[2] - 3 * ans[3];
    ans[1] = cnt[1] - ans[2] * 2 - ans[3] * 3;
    ans[0] = ((n * (n - 1)) >> 1) - ans[1] - ans[2] - ans[3];
    printf("%lld",ans[4 - d]);
    return 0;
}