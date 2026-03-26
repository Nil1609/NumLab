#include <stdio.h>
int main() {
    int n, i, j, k;
    float a[10][10], factor, sum;
    printf("Enter the number of variables: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix (including constants):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    for(i = 0; i < n-1; i++) {
        if(a[i][i] == 0.0) {
            printf("Mathematical Error! Division by zero.\n");
            return 0;
        }
        for(j = i+1; j < n; j++) {
            factor = a[j][i] / a[i][i];
            for(k = i; k <= n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }
    float x[10];
    for(i = n-1; i >= 0; i--) {
        sum = 0;
        for(j = i+1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }
    printf("Solution of the system:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i+1, x[i]);
    }
    return 0;
}