//numerical method for definite integral and even show each vayue of x and f(x) in the loop, TRAPEZOIDAL RULE
#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1/ (1 + (x * x)); // Example function: f(x) = 1/(1+x^2)
}

double definite_integral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        double fx = f(x);
        sum += fx;
        printf("x = %f, f(x) = %f\n", x, fx);
    }
    return sum * h;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 12;
    printf("Definite integral of f(x) = 1/(1+x^2) from %f to %f: %f\n", a, b, definite_integral(a, b, n));
    return 0;
}