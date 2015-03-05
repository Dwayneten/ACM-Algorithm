/*///////////////////////////////////////////////////////
    Author        :Dwayne
    Created Time  :2015/2/28 20:59:27
    File Name     :CF519A.cpp
///////////////////////////////////////////////////////*/

#include <cstdio>
#include <cstring>
#include <map>
#include <cctype>
using namespace std;

int n, m, k, tn, tcase = 0;

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
	char s[16][16];
	for (int i=0; i<8; ++i)
		gets(s[i]);
	map<char, int> mp;
	mp['Q'] = mp['q'] = 9;
	mp['R'] = mp['r'] = 5;
	mp['B'] = mp['b'] = 3;
	mp['N'] = mp['n'] = 3;
	mp['P'] = mp['p'] = 1;
	int cnta = 0, cntb = 0;
	for (int i=0; i<8; ++i)
		for (int j=0; j<8; ++j)
			if (isalpha(s[i][j]))
				if (isupper(s[i][j]))
					cnta += mp[s[i][j]];
				else
					cntb += mp[s[i][j]];
	if (cnta == cntb)
		puts("Draw");
	else
		puts(cnta > cntb ? "White" : "Black");

    return 0;
}
