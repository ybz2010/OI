#include<bits/extc++.h>
using namespace std;
int n;
int a[15],b[15];
vector<vector<int> >ans;
int cost()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret += abs(a[i] - b[i]);
    return ret;
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        a[i] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d",b + i);
    int sum = -1;
    do
    {
        int c = cost();
        if (c > sum)
        {
            sum = c;
            ans.clear();
            vector<int>tmp;
            for (int i = 1; i <= n; i++)
                tmp.push_back(a[i]);
            ans.push_back(tmp);
        }
        else if (c == sum)
        {
            vector<int>tmp;
            for (int i = 1; i <= n; i++)
                tmp.push_back(a[i]);
            ans.push_back(tmp);
        }
    } while (next_permutation(a + 1, a + n + 1));
    cout << sum << endl;
    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}