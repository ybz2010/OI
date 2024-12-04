#include<cstdio>
typedef long long ll;
const int MAXN = 1e5 + 5;
const ll mod = 1e9 + 7;

char s[MAXN*2];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	if(s[1]=='W' || s[n<<1]=='W')
	{
		printf("0");
		return 0;
	}
	ll ans=1, t=1, last=1;
	for(int i=2; i<=(n*2); ++i)
	{	
		if(s[i]!=s[i-1])
		{
			if(last) ++t;
			else --t;
		}
		else
		{
			if(last) --t;
			else ++t;
			last=!last;
		}
		if(!last)
			ans = ans*(t+1) %mod;
		if(t<0)
		{
			printf("0");
			return 0;
		}
	}
	if(t)
	{
		printf("0");
		return 0;
	}
	
	for(int i=1; i<=n; ++i) ans = ans*i%mod;
	printf("%lld",ans);
	return 0;
}
