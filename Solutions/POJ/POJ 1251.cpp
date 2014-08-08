#include <cstdio>
#include <cstring>
#include <cctype>
#define inf 0x3f3f3f3f
#define LETTER 'A'
int ans = 0;
int edge[27][27];
int vis[27];
int n, m;
void prim(int x)
{
    vis[x] = 1;
    for (int i=0; i<n-1; ++i)
    {
        int v = -1, minn = inf;
        for (int j=0; j<n; ++j)
        {
            if (!vis[j] && edge[x][j] < minn)
                minn = edge[x][v=j];
        }
        if (v == -1)
            break;
        vis[v] = 1;
        ans += edge[x][v];
        for (int j=0; j<n; ++j)
        {
            if  (!vis[j] && edge[v][j] < edge[x][j])
                edge[x][j] = edge[v][j];
        }
    }
}
int main()
{
    while (scanf("%d", &n), n)
    {
        memset(vis, 0, sizeof(vis));
        memset(edge, inf, sizeof(edge));
        char u, v;
        int w, index = -1;
        // int u, v;
        for (int i=0; i<n-1; ++i)
        {
            u = getchar();
            while (!isalpha(u))
                u = getchar();
            scanf("%d", &m);
            for (int j=0; j<m; ++j)
            {
                v = getchar();
                while (!isalpha(v))
                    v = getchar();
                scanf("%d", &w);
                if (index == -1 && w)
                    index = u - LETTER;
                edge[u-LETTER][v-LETTER] = w;
                edge[v-LETTER][u-LETTER] = w;
            }
        }
        ans = 0;
        prim(index);
        printf("%d\n", ans);
    }
}