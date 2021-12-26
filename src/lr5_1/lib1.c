#include <math.h>
#include "libs.h"

double dcosx(double A, double dx) {
    return (cos(A + dx) - cos(A - dx)) / (2.0 * dx);
}

double pi(int n) {
    double mpi = 1.0;
    for (int i = 1; i <= n; i++) {
        mpi *= (4.0 * (double)i * (double)i) / (4.0 * (double)i * (double)i - 1.0);
    }
    return mpi * 2.0;
}

