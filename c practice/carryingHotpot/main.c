#include <stdio.h>
#include <math.h>

int main() {
  double x, y;
  int z;
  
  scanf("%lf %lf %d", &x, &y, &z);
  
  double result = x * y;
  
  if(z == 0) {
    result = round(result); 
  } else {
    double power = pow(10, z);
    result = round(result * power) / power;
  }
  
  printf("%.*lf\n", z, result);
  
  return 0;
}
