#include<bits/extc++.h>
using namespace std;
const int maxn = 5005;
int n,s;
int a,b;
multiset<int>st;
signed main()
{
    cin >> n >> s >> a >> b;
    a += b;
    for (int i = 1,x,y; i <= n; i++)
    {
        cin >> x >> y;
        if (x <= a)
            st.insert(y);
    }
    int cnt = 0;
    for (auto i : st)
    {
        if (i > s)
            break;
        cnt ++;
        s -= i;
    }
    cout << cnt;
    return 0;
}