/*///////////////////////////////////////////////////////
    Author        :Dwayne
    Created Time  :2015/2/28 21:11:21
    File Name     :CF519B.cpp
///////////////////////////////////////////////////////*/

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int n, m, k, tn, tcase = 0;

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
	scanf("%d", &n);
	int d[100024], e[100024], f[100024];
	for (int i=0; i<n; ++i)
		scanf("%d", &d[i]);
	for (int i=0; i<n-1; ++i)
		scanf("%d", &e[i]);
	for (int i=0; i<n-2; ++i)
		scanf("%d", &f[i]);
	sort(d, d+n);
	sort(e, e+n-1);
	sort(f, f+n-2);
	for (int i=0; i<n; ++i)
		if (d[i] != e[i])
			printf("%d\n", d[i]), i = n;
	for (int i=0; i<n-1; ++i)
		if (e[i] != f[i])
			printf("%d\n", e[i]), i = n;
    return 0;
}
