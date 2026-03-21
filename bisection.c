//Bisection method for x cube - 4 x - 9 = 0
#include <stdio.h>
#include <math.h>
#define e 0.01
double f(double x) {
    return x * x * x - 4 * x - 9;
}
int main() {
    double a, b, c;
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return 1;
    }
    while ((b - a) >= e) { 
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("The root is: %.4lf\n", c);
    return 0;
}