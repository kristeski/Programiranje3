#include <bits/stdc++.h>
using namespace std;

int n, sol = 0;
vector<bool> col, ldiag, rdiag;
vector<pair<int, int>> kr;

bool valid(int i, int j) {
	return (i < j) ? !ldiag[2 * n - 1 + i - j] && !rdiag[i + j] && !col[j] : !rdiag[i + j] && !ldiag[i - j] && !col[j];
}
void solve(int layer = 0, int rem = n) {
	if (!rem) {
		sol++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!valid(layer, i)) continue;
		kr.push_back({ layer, i });
		(layer < i) ? (ldiag[2 * n - 1 + layer - i] = 1, rdiag[i + layer] = 1, col[i] = 1) : (rdiag[layer + i] = 1, ldiag[layer - i] = 1, col[i] = 1);
		solve(layer + 1, rem - 1);
		kr.pop_back();
		(layer < i) ? (ldiag[2 * n - 1 + layer - i] = 0, rdiag[i + layer] = 0, col[i] = 0) : (rdiag[layer + i] = 0, ldiag[layer - i] = 0, col[i] = 0);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	col.resize(n, false); ldiag.resize(2 * n - 1, false); rdiag.resize(2 * n - 1, false);
	solve();
	cout << sol;
}