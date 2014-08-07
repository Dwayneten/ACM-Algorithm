#include <cstdio>
#include <cstring>
#define LL long long
#define repp(i, x, y) for(int (i)=(x); (i)<(y); (i)++)
LL a[100];
LL binarysearch(int l, int r, LL x)
{
    if (l == r)
        return a[l-1];
    int mid = (l+r)>>1;
    if (x<=a[mid])
        return binarysearch(l, mid, x);
    else
        return binarysearch(mid+1, r, x);
}
LL findlower(LL x)
{
    return binarysearch(2, 88, x);
}
int main()
{
    a[1] = 7;
    a[2] = 10;
    repp(i, 3, 88)
        a[i] = a[i-1] + a[i-2];
    char c[10] = "^T.T^__^";
    LL query;
    while(scanf("%lld", &query)!=EOF)
    {
        if (query>7)
        {
            while(query>7)
            {
                query -= findlower(query);
            }
        }
        putchar(c[query]);
        puts("");
    }
    // printf("%I64d\n",  0x7FFFFFFFFFFFFFFFLL);
    // 0x7FFFFFFFFFFFFFFFLL
    // 9223372036854775807
    // printf("%I64d\n", (1LL<<63)-1);
    return 0;
}