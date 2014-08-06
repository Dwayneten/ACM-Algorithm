char pattern[10001];
char text[1000001];
int kmpnext[10001];

void prekmp (int lenp, char *p)
{
    int i, j;
    i = 0;
    j = kmpnext[0] = -1;
    while (i < lenp)
    {
        while (j >= 0 && p[i] != p[j])
            j = kmpnext[j];
        ++j;
        ++i;
        // Morris-Pratt Algorithm //
        // kmpnext[i] = j;
        // Knuth-Morris-Pratt Algorithm //
        if (p[i] == p[j])
            kmpnext[i] = kmpnext[j];
        else
            kmpnext[i] = j;
    }
}

void kmp (int lent, char *t, int lenp, char *p)
{
    prekmp(lenp, p);
    int i, j;
    i = j = 0;
    while (i < lent)
    {
        while (j >= 0 && t[i] != p[j])
            j = kmpnext[j];
        ++j;
        ++i;
        if (j >= lenp)
        {
            // matching success, any operation here //
			// ans++;
            j = kmpnext[j];
        }
    }
}