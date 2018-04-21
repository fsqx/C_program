//#include <stdio.h>

//int add(int a, int b);
double add(double a,double b);

int main()
{
    double a = 3;
    double b = 5;

    double total;
    total = add(3.1,5.1);
    printf("%lf\n",total);

    return 0;
}

double add(double a,double b)
{
    double total = 0.0;

    total += a + b;

    return total;
}
