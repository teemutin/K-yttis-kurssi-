//Test
#include "header.h"
int main(int argc, char **argv){
    int i = 1;
    double number1;
    double number2;
    double result;

    number1 = atof(argv[1]);
    number2 = atof(argv[i+1]);
    result = calculator(number1,number2);

    printf("Result is %0.1f \n", result);
}