class Solution {
public:
    vector<int> parent, r;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if (r[a] < r[b])
            swap(a, b);

        parent[b] = a;

        if (r[a] == r[b])
            r[a]++;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n+1);
        r.assign(n+1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if (find(u) == find(v))
                return e;

            Union(u, v);
        }

        return {};
    }
};