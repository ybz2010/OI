#include <bits/stdc++.h>
#define int long long
using namespace std;

void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		x = x * 10 + (ch ^ 48), ch = getchar();
}
void write(int x)
{
	if (x > 9)
		write(x / 10);
	putchar('0' + x % 10);
}

const int maxn = 510;
unordered_map<int, int> need, cnt;
int m, q, t[maxn];
struct node
{
	int x, cnt;
	bool operator<(const node &rhs) const
	{
		return cnt == rhs.cnt ? x < rhs.x : cnt > rhs.cnt;
	}
};
set<node> a;

int check(int x)
{
	int res = 1;
	for (int i = 1, cnt = 0; i <= m; i++, cnt = 0)
	{
		while (x % t[i] == 0)
			cnt++, x /= t[i];
		if (cnt % 3 == 1)
			res *= (t[i] * t[i]);
		else if (cnt % 3 == 2)
			res *= t[i];
	}
	if (cbrt(x) != (int)cbrt(x))
		return -1;
	return res;
}

signed main()
{
	read(m);
	for (int i = 1; i <= m; i++)
		read(t[i]);
	read(q);
	for (int i = 1, op, x; i <= q; i++)
	{
		read(op);
		if (op == 1)
		{
			read(x);
			need[x] = check(x);
			if (need[x] == -1)
				continue;
			a.erase({need[x], cnt[need[x]]});
			cnt[need[x]]++;
			a.insert({need[x], cnt[need[x]]});
		}
		else if (op == 2)
		{
			read(x);
			if (need[x] == -1)
				continue;
			a.erase({need[x], cnt[need[x]]});
			cnt[need[x]]--;
			a.insert({need[x], cnt[need[x]]});
		}
		else
		{
			write((*a.begin()).x), putchar('\n');
		}
	}
	return 0;
}