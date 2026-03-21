//False position method for xcube - 2x -5=0 even provide itteration table with porper fomratting and table alignment upto 3 decimal place
#include <stdio.h>
#include <math.h>
#define e 0.0001
double f(double x) {
    return x * x * x - 2 * x - 5;
}
int main() {
    double a, b, c;
    int iteration = 0;
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return 1;
    }
    printf("Iteration\t   a\t\t   b\t\t   c\t\t f(c)\n");
    printf("-------------------------------------------------------------------------\n");
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        printf("%9d\t%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", iteration++, a, b, c, f(c));
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    } while (fabs(f(c)) >= e);
    printf("The root is: %.4lf\n", c);
    return 0;
}
