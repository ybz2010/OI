#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,q;
struct sumeru
{
    int r,x,y,id;
    bool operator<(sumeru a)
    {
        if (x == a.x)
            return y < a.y;
        else
            return x < a.x;
    }
}que;
set<sumeru> st;
int dis(sumeru x,sumeru y){return abs(x.x - y.x) + abs(x.y - y.y);}
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld%lld%lld",&que.x,&que.y,&que.r);
        que.id = i;
        auto it = st.upper_bound(que);
    }
    return 0;
}
//咱就是说：
//须弥有20万人口吗你就放20万个花环？？！