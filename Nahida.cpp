#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int Mod = 1e9 + 9;
const int N = 35, M = 15, L = 905;
int g[N][N], f[N][N][M], c[L][L];
int x, n, m, C, Ans;

int main()
{		
	scanf("%d%d%d", &n, &m, &C);

	const int tmp = n * m;
	for (int i = 0; i <= tmp; ++i)
		c[i][0] = 1;
	for (int i = 1; i <= tmp; ++i)
		for (int j = 1; j <= i; ++j)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
	
	f[0][0][0] = 1;
	for (int k = 1; k <= C; ++k) 
	{
		scanf("%d", &x);
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			if (i * j >= x)
			{
				g[i][j] = c[i * j][x];
				for (int l = 1; l <= i; ++l)
					for (int r = 1; r <= j; ++r)
					if (l < i || r < j)
						g[i][j] = ((ll)g[i][j] - (ll)g[l][r] * c[i][l] % Mod * c[j][r] % Mod + Mod) % Mod;
			}
			
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				for (int l = 0; l < i; ++l)
					for (int r = 0; r < j; ++r)
					{
						int tx = i - l, ty = j - r;
						if (tx * ty >= x)
							(f[i][j][k] += (ll)f[l][r][k - 1] * g[tx][ty] % Mod * c[n - l][tx] % Mod * c[m - r][ty] % Mod) %= Mod;
					}
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			(Ans += f[i][j][C]) %= Mod;
	printf("%d\n", Ans);
	return 0;
}