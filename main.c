/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
    printf("double型の最大値:%g\n", DBL_MAX);
    printf("double型の最小値:%g\n", DBL_MIN);
    printf("double型の精度:%d\n", DBL_DIG);
    printf("int型の最大値:%d\n", INT_MAX);
    printf("int型の最小値:%d\n", INT_MIN);
    printf("long型の最大値:%ld\n", LONG_MAX);
    printf("long型の最大値:%ld\n", LONG_MAX);
    printf("long double型の最大値:%Le\n", LDBL_MAX);
    printf("long double型の最小値:%Le\n", LDBL_MIN);
    printf("long double型の精度:%d\n", LDBL_DIG);
    

    return 0;
}