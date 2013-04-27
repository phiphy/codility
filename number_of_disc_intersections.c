/*
 * number_of_disc_intersections
 * https://codility.com/demo/take-sample-test/beta2010/
 *
 */
int find(long long *b, int l, int r, long long x)
{
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (b[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;    
}

int number_of_disc_intersections(int *A, int N)
{
    if (N <= 1)
        return 0;
    int i, j, k, r = 0;
    long long *b = (long long *)malloc(sizeof(long long) * 10000000);
    b[0] = A[0];
    for (i = 1; i < N; ++i) {
        j = find(b, 0, i-1, (long long)i - A[i]);
        r += (i - j);
        if (r > 10000000)
            return -1;
        j = find(b, 0, i-1, (long long)i + A[i]);
        for (k = i; k > j; --k)
            b[k] = b[k-1];
        b[j] = (long long)i + A[i];
    }
    return r;
}
