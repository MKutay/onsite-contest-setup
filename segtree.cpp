template<typename T, typename F = function<T(const T&, const T&)>> class segtree {
  public:
		int N;
		T neutral;
		vector<T> tree;
		F f;
		segtree() {}
		segtree(int n, vector<T> &A, T _neutral, F _f) : neutral(_neutral), f(_f) {
			N = 1;
			while (N < n) N *= 2;
			tree.resize(2 * N);
			build(A, 0, 0, N);
		}
		void build(vector<T> &A, int x, int lx, int rx) {
			if (rx - lx == 1) {
				if (lx < (int) A.size()) tree[x] = A[lx];
				return;
			}
			int m = (lx + rx) / 2;
			build(A, 2 * x + 1, lx, m);
			build(A, 2 * x + 2, m, rx);
			tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
		}
		void update(int i, int v, int x, int lx, int rx) {
			if (rx - lx == 1) {
				tree[x] = v;
				return;
			}
			int m = (lx + rx) / 2;
			if (i < m) update(i, v, 2 * x + 1, lx, m);
			else update(i, v, 2 * x + 2, m, rx);
			tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
		}
		void update(int i, int v) { update(i, v, 0, 0, N); }
		T query(int l, int r, int x, int lx, int rx) {
			if (lx >= r || rx <= l) return neutral;
			if (rx <= r && lx >= l) return tree[x];
			int m = (lx + rx) / 2;
			T L = query(l, r, 2 * x + 1, lx, m);
			T R = query(l, r, 2 * x + 2, m, rx);
			return f(L, R);
		}
		T query(int l, int r) { return query(l, r, 0, 0, N); }
};
