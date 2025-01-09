#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,len;
char s[205][12],str[maxn];
bool dp[maxn];
signed main()
{
    while (scanf("%s",str + 1))
    {
        if (strcmp(str + 1,".") == 0)
            break;
        strcpy(s[++n] + 1,str + 1);
    }
    memset(str,0,sizeof str);
    while (scanf("%s",str + strlen(str + 1) + 1) != EOF);
    len = strlen(str + 1);
    dp[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= n && !dp[i]; j++)
        {
            int tmp = strlen(s[j] + 1);
            if (i < tmp || !dp[i - tmp])
                continue;
            bool fl = 1;
            for (int k = 1; k <= tmp && fl; k ++)
                if (s[j][k] != str[i - tmp + k])
                    fl = 0;
            dp[i] = (fl && dp[i - tmp]);
        }
    }
    int ans = 0;
    for (int i = len; i >= 1; i--)
    {
        if (dp[i])
        {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}