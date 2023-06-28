#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<pair<ll, ll>> G[n + 5];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<ll> dist(n + 5, 99999999);
    vector<ll> path(n + 5, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    que.push({0, 1});
    dist[1] = 0;
    while (!que.empty())
    {
        ll cur_node = que.top().second;
        ll cur_cost = que.top().first;
        que.pop();
        /// cout<<cur_node<<"==>>"<<cur_cost<<endl;
        for (int i = 0; i < G[cur_node].size(); i++)
        {
            ll dist_node = G[cur_node][i].first;
            ll dist_cost = G[cur_node][i].second;
            if (cur_cost + dist_cost < dist[dist_node])
            {
                dist[dist_node] = cur_cost + dist_cost;
                que.push({dist[dist_node], dist_node});
                path[dist_node] = cur_node;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    int r;
    cout << endl
         << "Enter destination : ";
    cin >> r;
    vector<ll> ans;
    ans.push_back(r);
    while (path[r] != -1)
    {
        ans.push_back(path[r]);
        r = path[r];
    }
    reverse(ans.begin(), ans.end());

    for (auto it : ans)
    {
        cout << it << "--->";
    }
    cout << dist[ans[ans.size() - 1]] << endl;
}