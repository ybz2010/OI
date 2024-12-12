#include<bits/extc++.h>
using namespace std;
struct node
{
	int val;
	node *nxt;
};
node *head = NULL;
void push(int x)
{
	node *tmp = new node;
	tmp->val = x;
	tmp->nxt = head;
	head = tmp;
}
signed main()
{
	basic_string<int>v1 = {114514,1919810};
	v1 += 114;
	for (auto i : v1)
		cout << i;
	return 0;
}