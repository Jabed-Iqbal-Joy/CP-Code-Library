#include <bites/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
int n, m, s; //n->node,m->edge,s->source

struct Edge {
	ll u, v, cost;
};

void solve()
{
	cin >> n >> m;
	Edge edge[m + 5];
	for (int i = 0; i < m; ++i)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].cost;
	}
	vector<ll> dis(n, INF);
	vector<int> par(n, -1);
	cin >> s;
	dis[s] = 0;
	bool update = true;
	for (int i = 0; i < n; ++i)
	{
		update = true;
		for (int j = 0; j < m ; ++j)
		{
			if (dis[edge[j].u] != INF && dis[edge[j].u] + edge[j].cost < dis[edge[j].v])
			{
				dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;
				par[edge[j].v] = edge[j].u;
				update = false;
			}
		}
		if (update) break;
	}
	for (int j = 0; j < m && !update; ++j)
	{
		if (dis[edge[j].u] != INF && dis[edge[j].u] + edge[j].cost < dis[edge[j].v])
		{
			cout << "Negetive edge Cycle found\n";
			return;
		}
	}

	cout << "Min cost:\n";
	for (int i = 0; i < n; ++i)
	{
		cout << dis[i] << ' ';
	}
	cout << endl;

}

int main()
{
	solve();
	return 0;
}