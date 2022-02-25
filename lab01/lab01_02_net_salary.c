#include <stdio.h>

double get_net_salary(double, double, double, double);

int main(void)
{
    double base_salary;
    printf("Enter base salary: ");
    scanf("%lf", &base_salary);

    double da = 0.25f, hra = 0.15f, pf = 0.1f;
    // pf -> provident fund (base_salary+da+hra)
    printf("net salary = %.3lf\n", get_net_salary(base_salary, da, hra, pf));
}

double get_net_salary(double bs, double da, double hra, double pf)
{
    return bs - (pf * (bs + (da * bs) + (hra * bs)));
}
