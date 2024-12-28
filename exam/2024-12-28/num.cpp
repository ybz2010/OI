#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,l,r,cnt,idx;
int s[12],a[15];
int dp[12][2][50005];
int dfs(int idx,bool lim,bool zero,int left)
{
    if (idx == 0)
        return left == 0 ? 1 : 0;
    if (!lim && ~dp[idx][2][left])
        return dp[idx][zero][left];
    int up = lim ? a[idx] : 9,ret = 0;
    for (int i = zero && s[1] ? 0 : 1; i <= cnt && s[i] <= up; i++)
        ret += dfs(idx - 1,lim && s[i] == up,zero && s[i] == 0,(left * 10 + s[i]) % x);
    if (!lim)
        dp[idx][zero][left] = ret;
    return ret;
}
int getans(int val)
{
    idx = 0;
    memset(a,0,sizeof a);
    memset(dp,-1,sizeof dp);
    while (val)
    {
        a[++idx] = val % 10;
        val /= 10;
    }
    return dfs(idx,1,1,0);
}
signed main()
{
    scanf("%lld%lld%lld",&x,&l,&r);
    string str;
    cin >> str;
    for (auto i : str)
    {
        s[++cnt] = i - '0';
        a[i - '0'] = 1;
    }
    if (x <= 5e4)
        printf("%lld\n",getans(r) - getans(l - 1));
    else
    {
        int cnt = 0;
        l = ceil((double)l / x) * x;
        for (int i = l; i <= r; i += x)
        {
            int tmp = i,fl = 1;
            while (tmp)
            {
                if (!a[tmp % 10])
                {
                    fl = 0;
                    break;
                }
                tmp /= 10;
            }
            cnt += fl;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
/*
114514191 114 14514112411
0123456
g++ num.cpp -o num.out -O2 -std=c++14
./num.out < data.txt

*/
