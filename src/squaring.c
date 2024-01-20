#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    float v;
    *n = 0;
    int b = scanf("%f", &v);
    if (((int)v == v) && (b == 1) && (v <= NMAX) && (v > 0)) {
        *n = v;
        for (int p = *a; p - *a < *n; p++) {
            b = scanf("%f", &v);
            if (((int)v == v) && (b == 1))
                *a++ = v;
            else
                *n = -1;
        }
    }
}

void output(int *a, int n) {
    if (n > 0) {
        for (int p = *a; p - *a < n; p++)
            printf("%d ", *a++);
        printf("\b");
    } else {
        printf("n/a");
    }
}

void squaring(int *a, int n) {
    if (n > 0) {
        for (int p = *a; p - *a < n; p++)
            *a++ = *a * *a;
    }
}
