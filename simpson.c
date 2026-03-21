//simpson 1/3rd rule for numerical integration
#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1/ (1 + (x * x)); 
}

double simpson_1_3(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Error.\n");
        return -1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }
    return sum * h / 3;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 6;
    printf("Simpson's 1/3 rule integral of f(x) = 1/(1+x^2) from %f to %f: %f\n", a, b, simpson_1_3(a, b, n));
    return 0;
} 