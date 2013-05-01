int imin(int x, int y) { return x < y ? x : y; }
int solution ( char *t ) {
    if (!t)
        return 0;
    int n = strlen(t);
    if (n < 2)
        return 0;
    int i, j, k, r = 0;
    int m = n + n + 3;
    char *s = (char *)malloc(sizeof(char) * m);
    int *p = (int *)malloc(sizeof(int) * m);
    for (s[0] = '$', s[1] = '#', i = 0, j = 2; i < n; ++i) {
        s[j++] = t[i];
        s[j++] = '#';
    }
    s[j] = '\0';
    for (k = 0, i = 1; i < m-1; ++i) {
        p[i] = k > i ? imin(p[2*j-i], k-i) : 1;
        while (s[i+p[i]] == s[i-p[i]])
            ++p[i];
        if (p[i] > 1) {
            r += (p[i]/2 - (s[i]!='#'));
            if (r > 100000000) {
                r = -1;
                break;
            }
        }
        if (p[i]+i > k) {
            k = p[i] + i;
            j = i;
        }
    }
    free(s); s = NULL;
    free(p); p = NULL;
    return r;
}
