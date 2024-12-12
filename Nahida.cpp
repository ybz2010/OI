#include<bits/extc++.h>
using namespace std;
struct node{
    int val;
    node *nxt;
}*head;
void push(int x)
{
    auto tmp = new node;
    tmp->val = x;
    tmp->nxt = head;
    head = tmp;
}
signed main()
{
    for (int i = 1; i <= 10; i++)
        push(i);
    for (auto i = head; i; i = i->nxt)
        cout << i->val << endl;
    return 0;
}