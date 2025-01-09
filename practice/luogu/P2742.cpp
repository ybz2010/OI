#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 1e5 + 5;
int n;
int ans[maxn],top;
struct node{double x,y,ang;}a[maxn];
double dis(node x,node y){return sqrt(sq(x.x - y.x) + sq(x.y - y.y));}
double mul(node x,node y){return x.x * y.y - x.y * y.x;}
bool operator<(const node &x,const node &y){return x.ang != y.ang ? x.ang < y.ang : dis(a[1],x) < dis(a[1],y);}
node operator-(const node &x,const node &y){return {x.x - y.x,x.y - y.y,0};}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);
        if (a[1].y > a[i].y)
            swap(a[1],a[i]);
    }
    for (int i = 2; i <= n; i++)
        a[i].ang = atan2(a[i].y - a[1].y,a[i].x - a[1].x);
    sort(a + 2,a + n + 1);
    ans[++top] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top > 1 && mul(a[ans[top]] - a[ans[top - 1]],a[i] - a[ans[top]]) < 0)
            top--;
        ans[++top] = i;
    }
    ans[++top] = 1;
    double sum = 0;
    for (int i = 1; i < top; i++)
        sum += dis(a[ans[i]],a[ans[i + 1]]);
    printf("%.2lf",sum);
    return 0;
}