#include <math.h>
#include "libs.h"

double dcosx(double A, double dx) {
    return (cos(A + dx) - cos(A)) / dx;
}

double pi(int n) {
    double mpi = 0;
    double zn = 1.0;
    for (int i = 0; i < n; zn += 2.0, i++) {
        if (i % 2) {
            mpi -= 1.0 / zn;
        } 
        else {
            mpi += 1.0 / zn;
        }
    }
    return mpi * 4.0;
}
