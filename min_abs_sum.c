/*
 * Delta 2011
 * min_abs_sum
 * https://codility.com/demo/take-sample-test/delta2011/
*/

int imax(int x, int y) { return x > y ? x : y; }

int imin(int x, int y) { return x < y ? x : y; }

void free2a(int **a) { free(a[0]); free(a); }

int **new2a(int m, int n)
{
    int **a = (int **)malloc(sizeof(int *) * m);
    a[0] = (int *)malloc(sizeof(int) * m * n);
    int i, j;
    for (i = 1; i < m; ++i)
        a[i] = a[i-1] + n;
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            a[i][j] = 0;
    return a;
}

int solution (int A[], int N) {
    if (N == 0)
        return 0;
    if (N == 1)
        return abs(A[0]);
    int C[102] = {0}; C[101] = 1;
    int D[101] = {0};
    int i, j, k, b, m, sum = 0;
    for (i = 0; i < N; ++i) {
        j = abs(A[i]);
        if (j != 0) {
            ++C[j];
            sum += j;
        }
    }
    b = sum / 2;
    for (i = 1, m = 0; ; ++i) {
        while (C[i] == 0)
            ++i;
        if (i < 101) {
            C[m] = C[i];
            D[m++] = i;
        } else {
            break;
        }
    }

    int **dp = new2a(m, b+1);
    int **ud = new2a(m, b+1);
    for (j = D[0]; j <= b; ++j) {
        k = imin(j/D[0], C[0]);
        ud[0][j] = k;
        dp[0][j] = k * D[0];
    }
    for (i = 1; i < m; ++i) {
        for (j = 1; j <= b; ++j) {
            dp[i][j] = dp[i-1][j];
            k = j - D[i];
            if ((k >= 0) && (ud[i][k] < C[i]) && (dp[i][k] + D[i] > dp[i][j])) {
                dp[i][j] = dp[i][k] + D[i];
                ud[i][j] = ud[i][k] + 1;
            }
        }
    }
    for (i = 0, k = 0; i < m; ++i)
        k = imax(k, dp[i][b]);
    free2a(dp);
    free2a(ud);
    return sum - 2*k;
}

/* test cases:
4, 1, 1                 =>  2
1, 3                    =>  2
1, 1, 1, 3, 3, 3        =>  0
1, 1, 1, 7, 8, 9        =>  3
1, 2, 3, 4              =>  0
1, 2, 3, 4, 4, 4        =>  0
2, 3, 4, 5, 6, 8        =>  0
2, 3, 4, 5, 6, 7        =>  1
3, 0, 0, 0              =>  3
*/
