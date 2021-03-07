  vector<array<int, 2>> pos(N);
  vector<int> tour, d(N);
  function<void(int, int)> dfs = [&](int v, int parent) {
    pos[v][0] = pos[v][1] = tour.size();
    tour.emplace_back(v);
    for (auto node : g[v]) {
      if (node == parent) continue;
      d[node] = d[v] + 1;
      dfs(node, v);
      pos[v][1] = tour.size();
      tour.emplace_back(v);
    }
  };
  dfs(0, -1);
  sparseTable<int> st(tour, [&](int x, int y) {
    return (d[x] < d[y] ? x : y);
  });
  auto query = [&](int x, int y) {
    if (pos[x][0] > pos[y][0]) swap(x, y);
    if (pos[x][1] >= pos[y][1]) return x;
    return st.query(pos[x][1], pos[y][0]);
  };
