#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n, ctr = 0;
vector<vector<pair<int, int>>> sol;
bool valid(vector<pair<int, int>> &krals) {
    for (int i = 0; i < krals.size(); i++) {
        for (int j = i + 1; j < krals.size(); j++) {
            if (krals[i].f == krals[j].f || krals[i].s == krals[j].s || krals[i].f + krals[i].s == krals[j].f + krals[j].s ||
                krals[i].f - krals[i].s == krals[j].f - krals[j].s) return false;
        }
    }
    return true;
}
void rec(pair<int, int> p, int rem, vector<pair<int, int>> krals = {}) {
    krals.push_back(p);
    if (!rem) {
        if (valid(krals)) {
            ctr++;
            sol.push_back(krals);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(((i != p.f) ^ (j != p.s)) || (i != p.f && j != p.s))) continue;
            rec({ i, j }, rem - 1, krals);
        }
    }
}
int main()
{
    cin >> n;
    vector<pair<int, int>> kral(n, {0, 0});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rec({ i, j }, n - 1);
        }
    }
    cout << ctr << endl;
    for (auto i : sol) {
        for (auto j : i) cout << j.f << " " << j.s << ", ";
        cout << '\n';
    }
    /*system("pause");
    vector<int> v;
    v.resize(n * n, 0); 
    for (int i = n * n - n; i < n * n; i++) v[i] = 1;
    do  {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << v[i * n + j];
            }
            cout << endl;
        }
        cout << endl;
    } while ((next_permutation(v.begin(), v.end()))); */
}
