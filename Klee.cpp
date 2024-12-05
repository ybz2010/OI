#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3f3f3f3f

const int maxn=705;
const int maxm=1;

int n,m,ans=INF;

int cnt1,cnt2;

int head[maxn],nxt[(maxn*maxn)<<1],to[(maxn*maxn)<<1],cnt;

inline void add(int u,int v){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}

bool g[maxn][maxn];

int vis[maxn];

bitset <705> f;

void dfs(int u,int fa,int color){
	if(vis[u]){
		if(vis[u]==color)return;
		if(vis[u]^color){
			puts("-1");
			exit(0);
		}
	}
	vis[u]=color;
	vis[u]==1?cnt1++:cnt2++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa)continue;
		dfs(v,u,3-color);
	}
}

inline int calc(int x){
	return (x*(x-1)/2)+((n-x)*(n-x-1)/2);
}

namespace IO{
	template<typename T>
	inline void read(T &x){
		x=0;T f=1;char ch=getchar();
		while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
		while (isdigit(ch)){x=x*10+(ch^48);ch=getchar();}
		x*=f;
	}

	template <typename T, typename... Args>
	inline void read(T& t, Args&... args){
		read(t); read(args...);
	}

	template<typename T>
	void write(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}

	template<typename T,typename... Args>
	void write(T t,Args... args){
		write(t);putchar(' ');write(args...);
	}
}

using namespace IO;

signed main(){
#ifdef LawrenceSivan
	freopen("aa.in","r", stdin);
	freopen("aa.out","w", stdout);
#endif
	read(n,m);
	for(int i=1,u,v;i<=m;i++){
		read(u,v);
		g[u][v]=g[v][u]=true;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!g[i][j]&&i!=j){
				add(i,j);
				add(j,i);
			}
		}
	}

	f[0]=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cnt1=cnt2=0;
			dfs(i,0,1);
			for(int j=n;~j;j--){
				bool t=false;
				if(j>=cnt1)t|=f[j-cnt1];
				if(j>=cnt2)t|=f[j-cnt2];
				f[j]=t;
			}
		}
	}

	for(int i=0;i<=n;i++){
		if(f[i])ans=min(ans,calc(i));
		cout << f[i];
	}

	write(ans),puts("");


	return 0;
}