//c code for lagrage interpolation for x and y values 
#include <stdio.h>

int main() {
    float x[] = {5, 6, 9, 11};
    float y[] = {12, 13, 14, 16};
    float x_point = 10;
    float result = 0;
    
    int n = 4;
    
    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (x_point - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    
    printf("y(%.1f) = %.4f\n", x_point, result);
    return 0;
}

