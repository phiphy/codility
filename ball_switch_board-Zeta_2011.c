int solution ( int **A, int N, int M, int K ) {
    int *down = (int *)malloc(sizeof(int) * M);
    int *right = (int *)malloc(sizeof(int) * M);
    memset(down, 0, sizeof(int) * M);
    memset(right, 0, sizeof(int) * M);
    down[0] = K;
    int i, j;
    int balls_right, balls_all;
    for (i = 0; i < N; ++i) {
        balls_right = 0;
        for (j = 0; j < M; ++j) {
            if (A[i][j] == 0) {
                right[j] = balls_right;
            } else {
                balls_all = down[j] + balls_right;
                if (A[i][j] == 1) {
                    down[j] = balls_all / 2;
                    right[j] = balls_all - down[j];
                } else {
                    right[j] = balls_all / 2;
                    down[j] = balls_all - right[j];
                }
                balls_right = right[j];
            }
        }
    }
    i = down[M-1];
    free(down);
    free(right);
    return i;
}
