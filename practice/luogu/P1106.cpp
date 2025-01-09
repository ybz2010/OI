#include<bits/extc++.h>
using namespace std;
int n,k;
char s[255];
signed main()
{
    scanf("%s%d",s + 1,&k);
    n = strlen(s + 1);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[j] > s[j + 1])
            {
                for (int k = j; k <= n; k++)
                    s[k] = s[k + 1];
                n --;
                break;
            }
        }
    }
    int pos = 1;
    while (s[pos] == '0')
        pos ++;
    if (pos <= n)
        printf("%s",s + pos);
    else
        printf("0");
    return 0;
}