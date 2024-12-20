#include <bits/stdc++.h>
using namespace std;

int t;
string s;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> s;
		int len = s.size();
		cout << 1 << " " << len << " ";
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '0')
			{
				int pos = -1, ansl = 1, ansr = 1;
				int len1 = len - i;
				for (int j = 0; j < len - len1; j++)
				{
					string str = s.substr(j, len1);
					for (int k = 0; k < len1; k++)
					{
						if (str[k] == s[i + k])
						{
							if (pos < k)
							{
								pos = k;
								ansl = j + 1, ansr = j + len1;
							}
							break;
						}
						else if (k == len1 - 1)
						{
							pos = k;
							ansl = j + 1, ansr = j + len1;
						}
					}
				}
				cout << ansl << " " << ansr << "\n";
				break;
			}
			else if (i == len - 1)
			{
				cout << 1 << " " << 1 << "\n";
			}
		}
	}
	return 0;
}
