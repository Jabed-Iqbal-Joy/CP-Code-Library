#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bfs(int source, int sink, vector<int>&par, vector<vector<ll>>&rgraph)
{
	fill(par.begin(), par.end(), -1);
	int n = rgraph.size();
	par[source] = -2;
	queue<pair<int, int>> q;
	q.push({source, INT_MAX});

	while (!q.empty()) {
		int cur = q.front().first;
		ll cap = q.front().second;
		q.pop();
		for (int next = 0; next < n; next++) {
			if (cur != next && par[next] == -1 && rgraph[cur][next] != 0) {
				par[next] = cur;
				ll min_cap = min(cap, rgraph[cur][next]);
				if (next == sink)
					return min_cap;
				q.push({next, min_cap});
			}
		}
	}
	return 0;
}

ll fordFulkerson(vector<vector<ll>> & graph , int source, int sink)
{
	vector<int> par(graph.size(), -1);
	vector<vector<ll>> rgraph = graph; //Residual graph
	int min_cap = 0, max_flow = 0;
	while (min_cap = bfs(source, sink, par, rgraph))
	{
		max_flow += min_cap;
		int cur = sink;
		while (cur != source) {
			int prev = par[cur];
			rgraph[cur][prev] += min_cap;
			rgraph[prev][cur] -= min_cap;
			cur = prev;
		}

	}
	return max_flow;
}

void solve()
{
	int u, v, cost, n, m;
	cin >> n >> m; //m->edge,n->node
	vector<vector<ll>> graph(n, vector<ll>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> cost;
		graph[u - 1][v - 1] = cost;
	}
	int source, sink; //source & sink->destionation
	cin >> source >> sink;
	ll ans = fordFulkerson(graph, source - 1, sink - 1);
	cout << ans << endl;
}

int main()
{
	solve();
	return 0;
}