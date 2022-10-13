#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int timer =  0;
vector<pair<int, int>> bridges;
vector<int> time, low;

void dfs(vector<vector<int>>& adj, int u, int p) {
	low[u] = time[u] = timer++;
	for(int v : adj[u]) {
		if(v == p) continue;
		if(!time[v]) {
		dfs(adj, v, u);
		if(time[u] < low[v])
			bridges.push_back({u,v});
		low[u] = min(low[u], low[v]);
		}
		else
		low[u] = min(low[u], time[v]);

	}
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
vector<vector<int>> adj(n);
	time.resize(n);
	low.resize(n);
	for(auto edge : connections) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	
	dfs(adj, 0, -1);
	return bridges;
}

int main() {

	return 0;
}