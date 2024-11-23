#include<bits/stdc++.h>
using namespace std;
int randseed,n,m,Q;
int x[2000001],y[2000001],w[2000001],x2[2000001],y2[2000001],fw[2000001];
struct sj{
	int w,t,u,v,id;
};
sj gb[2000001];
unsigned int rnd(){
	unsigned int r;
	r = randseed = randseed * 1103515245 + 12345;
	return (r << 16) | ((r >> 16) & 0xFFFF);
}
void init(){
	cin>>n>>m>>Q>>randseed;
	for (int i=1;i<=m;i++) {x[i]=rnd()%n+1; y[i]=rnd()%n+1;}
	for (int i=1;i<=Q;i++) {gb[i].t=rnd()%m+1; gb[i].u=rnd()%n+1; gb[i].v=rnd()%n+1;gb[i].id=rnd()%n+1;gb[i].w=i;}
	return;
}
bool ff(sj a,sj b){
	return a.t<b.t;
}
signed main(){
	init();
	int a(1);
	for(int v=1;v<=n;++v){
		w[v]=v;//第v个点的坐标
	}
	sort(gb+1,gb+1+Q,ff);
	for(int v=1;v<=m;++v){
		x2[v]=w[x[v]];//第v次交换了哪两个
		y2[v]=w[y[v]];
		swap(w[x[v]],w[y[v]]);
		while(a<=Q&&gb[a].t==v){
			gb[a].u=w[gb[a].u];//第a次查询会交换哪两个
			gb[a].v=w[gb[a].v];
			++a;
		}
	}
	for(int v=1;v<=n;++v){
		fw[w[v]]=v;//最终第i位是哪个人
	}
	long long b(0);
	for(int v=1;v<=Q;++v){
		if(x2[gb[v].t]==gb[v].id){
			gb[v].id=y2[gb[v].t];//有关就交换
		}
		else if(y2[gb[v].t]==gb[v].id){
			gb[v].id=x2[gb[v].t];//同上
		}
		if(gb[v].u==gb[v].id){
			gb[v].id=gb[v].v;//操作时有就交换
		}
		else if(gb[v].v==gb[v].id){
			gb[v].id=gb[v].u;//同上
		}
		b=(b+(long long)fw[gb[v].id]*gb[v].w)%998244353;
	}
	cout<<b;
	return 0;
}
