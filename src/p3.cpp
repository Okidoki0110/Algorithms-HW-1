#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long computeMaxDiff(vector<int> &a) {
    int n = a.size();
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    int i, j;
    long long sum = 0;
/* pe diagonala principala se pun elementele din vector */     
    for (i = 0; i < n; ++i) {
        sum += a[i];
        dp[i][i] = a[i];
        if (i + 1 < n) {
            dp[i][i + 1] = max(a[i], a[i + 1]);
        }
    }
/* supradiagonala contine maximul dintre 2 elemente consecutive din vector */
    for (i = n - 1; i >= 0; --i) {
        for (j = i + 2; j < n; ++j) {
            dp[i][j] = max(
                min(dp[i + 1][j - 1], dp[i + 2][j]) + a[i],
                min(dp[i + 1][j - 1], dp[i][j - 2]) + a[j]
            );
            
        }
    }
    return dp[0][n - 1] - (sum - dp[0][n - 1]);
}

int main() {
    ifstream f("p3.in");

    int n;
    f >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        f >> a[i];
    }

    ofstream g("p3.out");
    g << computeMaxDiff(a) << "\n";
}