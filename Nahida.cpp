#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
int num[20];
int f[20][20][5];
int dfs(int pos,bool lim,int sum,bool zero,int d)
{
    if(!pos)
        return sum;
    if(!lim&&f[pos][sum][zero])
        return f[pos][sum][zero];
    int up=lim?num[pos]:9,ret=0;
    for(int i=0;i<=up;i++)
        ret+=dfs(pos-1,lim&&i==up,sum+((!zero||i)&&i==d),zero&&!i,d);
    f[pos][sum][zero]=ret;
    return ret;
}
int solve(int x,int d)
{
    int idx=0;
    while(x)
    {
        num[++idx]=x%10;
        x/=10;
    }
    memset(f,0,sizeof(f));
    return dfs(idx,1,0,1,d);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    for(int i=0;i<10;i++)
        cout<<solve(b,i)-solve(a-1,i)<<" ";
    return 0;
}
/*
Do you play Genshin Impact?
Genshin Impact,what a waste it is!
by ybz2010 or __dragon_
*/