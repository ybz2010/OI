#include<bits/extc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1 << 24 | 5;
int n;
int sum[maxm];
char s[maxn][3];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s[i]);
        sum[(1 << (s[i][0] - 'a')) | (1 << (s[i][1] - 'a')) | (1 << (s[i][2] - 'a'))]++;
    }
    for (int i = 0; i < 24; i++)
        for (int k = 0; k < (1 << 24); k++)
            if (k & (1 << i))
                sum[k] += sum[k ^ (1 << i)];
    int ans = 0;
    for (int i = 0; i < (1 << 24); i++)
        ans ^= (n - sum[i]) * (n - sum[i]);
    printf("%d",ans);
    return 0;
}