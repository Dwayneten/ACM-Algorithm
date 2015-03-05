/*///////////////////////////////////////////////////////
    Author        :Dwayne
    Created Time  :2015/2/28 21:22:58
    File Name     :CF519C.cpp
///////////////////////////////////////////////////////*/

#include <cstdio>
#include <cstring>

int n, m, k, tn, tcase = 0;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
	scanf("%d %d", &n, &m);
	int ans = 0, curn = n, curm = m, sum = n + m, typea = 0, typeb = 0;
	while (sum >= 3 && curn && curm)
	{
		if (curn >= 2 && curm >= 1)
			curn -= 2, curm -= 1, sum -= 3, ans++, typea++;
		if (curn >= 1 && curm >= 2)
			curn -= 1, curm -= 2, sum -= 3, ans++, typeb++;
	}
	while (typea && curm >= 3)
	{
		typeb += 2;
		typea--;
		ans++;
		curm -= 3;
	}
	while (typeb && curn >= 3)
	{
		typea += 2;
		typeb--;
		ans++;
		curn -= 3;
	}
	printf("%d\n", ans);

    return 0;
}
