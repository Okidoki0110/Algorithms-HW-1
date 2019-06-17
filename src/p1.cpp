#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;

int findMaxDiff(vector<int> &v) {
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	long long s = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (i % 2 == 0) {
			s += v[i];
		} else {
			s -= v[i];
		}
	}
	return s;
}
int main() { 
    freopen("p1.in", "r", stdin); 
    freopen("p1.out", "w", stdout);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    cout << findMaxDiff(v) << "\n";
    
}
