#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        long long k;
        cin >> n >> k;
        
        if (n <= 60 && (1ll << (n - 1)) < k) {
            cout << -1 << endl;
            continue;
        }
        k--;
        vector <int> d;
        while (k) {
            d.push_back(k % 2);
            k /= 2;
        }
        while (d.size() < n - 1) d.push_back(0);
        
        reverse(d.begin(),d.end());
        
        vector<int>a,b;
        for (int i = 0; i < n - 1; i++)
        {
            if (!d[i])
                a.push_back(i + 1);
            else
                b.push_back(i + 1);
        }

        reverse(b.begin(), b.end());
        for (int i : a) cout << i << ' ';
        cout << n << ' ';
        for (int i : b) cout << i << ' ';
        cout << endl;
    }
	
    return 0;
}