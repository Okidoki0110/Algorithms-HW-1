#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;

int findMaxDiff(vector<int> &v, int K) {
    int n = v.size(), i, j, cost;
    // dp[i][j] = diferenta maxima obtinuta din primele i numere sortate descrescator
    //            selectand exact j din ele.
    vector<vector<int>> dp(n + 1, vector<int>(n - K + 1, 0));

    // sortez descrescator 
    sort(v.begin(), v.end(), [](const int &a, const int &b) {
        return a > b;
    });

    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n - K; ++j) {
            cost = v[i - 1];
            // daca j e par inseamna ca adversarul alege => scadem costul
            if (j % 2 == 0) cost = -cost;
            dp[i][j] = INT_MIN;
            if (i - 1 >= j) {
                // daca putem selecta j din primele i - 1, consideram ca e o solutie viabila
                dp[i][j] = dp[i - 1][j];
            }
            // sau alegem valoarea v[i]
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + cost);
        }
    }

    return dp[n][n - K];
}



// solutie brute force pentru a verifica daca da corect
int computeDiff(vector<int> &v) {
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i % 2) {
            sum -= v[i];
        } else {
            sum += v[i];
        }
    }
    return sum;
}
int brut(vector<int> &v, int K) {
    int i, n = v.size(), maxDiff = INT_MIN;
    
    vector<int> a(n, 0);
    for (i = 0; i < n - K; ++i)
        a[i] = 1;
    reverse(a.begin(), a.end());
    vector<int> selected;
    selected.reserve(n);
    do {
        selected.clear();
        for (i = 0; i < n; ++i)
            if (a[i]) {
                selected.push_back(v[i]);
            }
        int diff = computeDiff(selected);
        maxDiff = max(maxDiff, diff);
    } while (next_permutation(a.begin(), a.end()));
    
    return maxDiff;
}

int main() { 
    freopen("p2.in", "r", stdin); 
    freopen("p2.out", "w", stdout);
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    cout << findMaxDiff(v, K) << "\n";
    
    //cout << brut(v, K) << "\n";
}
