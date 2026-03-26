#include <stdio.h>

// Function dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}

// RK4 Method
double rk4(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;

    while (x < x_target) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
    }

    return y;
}

int main() {
    double x0 = 0.0, y0 = 1.0, h = 0.05;
    double x_target = 0.3;

    double result = rk4(x0, y0, h, x_target);

    printf("Runge-Kutta (RK4): y(%.2f) = %.4f\n", x_target, result);

    return 0;
}