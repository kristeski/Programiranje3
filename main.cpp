#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 1;
vector<int> dsu(N, -1);
vector<tuple<int, int, int>> edge;
int n, m, mst = 0;

int findp(int nd) {
    if(dsu[nd] >= 0)
        return dsu[nd] = findp(dsu[nd]);
    else
        return nd;
}
void uni(int a, int b) {
    if(dsu[a] > dsu[b])
        swap(a, b);
    dsu[a] += dsu[b];
    dsu[b] = a;
}
int main()
{
    cin >> n >> m;
    edge.reserve(m);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    for(auto e : edge)  {
        auto [w, u, v] = e;
        u = findp(u);
        v = findp(v);
        if(u == v)
            continue;
        else {
            mst += w;
            uni(u, v);
        }
    }
    cout << mst;
}
