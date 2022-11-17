#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int n = 10;
ll graph[n][n], dist[n][n], par[n][n];

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = (i == j ? 0 : 2e9);
			par[i][j] = j;
		}
	}
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					par[i][j] = par[i][k];
				}
			}
		}
	}
	vector<int> path;
	int s, d; //s=source,d=destination
	cin >> s >> d;
	path.push_back(s);
	while (s != d)
	{
		s = par[s][d];
		path.push_back(d);
	}
	cout << "Path : ";
	for (auto it : path)
		cout << it << ' ';
	cout << endl;
}

int main()
{
	solve();
}