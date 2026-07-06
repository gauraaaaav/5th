// Lab 10: Kruskal's and Prim's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Edge {
    char u, v;
    int w;
};

void border() {
    cout << "+--------+--------+--------+\n";
}

void row(char u, char v, int w) {
    cout << "| "
         << setw(6) << u
         << " | "
         << setw(6) << v
         << " | "
         << setw(6) << w
         << " |\n";
}

// ---------- KRUSKAL ----------

struct DSU {

    vector<int> p;

    DSU(int n) {
        p.resize(n);

        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int x) {
        if (p[x] == x)
            return x;

        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {

        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        p[b] = a;

        return true;
    }
};

void kruskal(vector<Edge> edges, int n) {

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    DSU dsu(n);

    int cost = 0;

    cout << "\nKRUSKAL\n\n";

    border();
    cout << "| Edge1  | Edge2  | Weight |\n";
    border();

    for (auto e : edges) {

        if (dsu.unite(e.u - 'A', e.v - 'A')) {

            row(e.u, e.v, e.w);

            cost += e.w;
        }
    }

    border();

    cout << "\nMinimum Cost = "
         << cost
         << "\n";
}

// ---------- PRIMS ----------

void prim(vector<vector<int>> &g, int n) {

    vector<bool> vis(n);

    vis[0] = true;

    int cost = 0;

    cout << "\nPRIMS\n\n";

    border();

    cout << "| Edge1  | Edge2  | Weight |\n";

    border();

    for (int e = 0; e < n - 1; e++) {

        int mn = 9999;

        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {

            if (vis[i]) {

                for (int j = 0; j < n; j++) {

                    if (
                        !vis[j] &&
                        g[i][j] &&
                        g[i][j] < mn
                    ) {
                        mn = g[i][j];

                        x = i;
                        y = j;
                    }
                }
            }
        }

        row('A' + x, 'A' + y, mn);

        cost += mn;

        vis[y] = true;
    }

    border();

    cout << "\nMinimum Cost = "
         << cost
         << "\n";
}

// ---------- MAIN ----------

int main() {

    int n, m;

    cout << "Enter no. of vertices & edges : ";
    cin >> n >> m;

    vector<Edge> edges;

    vector<vector<int>>
    graph(
        n,
        vector<int>(n, 0)
    );

    cout << "Enter edges (u v w):\n";

    for (int i = 0; i < m; i++) {

        char u, v;
        int w;

        cin >> u >> v >> w;

        edges.push_back({
            u,
            v,
            w
        });

        graph[u - 'A'][v - 'A'] = w;
        graph[v - 'A'][u - 'A'] = w;
    }

    kruskal(edges, n);

    cout << "\n-----------------\n";

    prim(graph, n);

    return 0;
}