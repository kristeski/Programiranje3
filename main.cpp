#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
bool vis[N];
int n, m, mst = 0;
vector<pair<int, int>> adj[N];


int main() {
    cin >> n >> m;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if(vis[v])
            continue;
        vis[v] = true;
        mst += w;
        for(auto &p : adj[v])
            pq.push(p);
    }
    cout << mst;
}
