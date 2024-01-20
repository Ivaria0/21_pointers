#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int check(int *a, int n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

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

void output(int *a, int n) {
    if (check(a, n) == 1) {
        int *p;
        p = a;
        for (int i = 0; i < n; i++)
            printf("%d ", *p++);
        printf("\b\n");
    } else {
        printf("n/a");
    }
}

int max(int *a, int n) {
    if (n > 0) {
        int max = *a;
        int t;
        int *p;
        p = a;
        for (int i = 0; i < n; i++) {
            t = *p++;
            if (max < t)
                max = t;
        }
        return max;
    } else {
        return 0;
    }
}

int min(int *a, int n) {
    if (n > 0) {
        int min = *a;
        int t;
        int *p;
        p = a;
        for (int i = 0; i < n; i++) {
            t = *p++;
            if (min > t)
                min = t;
        }
        return min;
    } else {
        return 0;
    }
}

double mean(int *a, int n) {
    if (check(a, n) == 1)
        return (max(a, n) + min(a, n)) / 2.;
    else
        return 0;
}

double variance(int *a, int n) {
    if (check(a, n) == 1)
        return ((n * n - 1) / 12.);
    else
        return -1;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    if (variance_v > 0)
        printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

int check(int *a, int n) {
    if (n <= 0)
        return 0;
    if (max(a, n) - min(a, n) >= n)
        return 0;
    int *b, *c;
    b = c = a;
    for (int i = 0; i < n; i++) {
        for (int j = *b; j < n; j++) {
            if ((i != j) && (a[i] == b[j]))
                return 0;
        }
        b = c;
    }
    return 1;
}
