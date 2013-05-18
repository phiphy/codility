/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
*/

/*
    Epsilon 2011
    https://codility.com/demo/take-sample-test/epsilon2011/
*/

#define EPS 0.0000001
#define INF 10000000.0

typedef struct { double x, y; } Point;
typedef struct { int a, b; } Line;

int cmp0(double x) { return (fabs(x) < EPS) ? 0 : ((x > 0) ? 1 : -1); }

double f(Line *lines, int i, double x) { return lines[i].a * x + lines[i].b; }

void get_intersection(Line *lines, int i, int j, Point *p)
{
    p->x = (lines[j].b - lines[i].b + 0.0) / (lines[i].a - lines[j].a);
    p->y = f(lines, i, p->x);
}

int cmp_slope(const void *p, const void *q)
{
    const Line *u = (const Line *)p;
    const Line *v = (const Line *)q;
    return ((u->a < v->a) || (u->a==v->a && u->b>v->b)) ? -1 : 1;
}

int get_upper_lower(Line *lines, int b, int e, int inc, int *idx, Point *ps)
{
    ps[0].x = -INF;
    ps[0].y = f(lines, b, ps[0].x);
    idx[0] = b;
    int i, j, k = 0;
    for (j = b+inc; j != e; j += inc) {
        i = idx[k];
        if (lines[j].a != lines[i].a) {
            ++k;
            get_intersection(lines, i, j, ps+k);
            if (cmp0(ps[k].x - ps[k-1].x) == 0) {
                --k;
            } else {
                while (k>=2 && ps[k].x<ps[k-1].x) {
                    get_intersection(lines, idx[k-2], j, ps+k-1);
                    --k;
                }
            }
            idx[k] = j;
        }
    }
    ps[++k].x = INF;
    ps[k].y = f(lines, idx[k-1], ps[k].x);
    return k;
}

double solution(int a[], int b[], int n)
{
    int i, j, un, vn;
    Line *lines = (Line *)malloc(sizeof(Line) * n);
    for (i = 0; i < n; ++i) {
        lines[i].a = a[i];
        lines[i].b = b[i];
    }
    qsort(lines, n, sizeof(Line), cmp_slope);

    int *iu = (int *)malloc(sizeof(int) * (n+1));
    Point *pu = (Point *)malloc(sizeof(Point) * (n+1));
    un = get_upper_lower(lines, 0, n, 1, iu, pu);

    int *iv = (int *)malloc(sizeof(int) * (n+1));
    Point *pv = (Point *)malloc(sizeof(Point) * (n+1));
    vn = get_upper_lower(lines, n-1, -1, -1, iv, pv);

    if (un<=1 && vn<=1)
        return pu[0].y - pv[0].y;

    double r = INF, dy;
    for (i = 1, j = 1; i<un || j<vn;) {
        if (pu[i].x < pv[j].x) {
            dy = pu[i].y - f(lines, iv[j-1], pu[i].x);
            ++i;
        } else {
            dy = f(lines, iu[i-1], pv[j].x) - pv[j].y;
            ++j;
        }
        r = (dy < r) ? dy : r;
    }
    free(lines);
    free(iu); free(pu);
    free(iv); free(pv);
    return fabs(r);
}

/*
int main()
{
    int a[3] = {-1, 1, 0};
    int b[3] = {3, 0, 2};
    printf("%lf\n", solution(a, b, 3));
    return 0;
}
*/
