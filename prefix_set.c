/*
    Alpha 2010
    https://codility.com/demo/take-sample-test/alpha2010/
    prefix set
*/
int ps ( int A[], int N ) {
    int b[1000000] = {0};
    int i, k;
    for (i = 0, k = 0; i < N; ++i) {
        if (b[A[i]] == 0) {
            b[A[i]] = 1;
            ++k;
        }
    }
    for (i = 0; i < N; ++i) {
        if (b[A[i]] == 1) {
            b[A[i]] = 0;
            --k;
            if (k == 0)
                return i;
        }
    }
    return N-1;    
}
