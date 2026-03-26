#include <stdio.h>

// Function dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}

// Euler Method
double euler(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;

    while (x < x_target) {
        y = y + h * f(x, y);
        x = x + h;
    }

    return y;
}

int main() {
    double x0 = 0.0, y0 = 1.0, h = 0.05;
    double x_target = 0.3;

    double result = euler(x0, y0, h, x_target);

    printf("Euler Method: y(%.2f) = %.4f\n", x_target, result);

    return 0;
}