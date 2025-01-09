#include<bits/extc++.h>
using namespace std;
int n,cur,x;
string s,op,in;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == "Move")
        {
            cin >> x;
            cur = x;
        }
        else if (op == "Insert")
        {
            cin >> x;
            char ch;
            in.clear();
            while (x)
            {
                ch = getchar();
                if (ch >= 32 && ch <= 126)
                {
                    x --;
                    in.push_back(ch);
                }
            }
            s.insert(cur,in);
        }
        else if (op == "Delete")
        {
            cin >> x;
            s.erase(cur,x);
        }
        else if (op == "Get")
        {
            cin >> x;
            cout << s.substr(cur,x) << endl;
        }
        else if (op == "Prev")
            cur --;
        else 
            cur ++;
    }
    return 0;
}