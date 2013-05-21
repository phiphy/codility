#include <vector>
#include <algorithm>
using namespace std;

int solution ( const vector<int> &D,const vector<int> &P,int T ) {
    int n = D.size();
    int i, j, k, l, x(0), r(0);
    long long ans(0);
    for (i = 0; i < n; ++i) // check this first
        if (D[i] > T)
            return -1;
    for (i = 0; i < n; ++i) {
        r = max(D[i] - x, 0);
        l = T - D[i];
        for (k = 0, j = i+1; j<n && k<l; ++j) {
            if (P[j] < P[i])
                break;
            k += D[j];
        }
        k = min(k, l);
        if (x < D[i]) {
            x = k;
            r += x;
        } else {
            if (k < x-D[i]) {
                x -= D[i];
            } else {
                r += (k + D[i] - x);
                x = k;
            }
        }
        ans += (long long)P[i] * (long long)r;
        if (ans > 1000000000)
            return -2;
    }
    return ans;
}
