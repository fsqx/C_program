#include <stdio.h>

double calculate_pi(int num); //第一种公式计算pi
double calculate_pi_2(int num); //第二种公式计算pi
int main()
{

    printf("Pi = %0.10lf\n",calculate_pi(500)); // 5W次迭代
    printf("Pi = %0.10lf\n",calculate_pi(5000)); // 5W次迭代
    printf("Pi = %0.10lf\n",calculate_pi(50000)); // 5W次迭代   
    printf("Pi = %0.10lf\n",calculate_pi(500000)); // 50W次迭代
    printf("Pi = %0.10lf\n",calculate_pi(5000000)); // 500W次迭代
    printf("Pi = %0.10lf\n",calculate_pi(50000000)); // 5000W次迭代
    printf("Pi = %0.10lf\n",calculate_pi(500000000)); // 50000W次迭代
   

    /*超过int*/
    // printf("Pi = %0.10lf\n",calculate_pi(5000000000)); // 500000W次迭代
    // printf("Pi = %0.10lf\n",calculate_pi(50000000000)); // 5000000W次迭代
    printf("\n");
    printf("Pi = %0.10lf\n",calculate_pi_2(100));
    printf("Pi = %0.10lf\n",calculate_pi_2(1000));
    printf("Pi = %0.10lf\n",calculate_pi_2(10000));
    printf("Pi = %0.10lf\n",calculate_pi_2(100000));
}



double calculate_pi(int num)
{
    int n = 0;
    double pi = 0.0;
    for(; n < num; n++)
    {
        if(n % 2 == 0)
        {
            pi += 4.00/(2 *n +1.0);    
        }
        else
        {
            pi -= 4.00/(2 *n +1.0);
        }
    }
    //printf ("%lf\n",pi);
    return pi;

}

double calculate_pi_2(int num)
{
    int n = 0;
    int temp;
    double pi = 3.0;
    for(; n < num; n++)
    {
        temp=2 *(n + 1);
        if(n % 2 == 0)
        {
            pi += 4.0 /((temp)*(temp + 1)*(temp + 2));
        }
        else
        {
            pi -= 4.0 /((temp)*(temp + 1)*(temp + 2));
        }
    }
    return pi;

}
