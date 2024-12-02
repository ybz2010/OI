#include<bits/extc++.h>
using namespace std;
int n,k;
int p[25],p1[25];
vector<pair<int,string> >a;
string tostring(int x[])
{
    string ret;
    for (int i = 1; i <= n; i++)
        ret.push_back(x[i] + '0');
    return ret;
}
int calc()
{
    int ret = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (p[j] > p[i])
                ret ++;
    return ret;
}
signed main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    do
    {
        a.push_back({calc(),tostring(p)});
    }while(next_permutation(p + 1,p + n + 1));
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++)
        printf("%c ",a[k - 1].second[i]);
    return 0;
}