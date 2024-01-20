#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int check(int *a, int n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    output(data, n);
    return 0;
}

int input(int *a, int *n) {
    float v;
    *n = 0;
    int b = scanf("%f", &v);
    if (((int)v == v) && (b == 1) && (v <= NMAX) && (v > 0)) {
        *n = v;
        int *p;
        p = a;
        for (int i = 0; i < *n; i++) {
            b = scanf("%f", &v);
            if (((int)v == v) && (b == 1))
                *p++ = v;
            else
                *n = -1;
        }
    }
    return 0;
}

int check(int *a, int n) {
    if (n > 0) {
        int *p;
        p = a;
        int t;
        double m = mean(a, n);
        double tsigma = 3 * sqrt(variance(a, n));
        for (int i = 0; i < n; i++) {
            t = *p++;
            if ((t % 2 == 0) && (t >= m) && (t <= m + tsigma) && (t != 0))
                return t;
        }
        return 0;
    } else {
        return -1;
    }
}

void output(int *a, int n) {
    if (n > 0)
        printf("%d", check(a, n));
    else
        printf("n/a");
}

double mean(int *a, int n) {
    if (n > 0) {
        double t = 0;
        int *p;
        p = a;
        for (int i = 0; i < n; i++)
            t += *p++;
        t /= (double)n;
        return t;
    } else {
        return 0;
    }
}

double variance(int *a, int n) {
    if (n > 0) {
        double t;
        double var = 0;
        int *p;
        p = a;
        for (int i = 0; i < n; i++) {
            t = *p++;
            var += t * t;
        }
        var /= (double)n;
        double m = mean(a, n);
        var -= m * m;
        return var;
    } else {
        return 0;
    }
}
