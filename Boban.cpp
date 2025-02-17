#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.resize(n);
	for (int& i : v) cin >> i;
	int l = 0, r = n - 1, maxi = 0;
	while (l < r) {
		maxi = max(maxi, min(v[l], v[r]) * (r - l));
		(v[l] < v[r]) ? l++ : r--;
	}
	cout << maxi;
}