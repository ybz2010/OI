#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i], y = b[i];
        int xy = x + y;
        int cost = 0;
        for (int j = 0; j <= xy; ++j) {
            for (int j1 = 0; j1 + j <= k; ++j1) {
                dp[i + 1][j1 + j] = min(dp[i + 1][j1 + j], dp[i][j1] + cost);
            }
            if (j < xy) {
                if (x >= y) {
                    x--, cost += y;
                } else {
                    y--, cost += x;
                }
            }
        }
    }
    cout << (dp[n][k] == 1e9 ? -1 : dp[n][k]) << '\n';
}
 
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}