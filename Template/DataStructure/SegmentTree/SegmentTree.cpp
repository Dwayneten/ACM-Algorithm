struct SegmentTree 
{
    // !! the index of root is 1 !!//
    #define lson l, mid, root << 1
    #define rson mid+1, r, root << 1 | 1

    static const int MAXN = 2000;
    int node[MAXN << 2];

    // update value from bottom to top //
    void pushup(int root)
    {
        node[root] = max(node[root<<1], node[root<<1|1]);
    }
    // read input and build segment tree //
    void build(int l, int r, int root)
    {
        if (l == r)
        {
            scanf("%d", &node[root]);
            return ;
        }
        int mid = (l+r) >> 1;
        build(lson);
        build(rson);
        pushup(root);
    }
    // update node value //
    // x:node number w:new value //
    void update(int x, int w, int l, int r, int root)
    {
        if (l == r)
        {
            node[root] = w;
            return ;
        }
        int mid = (l+r) >> 1;
        if (x <= mid)
        {
            update(x, w, lson);
        }
        else
        {
            update(x, w, rson);
        }
        pushup(root);
    }
    // L&R:query segment l&r:search segment//
    int query(int L, int R, int l, int r, int root)
    {
        if (L <= l && r <= R)
        {
            return node[root];
        }
        int mid = (l+r) >> 1;
        int ret = 0;
        if (L <= mid)
            ret = max(ret, query(L, R, lson));
        if (R > mid)
            ret = max(ret, query(L, R, rson));
        return ret;
    }
};