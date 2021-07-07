#include <iostream>
#include <cmath>

using namespace std;

double uniform(double a, double b)
{
    double r = rand() * 1.0 / RAND_MAX;
    return r * (b - a) + a;
}

double f(double x)
{
    double y;
    // y = exp(-pow(x - 2, 2)) + exp(-pow(x + 2, 2));
    // y=sqrt(x)/(sqrt(6-x)+sqrt(x));
    y = sqrt(sin(x)) / (sqrt(sin(x)) + sqrt(cos(x)));
    return y;
}

double simple_mc(double a, double b, int N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        double x = uniform(a, b);
        sum += f(x);
    }
    return sum * (b - a) / N;
}
void definite_integral(double a, double b, int n)
{
    double sum_mc = 0.0;
    double all_mc[n];
    for (int i = 0; i < n; i++)
    {
        int N = 1000;
        double mc = simple_mc(a, b, N);
        all_mc[i] = mc;
        sum_mc += mc;
        cout << "N=" << N << "\t I_mc=" << mc << endl;
    }
    sum_mc = sum_mc / n;
    double all_e = 0.0;
    for (int i = 0; i < n; i++)
    {
        all_e += ((all_mc[i] - sum_mc) * (all_mc[i] - sum_mc) / n);
    }
    all_e = sqrt(all_e);
    cout << "The standard deviation: " << all_e << endl;
}

int main()
{
    definite_integral(0, M_PI_2, 10);
}