#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libs.h"

int main() {
    int cmd;
    printf("cos'x - 1 (float)arg1 (float)arg2\n");
    printf("pi - 2 (int)arg1\n");
    printf("Enter number the command and args: ");
    while (scanf("%d", &cmd) == 1) {
        if (cmd == 1) {
            double A, dx;
            if (scanf("%lf%lf", &A, &dx) != 2) {
                fprintf(stderr, "Function cosx_dx error input\n");
                exit(1);
            }
            printf("cos'x: %lf\n", dcosx(A, dx));
        }
        else if (cmd == 2) {
            int n;
            if (scanf("%d", &n) != 1) {
                fprintf(stderr, "Function cosx_dx error input\n");
                exit(2);
            }
            printf("pi: %lf\n", pi(n));
        }
        else {
            fprintf(stderr, "Undefined command\n");
        }
        printf("Enter number the command and args: ");
    }
    return 0;
}