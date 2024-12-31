#include<bits/extc++.h>
using namespace std;
int n;
int h[155][155];
signed main()
{
    scanf("%d",&n);
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ch;
            h[i][j] = h[i - 1][j];
            if (ch == 'W')
                h[i][j] ++;
            else
                h[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp = 114514;
            for (int k = j; k <= n && h[i][k]; k++)
            {
                tmp = min(tmp,h[i][k]);
                ans += tmp;
            }
        }
    }
    printf("%d",ans);
    return 0;
}