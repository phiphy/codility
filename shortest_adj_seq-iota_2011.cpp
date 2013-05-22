/*
 * Codility - Iota 2011
 * https://codility.com/demo/take-sample-test/iota2011/
 */
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution ( const vector<int> &A ) {
    int n(A.size());
    if (A[0] == A[n-1]) return 1;
    int s(A[0]), t(A[n-1]);
    map<int, set<int> > g;
    map<int, int> b;
    g[s].insert(A[1]);
    int i, j;
    for (i = 1; i < n-1; ++i) {
        g[A[i]].insert(A[i-1]);
        g[A[i]].insert(A[i+1]);
        b[A[i]] = 0;
    }
    g[t].insert(A[n-2]);
    b[t] = 0;
    b[s] = 1;
    vector<int> c[2];   // candidates
    c[0].push_back(s);
    set<int>::iterator it;
    int k(0), dis(2);
    while (!b[t]) {
        if (c[k].empty()) {
            k = 1 - k;
            ++dis;
        }
        i = c[k].back(); c[k].pop_back();
        for (it = g[i].begin(); it != g[i].end(); ++it) {
            j = *it;
            if (!b[j]) {
                b[j] = 1;
                c[1-k].push_back(j);
            }
        }
    }
    return dis;
}
