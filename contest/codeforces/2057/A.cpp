#include<bits/extc++.h>
using namespace std;
signed main()
{
    int t,n,m;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",max(n,m) + 1);
    }
    return 0;
}