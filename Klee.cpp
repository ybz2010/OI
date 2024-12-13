#include<bits/stdc++.h>
#define il inline
#define int long long //不开ll见祖宗 

using namespace std;
const int N = 1e6 + 10;

vector<int> v[N], b[N];

il int re()
{
	int x = 0, p = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') p = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * p;
}

int n, m, s;
int dp2[50][5000], dp1[50][5000];//注意这里不要开太小！！！ 

void init()//多组数据 
{
	s = 0;
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);;
	for(int i = 0; i <= 50; ++i) v[i].clear(), b[i].clear();
}

signed main()
{
	while(1)
	{
		n = re(), m = re();
		if(n == -1) break;
		init();
    	int u,val,tmp;
		for(int i = 1; i <= n; ++i)//读入
		{
			u = re(), val = re(), tmp = 0;
			while(((u >> tmp) & 1) == 0) tmp++;//记录每一个物品的二进制的表示 
			v[tmp].push_back(val);
			b[tmp].push_back((u >> tmp));
		}
		while((m >> s)) s++;//总的体积的位数 
		for (int i = 0; i <= s; i++)
			for (int j = 0; j < b[i].size(); j++)
				for (int k = 500; k >= b[i][j]; k--)
					dp1[i][k] = max(dp1[i][k],dp1[i][k - b[i][j]] + v[i][j]);
		for (int i = 0; i <= s; i++)
			for (int j = 500; j >= 0; j--)
				for (int k = 0; k <= j; k++)
					dp2[i][j] = max(dp2[i][j],dp2[i - 1][((j - k) << 1) + ((m >> (i - 1)) & 1)] + dp1[i][k]);
		printf("%lld\n", dp2[s - 1][1]);
	}
}