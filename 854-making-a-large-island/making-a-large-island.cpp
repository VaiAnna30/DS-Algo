#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, sz;

    DisjointSet(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findUPar(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv) return;
        if (sz[pu] < sz[pv]) {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        } else {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
    }
};

class Solution {
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        DisjointSet ds(total);

        // use your “move” vector style
        vector<vector<int>> move = {
            {-1, 0},
            { 1, 0},
            { 0, 1},
            { 0,-1}
        };

        // 1) Union all adjacent 1’s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) continue;
                int id = r * n + c;
                for (auto &d : move) {
                    int nr = r + d[0], nc = c + d[1];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1)
                        ds.unionBySize(id, nr * n + nc);
                }
            }
        }

        bool hasZero = false;
        int ans = 0;

        // 2) Try flipping each 0 → compute combined area
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) continue;
                hasZero = true;
                set<int> comps;
                for (auto &d : move) {
                    int nr = r + d[0], nc = c + d[1];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1)
                        comps.insert(ds.findUPar(nr * n + nc));
                }
                int area = 1;
                for (int root : comps)
                    area += ds.sz[root];
                ans = max(ans, area);
            }
        }

        // 3) If there was no zero, entire grid is one big island
        if (!hasZero) return total;

        // 4) Also compare against any existing island without flip
        for (int i = 0; i < total; ++i) {
            int root = ds.findUPar(i);
            ans = max(ans, ds.sz[root]);
        }

        return ans;
    }
};
