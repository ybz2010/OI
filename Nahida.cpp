#include<bits/extc++.h>
using namespace std;
signed main()
{
    set<int,less_equal<int> >st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    auto i = st.upper_bound(2);
    cout << *(--i);
    return 0;
}