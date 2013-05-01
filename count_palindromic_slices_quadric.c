int solution ( char *s ) {
    if (!s)
        return 0;
    int n = 0;    
    char *p = s;
    while (*p++)
        ++n;
    if (n < 2)
        return 0;
    int i, j, k;
    int r = (s[0] == s[1]);
    for (k = 1; k < n-1; ++k) {
        for (i = k-1, j = k+1; i>=0 && j<n; --i, ++j) {
            if (s[i] == s[j])
                ++r;
            else
                break;
        }
        if (r > 100000000)
            return -1;
        for (i = k, j = k+1; i>=0 && j<n; --i, ++j) {
            if (s[i] == s[j])
                ++r;
            else
                break;
        }
        if (r > 100000000)
            return -1;
    }
    return r;
}
