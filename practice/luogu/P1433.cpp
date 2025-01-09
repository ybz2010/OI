#include<bits/extc++.h>
#define float double
using namespace std;
int n;
float x[20],y[20];
float dp[20][(1 << 15) + 5];
float dis(int a,int b){return sqrt(pow(x[a] - x[b],2) + pow(y[a] - y[b],2));}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf",x + i,y + i);
    memset(dp,0x7f,sizeof dp);
    for (int i = 1; i <= n; i++)
        dp[i][1 << (i - 1)] = dis(0,i);
    for (int i = 1; i < (1 << n); i++)
        for (int k = 1; k <= n; k++)
            if (i & (1 << (k - 1)))
                for (int j = 1; j <= n; j++)
                    if (!(i & (1 << (j - 1))))
                        dp[j][i | (1 << (j - 1))] = min(dp[j][i | (1 << (j - 1))],dp[k][i] + dis(k,j));
    float ans = 1145141919810;
    for (int i = 1; i <= n; i++)
        ans = min(ans,dp[i][(1 << n) - 1]);
    printf("%.2lf",ans);
    return 0;
}