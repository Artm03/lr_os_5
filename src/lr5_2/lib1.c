#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

double dcosx(double A, double dx) {
    printf("This is second realise of cos'x\n");
    return (cos(A + dx) - cos(A - dx)) / (2.0 * dx);
}

double pi(int n) {
    printf("This is vallis realise of pi\n");
    double mpi = 1.0;
    for (int i = 1; i <= n; i++) {
        mpi *= (4.0 * (double)i * (double)i) / (4.0 * (double)i * (double)i - 1.0);
    }
    return mpi * 2.0;
}
