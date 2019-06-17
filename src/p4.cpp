#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MOD 1000000007

int dp[2][101][401];
// dp[i][j][k] = numarul de combinari de i luate cate j cu diferenta k
// tinem doar ultimele 2 linii pt a optimiza memoria
int count(int n, int K, int diff) {
    // comb(n, K) cu diferenta diff
    memset(dp, 0, sizeof(dp));
    const int MAXK = 2 * n;  // (n * n) / 4;
    int i, j, k, cost;
    int P = 0, Q = 1;
    dp[0][0][0+MAXK] = 1;
    for (i = 1; i <= n; ++i) {
        dp[Q][0][0+MAXK] = 1;
        for (j = 1; j <= min(i,K); ++j) {
            cost = n - i + 1;
            if (j % 2 == 0)
             cost = -cost;
            for (k = -MAXK +1; k < MAXK;++k) {
                dp[Q][j][k + MAXK] = 0;
                if (i - 1 >= j)
                    dp[Q][j][k + MAXK] += dp[P][j][k + MAXK],
                    dp[Q][j][k + MAXK] %= MOD;
                
                dp[Q][j][k + MAXK] += dp[P][j - 1][k - cost + MAXK];
                dp[Q][j][k + MAXK] %= MOD;
            }
        }
        P ^= 1;
        Q ^= 1;
    }
    
    long long result = dp[P][K][MAXK + diff] % MOD;
    //cerr << result << endl;
    // inmultim rezultatul cu K! pt ca putem avea oricare din cele K permutari
    for (long long p = 2; p <= K; ++p) {
        result *= p;
        result %= MOD;
    }
    return int(result);
}

// solutie brute force pentru a verifica daca da corect
int computeDiff(vector<int> &v) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
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

int brut(int n, int K, int D) {
    int i, nr = 0;

    vector<int> a(n, 0);
    for (i = 0; i < K; ++i)
        a[i] = 1;
    reverse(a.begin(), a.end());
    vector<int> selected;
    selected.reserve(n);
    do {
        selected.clear();
        for (i = 0; i < n; ++i)
            if (a[i]) {
                selected.push_back(i + 1);
            }
        int diff = computeDiff(selected);
        if (diff == D) {
            ++nr;
        }
    } while (next_permutation(a.begin(), a.end()));
    long long result = nr;
    for (long long p = 2; p <= K; ++p) {
        result *= p;
        result %= MOD;
    }
    return int(result);
}

int main() {
    FILE *f = freopen("p4.in", "r", stdin);
    FILE *g = freopen("p4.out", "w", stdout);
    int n, v, k;
    cin >> n >> k >> v;

    cout << count(v, n, k) << "\n";
    
}