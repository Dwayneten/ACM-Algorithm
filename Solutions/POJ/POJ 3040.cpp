/*///////////////////////////////////////////////////////
    Author        :Dwayne
    Created Time  :2015/2/23 19:30:03
    File Name     :POJ3040.cpp
///////////////////////////////////////////////////////*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, k, tn, tcase = 0;
struct coin
{
	int v, num;
	bool operator < (const coin& b) const
	{
		return (this->v < b.v || (!(b.v < this->v) && (this->num < b.num)));
	}
};
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d %d", &n, &m);
	coin c[24];
    for (int i=0; i<n; ++i)
	{
		scanf("%d %d", &c[i].v, &c[i].num);	
	}
	sort(c, c+n);
	/*
	for (int i=0; i<n; ++i)
		printf("%d %d\n", c[i].v, c[i].num);
	*/
	int ans = 0;
	for (int i=n-1; i+1; --i)
		if (c[i].v >= m)
			ans += c[i].num, c[i].num = 0;
		else
			break;
	int cur = 0;
	while (true)
	{
		cur = 0;
		for (int i=n-1; i+1; --i)
		{
			while (c[i].num && cur + c[i].v <= m)
				c[i].num--, cur += c[i].v;
		}
		for (int i=0; i<n; ++i)
		{
			while (c[i].num && cur < m)
				c[i].num--, cur += c[i].v;
		}
		if (cur >= m)
			ans++;
		else
			break;
	}
	printf("%d\n", ans);
    return 0;
}