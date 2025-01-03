#include <bits/stdc++.h>
using namespace std;

void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		x = x * 10 + (ch & 15), ch = getchar();
}

int a, b, num[15];

struct long_int
{
	short d[2050];
	int len;
    long_int(){memset(d,0,sizeof d);len = 0;}
    short &operator[](int x){return d[x];}
	long_int operator*(const long_int &rhs) const
	{
		long_int res;
		res.len = rhs.len + len - 1;
		for (int i = 1; i <= len; i++)
			for (int j = 1; j <= rhs.len; j++)
			{
				res.d[i + j - 1] += d[i] * rhs.d[j];
			}
		for (int i = 1; i <= res.len; i++)
		{
			res.d[i + 1] += res.d[i] / 10, res.d[i] %= 10;
			if (i == res.len && res.d[i + 1])
				res.len++;
		}
		return res;
	}
	bool operator<(const long_int &rhs) const
	{
		if (len != rhs.len)
			return len < rhs.len;
		for (int i = len; i >= 1; i--)
			if (d[i] != rhs.d[i])
				return d[i] < rhs.d[i];
		return false;
	}
	void write()
	{
		for (int i = len; i >= 1; i--)
			printf("%d", d[i]);
		puts("");
	}
} x, y, tmp1, tmp2;

void solve()
{
	read(a), read(b);
	if (a > b)
		swap(a, b);
	x.len = a, y.len = b;
	for (int i = 1; i <= 9; i++)
		read(num[i]);
	for (int i = 9; i >= 1; i--)
		while (num[i]--)
		{
			if (!a)
				y.d[b--] = i;
			else if (!b)
				x.d[a--] = i;
			else if (a == x.len && b == y.len)
				x.d[a--] = i;
			else if (b == y.len)
				y.d[b--] = i;
			else
			{
				x.d[a--] = i;
				tmp1 = x * y;
				x.d[++a] = 0;
				y.d[b--] = i;
				tmp2 = x * y;
				y.d[++b] = 0;
				if (tmp1 < tmp2)
					y.d[b--] = i;
				else
					x.d[a--] = i;
			}
		}
	(x * y).write();
}

signed main()
{
	//	freopen ("math.txt", "w", stdout);
	int t;
	read(t);
	while (t--)
		solve();
	return 0;
}