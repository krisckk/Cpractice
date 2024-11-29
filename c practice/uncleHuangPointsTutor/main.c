#include <stdio.h>

// Function to calculate (x^y) % m using fast power method
long long fast_power(long long x, long long y, long long m) {
    if(m == 1){
        return 0;
    }
    long long result = 1;
    x = x % m;
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % m;
        }
        y = y >> 1;
        x = (x * x) % m;
    }
    return result;
}

int main() {
    long long x, y, m;
    
    // Read input
    scanf("%lld %lld %lld", &x, &y, &m);
    
    // Calculate (x^y) % m using fast power method
    long long result = fast_power(x, y, m);
    
    // Print the result followed by a newline
    printf("%lld\n", result);
    
    return 0;
}