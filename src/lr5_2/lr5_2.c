#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    double (*cosx_dx)(double, double);
    double (*pi)(int);
    //lib = dlopen("/home/artyom/OS/lib.so", RTLD_LAZY);
    void* lib1 = dlopen("lib1.so", RTLD_LAZY);
    if (!lib1) {
        fprintf(stderr, "Cannot open library lib.so\n");
        return -2;
    }
    void* lib2 = dlopen("lib2.so", RTLD_LAZY);
    if (!lib2) {
        fprintf(stderr, "Cannot open library lib.so\n");
        return -2;
    }
    cosx_dx = dlsym(lib1, "dcosx");
    pi = dlsym(lib1, "pi");
    int cmd;
    bool first_realise = false;
    printf("Change lib - 0\n");
    printf("cos'x - 1 (float)arg1 (float)arg2\n");
    printf("pi - 2 (int)arg1\n");
    printf("Enter number the command and args: ");
    while (scanf("%d", &cmd) == 1) {
        if (cmd == 0) {
            if (first_realise) {
                cosx_dx = dlsym(lib1, "dcosx");
                pi = dlsym(lib1, "pi");
            } 
            else {
                cosx_dx = dlsym(lib2, "dcosx");
                pi = dlsym(lib2, "pi");
            }
            first_realise = !first_realise;
            if (cosx_dx == NULL || pi == NULL) {
                fprintf(stderr, "Cannot find functions\n");
                exit(2);
            }
        }
        else if (cmd == 1) {
            double A, dx;
            if (scanf("%lf%lf", &A, &dx) != 2) {
                fprintf(stderr, "Function cosx_dx error input\n");
                exit(1);
            }
            printf("cos'x: %lf\n", cosx_dx(A, dx));
        }
        else if (cmd == 2) {
                int n;
                if (scanf("%d", &n) != 1) {
                    fprintf(stderr, "Function pi error input\n");
                    exit(1);
                }
                printf("pi: %lf\n", pi(n));
        }
        else {
            fprintf(stderr, "Undefined command\n");
        }
        printf("Enter number the command and args: ");
    }
    dlclose(lib1);
    dlclose(lib2);
    return 0;
}

