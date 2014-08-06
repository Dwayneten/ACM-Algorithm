struct Trie
{
    static const int MAXN = 1e6;
    static const int NONE = 0;
    static const int CHARSET = 26;
    static const int LETTER = 'a';

    int nodenum;
    int num[MAXN];
    int edge[MAXN][CHARSET];
    bool word[MAXN];

    void init()
    {
        nodenum = 1;
    }
    // add a string to trie //
    void add(int len, char *s)
    {
        int cur = 0;
        int index;
        for (int i=0; i<len; ++i)
        {
            index = s[i] - LETTER;
            if (edge[cur][index] == NONE)
            {
                edge[cur][index] = nodenum++;
            }
            cur = edge[cur][index];
            ++num[cur];
        }
        word[cur] = true;
    }
    // count the number of string s in trie //
    int count(int len, char *s)
    {
        int cur = 0;
        int index;
        for (int i=0; i<len; ++i)
        {
            index = s[i] - LETTER;
            if (edge[cur][index] == NONE)
            {
                return 0;
            }
            cur = edge[cur][index];
        }
        return num[cur];
    }
    // print the shortest prefix which can identify string s //
    void print(int len, char *s)
    {
        int cur = 0;
        int index;
        for (int i=0; i<len; ++i)
        {
            putchar(s[i]);
            index = s[i] - LETTER;
            cur = edge[cur][index];
            if (num[cur] == 1 || i == len - 1)
            {
                printf("\n");
                return ;
            }
        }
    }
};