#include <bits/extc++.h>
using namespace std;
const int mod = 45989;
struct Matr
{
	int m[150][150];
	int R, C;
	Matr() { memset(m, 0, sizeof(m)); }
	Matr operator*(const Matr &a) const
	{
		Matr t;
		t.R = R;
		t.C = a.C;
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= t.C; j++)
				for (int k = 1; k <= C; k++)
					t.m[i][j] = (t.m[i][j] + (m[i][k] * a.m[k][j]) % mod) % mod;
		return t;
	}
} ini, trans; // 分别是初始矩阵和转移矩阵
struct E
{
	int u, v;
} e[127]; // 为了更方便的枚举边使用邻接表存储边
int first[57], nt[127], idx;
int N, M, S, T, t;
Matr operator^(Matr a, int k) // 矩阵快速幂
{
	Matr s;
	s.C = a.C;
	s.R = a.R;
	for (int i = 1; i <= a.R; i++)
		s.m[i][i] = 1;
	while (k)
	{
		if (k & 1)
			s = s * a;
		a = a * a;
		k >>= 1;
	}
	return s;
}
int anti(int x) // 因为我是从1开始存边所以不能异或只能自己写函数了
{
	return x % 2 == 0 ? x - 1 : x + 1;
}
int main()
{
	scanf("%d%d%d%d%d", &N, &M, &t, &S, &T);
	if (t == 0) // 特殊判断t=0的情况
	{
		puts("0");
		return 0;
	}
	int u, v;
	S++;
	T++; // 题目给的是0开始编号要记得加
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d", &u, &v);
		u++;
		v++; // 要记得加
		e[++idx] = (E){u, v};
		nt[idx] = first[u];
		first[u] = idx;
		e[++idx] = (E){v, u};
		nt[idx] = first[v];
		first[v] = idx;
	}
	for (int i = 1; i <= idx; i++)
	{ // 如果某一条边的始点与当前这条边的终点重合
	  // 则称当前这条边可以转移到"某一条边"
		for (int k = first[e[i].v]; k; k = nt[k])
		{
			if (k != anti(i))	 // 记得不可以是反边，否则会违背题目要求
				trans.m[k][i]++; // 下标千万莫写反了，自己要搞清楚
		}
	}
	trans.C = trans.R = idx; // 矩阵大小表示
	ini.R = idx;
	ini.C = 1; // 表示错了乘法无法正确进行
	for (int i = first[S]; i; i = nt[i])
		ini.m[i][1]++; // 由于初状态不好确定
	// 干脆就把初始矩阵当成已经走出的距离为1时的状态
	trans = trans ^ (t - 1);
	// 因为初始矩阵当成了距离为1的状态这里只能t-1次幂
	for (int i = 1; i <= idx; i++)
	{
		for (int j = 1; j <= idx; j++)
			cout << trans.m[i][j] << " ";
		cout << endl;
	}
	// trans=trans*ini;
	// int ans=0;
	// for(int i=first[T];i;i=nt[i])
	//     //直接枚举终点为给定点的边不太好枚举
	//     //就枚举始点为给定终点的边然后取反边即可
	// ans=(ans+trans.m[anti(i)][1])%mod;//我最开始还没取模.....
	// printf("%d",ans);
	return 0;
}