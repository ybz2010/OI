#include<bits/extc++.h>
#define int long long
#define maxn 10005
using namespace std;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m;
int sx,sy,ex,ey;
bool mp[maxn][maxn];
int vis[maxn][maxn];
struct vertex{
	int x,y,len,dir[4];
	vertex(int x,int y):x(x),y(y){memset(dir,0,sizeof dir);len = 0;}
};
int bfs(int x,int y)
{
	queue<vertex>q;
	vertex tmp = vertex(x,y);
	q.push(tmp);
	vis[x][y] = 1;
	while (!q.empty())
	{
		vertex u = q.front();
		cout << u.x << " " << u.y << "\n";
		if (u.x == ex && u.y == ey)
			return u.len;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = u.x + dir[i][0];
			int ty = u.y + dir[i][1];
			cout << tx << " " << ty << " " << mp[tx][ty] << " " << vis[tx][ty] << " " << u.dir[i] << endl;
			if (mp[tx][ty] || vis[tx][ty] >= 2 || u.dir[i] == 3)
				continue;
			vertex tmp(tx,ty);
			memset(tmp.dir,0,sizeof tmp.dir);
			tmp.dir[i] = u.dir[i] + 1;
			tmp.len = u.len + 1;
			vis[tx][ty] ++;
			q.push(tmp);
		}
		cout << endl;
	}
	return 114514;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	memset(mp,0,sizeof mp);
	memset(vis,0,sizeof vis);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			mp[i][j] = (c == '#');
			if (c == 'S')
				sx = i,sy = j;
			else if (c == 'T')
				ex = i,ey = j;
		}
	}
	cout << bfs(sx,sy);
	return 0;
}
