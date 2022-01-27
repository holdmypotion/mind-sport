#include <bits/stdc++.h>
using namespace std;
#define int long long 

#define endl "\n"

int N, Q, LIMIT = 20;
vector<int> sum;
vector<int> arr;
vector<int> dist;
vector<int> depth;
vector<int> weight;
vector<vector<pair<int, int>>> tree;
vector<vector<int>> table;

void dfs(int src, int parent, int level = 1) {
	sum[src] = sum[parent] + arr[src]; // Sum of arr[i] from root to i.
	depth[src] = level;
	table[src][0] = parent;
	for (int i = 1; i <= LIMIT; i++) {
		if (table[src][i - 1] == -1)
			break;
		table[src][i] = table[table[src][i - 1]][i - 1];
	}
	for (auto child : tree[src]) {
		int idx = child.first, wt = child.second;
		if (idx == parent) continue;
		dist[idx] = dist[src] + wt;
		weight[idx] = weight[src] + (dist[idx] * arr[idx]); // sum of arr[i] * dist(root, i) from root to i.
		dfs(idx, src, level + 1);
	}
}

int getLCA(int x, int y) {
	if (depth[x] < depth[y]) {
		swap(x, y);
	}
	for (int j = LIMIT; j >= 0; j--) {
		if ((depth[x] - (1 << j)) >= depth[y]) {
			x = table[x][j];
		}
	}
	if (x == y) return x;
	for (int j = LIMIT; j >= 0; j--) {
		if (table[x][j] != table[y][j]) {
			x = table[x][j];
			y = table[y][j];
		}
	}
	return table[x][0];
}

void solve() {
	dfs(1, 0);
	while (Q--) {
		int x, y;
		cin >> x >> y;
		int lca = getLCA(x, y);
		int contribLCA = (dist[x] - dist[y]) * arr[lca];
		int ans1 = (sum[x] - sum[lca]) * (dist[x] - dist[y] + 2 * dist[lca]) - 2 * (weight[x] - weight[lca]);
		int ans2 = (sum[y] - sum[lca]) * (dist[x] - dist[y] - 2 * dist[lca]) + 2 * (weight[y] - weight[lca]);
		int ans = ans1 + ans2 + contribLCA;
		cout << ans << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T; cin >> T;
	while (T--) {
		cin >> N >> Q;
		tree.resize(N + 1);
		arr.assign(N + 1, 0LL);
		depth.assign(N + 1, 0LL);
		sum.assign(N + 1, 0LL);
		dist.assign(N + 1, 0LL);
		weight.assign(N + 1, 0LL);
		table.assign(N + 1, vector<int>(21, 0));

		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 1; i < N; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			tree[u].push_back({ v, w });
			tree[v].push_back({ u, w });
		}
		solve();
		tree.clear();
		table.clear();
	}
}