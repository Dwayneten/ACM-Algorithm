/*///////////////////////////////////////////////////////
    Author        :Dwayne
    Created Time  :2015/3/1 19:47:19
    File Name     :CF519D.cpp
///////////////////////////////////////////////////////*/

#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n, m, k, tn, tcase = 0;

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
	int value[32];
	for (int i=0; i<26; ++i)
		scanf("%d", &value[i]);
	char s[100024];
	getchar();
	gets(s);
	typedef long long LL;
	map<LL, int> cnt[32];
	LL sum[100024];
	sum[0] = value[0];
	int len = strlen(s);
	for (int i=1; i<len; ++i)
		sum[i] = sum[i-1] + value[s[i] - 'a'];
   	LL ans = 0;
	cnt[s[0] - 'a'][sum[0]]++;
	for (int i=1; i<len; ++i)
	{
		ans += cnt[s[i] - 'a'][sum[i-1]];
		cnt[s[i] - 'a'][sum[i]]++;
	}
	printf("%I64d\n", ans);

    return 0;
}
