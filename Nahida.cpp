#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxv=64+10;
int t,cnt1,cnt2;
int x[maxv],z[maxv];
ll ans,X,Z;
ll dp[maxv][3][2];
ll read()
{
	ll ret=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*w;
}
void init()
{
	cnt1=cnt2=0;
	memset(dp,-1,sizeof(dp));
}
void inpu() {Z=read(),X=read();}
void prepa()
{
	while(X) {x[++cnt1]=X%10;X/=10;}
	while(Z) {z[++cnt2]=Z%10;Z/=10;}
	while(cnt1<cnt2) x[++cnt1]=0;
	while(cnt2<cnt1) z[++cnt2]=0;
}
bool check(int pos,bool legal,int num)
{
	if(num!=x[pos]) return num>x[pos];
	return legal;
}
ll dfs(int pos,int isadd,bool islegal)
{
	ll ret=0;
	if(dp[pos][isadd][islegal]!=-1) return dp[pos][isadd][islegal];
	else if(pos==cnt2+1) return dp[pos][isadd][islegal]=!islegal;
	else
	{
		if(z[pos]==0)
		{
			for(int i=0;i<=3;i++) ret+=dfs(pos+1,0,check(pos,islegal,i));
			if(isadd>=1) ret+=dfs(pos+1,2,check(pos,islegal,4));
			if(isadd==0) ret+=dfs(pos+1,0,check(pos,islegal,4));
			for(int i=5;i<=9;i++) ret+=dfs(pos+1,1,check(pos,islegal,i));
		}else if(z[pos]==1)
		{
			if(isadd>=1)
			{
				for(int i=0;i<=4;i++) ret+=dfs(pos+1,0,check(pos,islegal,i));
				for(int i=5;i<=9;i++) ret+=dfs(pos+1,1,check(pos,islegal,i));
			}else ret+=dfs(pos+1,0,check(pos,islegal,1));
		}else
		{
			if(isadd<=1) ret+=dfs(pos+1,0,check(pos,islegal,z[pos]-isadd));
			else 
				for(int i=0;i<=1;i++)
					ret+=dfs(pos+1,0,check(pos,islegal,z[pos]-i));
		}	
	}
	return dp[pos][isadd][islegal]=ret;
}
void solve()
{
	init();
	inpu();
	prepa();
	ans=dfs(1,0,0);
	printf("%lld\n",ans);
}
int main()
{
	t=read();
	while(t--) solve();
	return 0;
}