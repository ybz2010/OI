#include<bits/extc++.h>
using namespace std;
signed main()
{
    vector<int>a = {1,2,3,4,5,7,10};
    cout << lower_bound(a.begin(),a.end(),6) - a.begin();
    return 0;
}