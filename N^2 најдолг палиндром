#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	string a;
	cin >> a;
	vector<int> fq(52, 0);
	for (int i = 0; i < a.size(); i++)
		(isupper(a[i])) ? fq[a[i] - 'A' + 26]++ : fq[a[i] - 'a']++;
	vector<vector<bool>> dp(a.size(), vector<bool>(a.size(), 0));
	for (int i = 0; i < a.size(); i++) dp[i][i] = 1;
	for (int j = 0; j < a.size(); j++) {
		for (int i = 0; i + j + 1 < a.size(); i++) {
			cout << i << " " << i + j + 1 << endl;
			if (i == i + j) dp[i][i + j + 1] = a[i] == a[i + j + 1];
			else dp[i][i + j + 1] = dp[i + 1][i + j] && a[i] == a[i + j + 1];
		}
	}
	for (auto i : dp) {
		for (bool b : i) cout << b << " ";
		cout << endl;
	}
}
