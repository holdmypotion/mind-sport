constexpr int mxn = 1000;

enum Color { WHITE, GRAY, BLACK };

struct graph {
	int n, m, cycleNumber = 0;
	v32 adj[mxn], color, mark, p, cycles[mxn];
	graph() = default;
	graph(int n) : n(n) {
		color.resize(n, WHITE);
		mark.resize(n, 0);
		p.resize(n, 0);
	};
	graph(int n, int m) : n(n), m(m) {
		color.resize(n, WHITE);
		mark.resize(n, 0);
		p.resize(n, -1);
	};

	void addEdge(int a, int b) {
		adj[a].push_back(b);
	}

	void dfs(int u, int par) {
		if (color[u] == BLACK) return;
		if (color[u] == GRAY) {
			cycleNumber++;
			auto cur = par;
			mark[cur] = cycleNumber;
			while (cur != u) {
				cur = p[cur];
				mark[cur] = cycleNumber;
			}
			return;
		}
		p[u] = par;
		color[u] = GRAY;
		for (auto v : adj[u]) {
			if (v == p[u]) continue;

			dfs(v, u);
		}
		color[u] = BLACK;
	}

	void printCycles() {
		forn(i, n) {
			if (color[i] == WHITE) {
				p[i] = 0;
				dfs(i, 0);
			}
		}

		forn(i, n) {
			if (mark[i] != 0) cycles[mark[i]].pb(i);
		}

		for (int i = 1; i <= cycleNumber; i++) {
			for (auto& v : cycles[i]) cout << v << " ";
			cout << ln;
		}
	}
};