#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int timer = 0;
vector<pair<int, int>> bridges;
vector<int> time, low;

vector<bool> articulations;

void dfs(vector<vector<int>>& adj, int u, int p) {
	int children = 0;
	low[u] = time[u] = timer++;
	for (int v : adj[u]) {
		if (v == p)
			continue;
		if (!time[v]) {
			childen++;
			dfs(adj, v, u);
			if (time[u] <= low[v])
				articulations[u] = true;
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], time[v]);
	}
	if (u == p)
		articulations[u] = children > 1;
}

int main() {
	

	return 0;
}