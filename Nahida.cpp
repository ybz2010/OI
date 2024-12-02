#include<bits/extc++.h>
using namespace std;
signed main()
{
	vector<int>a = {1,1,4,0,5,1,0,4};
	for (int i = 0; i < a.size();)
	{
		if (a[i] == 0)
			a.erase(a.begin() + i);
		else
			i ++;
	}
	for (auto i : a)
		cout << i << " ";
	return 0;
}