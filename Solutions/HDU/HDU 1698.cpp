/*////////////////////////////////////////////////////

      There is nothing to do but work hard.

////////////////////////////////////////////////////*/
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
  
using namespace std;
#define LL long long
#define MOD 1000000007
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define INF 1e9
#define pb push_back
#define mp make_pair
#define mset(x) memset((x), 0, sizeof((x)))
#define MSET(x) memset((x), inf, sizeof((x)))
#define geti(x) scanf("%d", &(x))
#define getii(x, y) scanf("%d %d", &(x), &(y))
#define getiii(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define getd(x) scanf("%lf", &(x))
#define puti(x) printf("%d", (x))
#define putii(x, y) printf("%d %d", (x), (y))
#define rep(n) for(int i=0; i<n; i++)
#define repp(i, x, y) for(int (i)=(x); (i)<(y); (i)++)
#define lowbit(x) ((x)&-(x))
#ifdef OFFLINE
#else
#define assert(exp) 0
#endif // OFFLINE
//const int maxn = 4*int(1e3)+5;

int tn, tcase=0;
int n, m, k;
//int r, c;

#define lson l , mid , root << 1
#define rson mid + 1 , r , root << 1 | 1
const int maxn = 111111;
LL add[maxn<<2];
LL sum[maxn<<2];

void pushup(int root)
{
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void pushdown(int root, int num)
{
	if (add[root])
	{
		add[root << 1] = add[root];
		add[root << 1 | 1] = add[root];
		sum[root << 1] = add[root] * (num - (num >> 1));
		sum[root << 1 | 1] = add[root] * (num >> 1);
		add[root] = 0;
	}
}

void build(int l, int r, int root)
{
	add[root] = 0;
	if (l == r)
	{
		sum[root] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(root);
}

LL query(int L, int R, int l, int r, int root)
{
	if (L <= l && r <= R)
		return sum[root];
	pushdown(root, r - l + 1);
	int mid = (l + r) >> 1;
	LL ret = 0;
	if (L <= mid)
		ret += query(L, R, lson);
	if (R > mid)
		ret += query(L, R, rson);
	return ret;
}

void update(int L, int R, int c, int l, int r, int root)
{
	if (L <= l && r <= R)
	{
		add[root] = c;
		sum[root] = c * (r - l + 1);
		return ;
	}
	pushdown(root, r - l + 1);
	int mid  = (l + r) >> 1;
	if (L <= mid)
		update(L, R, c, lson);
	if (R > mid)
		update(L, R, c, rson);
	pushup(root);
}

int main()
{
#ifdef OFFLINE
    freopen("data.in", "r", stdin);
    //freopen(data.out", "w", stdout);
#endif // OFFLINE
    
	scanf("%d", &tn);
	while (tn--)
	{
		scanf("%d", &n);
		build(1, n, 1);
		scanf("%d", &m);
		int a, b, c;
		for (int i=0; i<m; ++i)
		{
			scanf("%d %d %d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", ++tcase, query(1, n, 1, n, 1));
	}

#ifdef OFFLINE
    double CostTime=(double)clock()/CLOCKS_PER_SEC;
    printf("\nCostTime:%.0fms\n", CostTime*1000);
#endif // OFFLINE
    return 0;
}
