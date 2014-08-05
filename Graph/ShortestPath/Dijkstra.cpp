#include <vector>

using namespace std;

struct Dijkstra
{
    static const int MAXN = 1001;
    static const int INF = 0x3f3f3f3f;

	int dis[MAXN], vis[MAXN];
    // record shortest path // 
    int path[MAXN];

    // adjacency matrix //
    // int w[MAXN][MAXN];

    // adjacency lists //
    struct node
    {
        int v, w;
        node (int v, int w) : v(v), w(w) {}
    };
    vector<node> edge[MAXN];

    void init(int sourse)
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, INF, sizeof(dis));
        dis[sourse] = 0;
        path[sourse] = sourse;
    }
    void add(int a, int b, int c)
    {
        // adjacency matrix //
		// !! cover parallel edge !! //
        // w[a][b] = c;
        // undirected graph //
        // w[b][a] = c;

        // adjacency lists //
		// !! allow parallel edge !! //
        edge[a].push_back(node(b, c));
        // undirected graph //
        edge[b].push_back(node(a, c));
    }
    void solve()
    {
        for (int i=0; i<n; ++i)
        {
            int index = -1, minn = INF;
            for (int j=0; j<n; ++j)
            {
                if (!vis[j] && dis[j]<minn)
                {
                    minn = dis[index = j];
                }
            }
            if (index == -1)
                break;
            vis[index] = 1;

            // adjacency matrix //
            // for (int j=0; j<n; ++j)
            // {
            //     if (!vis[j] && dis[index]+w[index][j] < dis[j])
            //     {
            //         dis[j] = dis[index]+w[index][j];
            //         path[j] = index;
            //     }
            // }

            // adjacency lists //
            int size = edge[index].size();
            for (int j=0; j<size; ++j)
            {
                int v = edge[index][j].v, w = edge[index][j].w;
                if (!vis[v] && dis[index]+w < dis[v])
                {
                    dis[v] = dis[index]+w;
                    path[v] = index;
                }
            }
        }
    }
    int query(int x)
    {
        return dis[x];
    }
    void find_path(int x)
    {
		// !! no fresh line after output whole path !! //
        if (x != path[x])
        {
            find_path(path[x]);
            // output format //
            printf(" ");
        }
        printf("%d", x);
    }
};