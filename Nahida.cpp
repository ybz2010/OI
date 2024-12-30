#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e3 + 10;
const int mod = 1e9 + 7;
int pr[] = {
	0,
	2,
	3,
	5,
	7,
	11,
	13,
	17,
	19,
	23,
	29,
	31,
	37,
	41,
	43,
	47,
	53,
	59,
	61,
	67,
	71,
	73,
	79,
	83,
	89,
	97,
	101,
	103,
	107,
	109,
	113,
	127,
	131,
	137,
	139,
	149,
	151,
	157,
	163,
	167,
	173,
	179,
	181,
	191,
	193,
	197,
	199,
	211,
	223,
	227,
	229,
	233,
	239,
	241,
	251,
	257,
	263,
	269,
	271,
	277,
	281,
	283,
	293,
	307,
	311,
	313,
	317,
	331,
	337,
	347,
	349,
	353,
	359,
	367,
	373,
	379,
	383,
	389,
	397,
	401,
	409,
	419,
	421,
	431,
	433,
	439,
	443,
	449,
	457,
	461,
	463,
	467,
	479,
	487,
	491,
	499,
	503,
	509,
	521,
	523,
	541,
	547,
	557,
	563,
	569,
	571,
	577,
	587,
	593,
	599,
	601,
	607,
	613,
	617,
	619,
	631,
	641,
	643,
	647,
	653,
	659,
	661,
	673,
	677,
	683,
	691,
	701,
	709,
	719,
	727,
	733,
	739,
	743,
	751,
	757,
	761,
	769,
	773,
	787,
	797,
	809,
	811,
	821,
	823,
	827,
	829,
	839,
	853,
	857,
	859,
	863,
	877,
	881,
	883,
	887,
	907,
	911,
	919,
	929,
	937,
	941,
	947,
	953,
	967,
	971,
	977,
	983,
	991,
	997,
},
	cnt = 168; // 1000 以内的质数
int f[N][N], M;
int fac[N], inv[N];
struct rec
{
	int x, y, z;
} st, p1, p2, en;
int expow(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
void init(int n)
{
	// 预处理 g
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i / 2; j++)
			for (int k = 1; k <= cnt && pr[k] <= i; k++)
				f[i][j] = (f[i][j] + f[i - pr[k]][j - 1]) % mod;
	// 预处理阶乘
	n *= 3; // i+j+k<3000
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[n] = expow(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}
int dp(rec x, rec y)
{
	int dx = y.x - x.x;
    int dy = y.y - x.y;
    int dz = y.z - x.z;
    if (dx < 0 || dy < 0 || dz < 0)
        return 0;
    int ret = 0;
    for (int sum = 0; sum <= (dx >> 1) + (dy >> 1); sum++)
    {
        int sum1 = 0;
        for (int i = 0; i <= sum; i++)
            if (int j = sum - i; i <= (dx >> 1) && j <= (dy >> 1))
                sum1 = (sum1 + f[dx][i] * inv[i] % mod * f[dy][j] % mod * inv[j] % mod) % mod;
        int sum2 = 0;
        for (int k = 0; k <= (dz >> 1); k++)
            sum2 = (sum2 + f[dz][k] * inv[k] % mod * fac[sum + k] % mod) % mod;
        cout << sum1 << " " << sum2 << endl;
        ret = (ret + sum1 * sum2 % mod) % mod;
    }
    return ret;
}
int n, m, w;
int r1, c1, h1;
int r2, c2, h2;
signed main()
{
	scanf("%lld %lld %lld", &n, &m, &w);
    st = {1,1,1};
    en = {n,m,w};
    scanf("%lld%lld%lld",&p1.x,&p1.y,&p1.z);
    scanf("%lld%lld%lld",&p2.x,&p2.y,&p2.z);
	init(max(max(n, m), w));
	if (r2 <= r1 && c2 <= c1 && h2 <= h1)
		swap(p1, p2);
    int ans1 = dp(st,en);
    int ans2 = dp(st,p1) * dp(p1,en) % mod;
    int ans3 = dp(st,p2) * dp(p2,en) % mod;
    int ans4 = dp(st,p1) * dp(p1,p2) % mod * dp(p2,en) % mod;
	printf("%lld", ((ans1 - ans2 - ans3 + ans4) % mod + mod) % mod); // 容斥
	return 0;
}