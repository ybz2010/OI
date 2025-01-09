#include<bits/extc++.h>
using namespace std;
vector<int>v = {1,2,4,5};
signed main()
{
    v.insert(v.begin() + 2,3);
    for (auto i : v)
        cout << i << endl;
    return 0;
}