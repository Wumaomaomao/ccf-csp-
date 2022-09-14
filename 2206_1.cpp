#include<cstdio>
#include<iostream>
#include<cmath>

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    double sum = 0, even, D;
    cin >> n;

    double * data = new double[n];
    ll idx = 0;

    while(n-- > 0)
    {
        cin >> data[idx++];
        sum += data[idx - 1];
    }

    
    even = sum / (double)idx;

    n = idx;
    while(n-- > 0)
    {
        D += pow(data[n] - even, 2);
    }

    D = D / (double)idx;
    double D_res = sqrt(D);
    n = idx;
    idx = 0;
    while(idx < n)
    {
        double x = data[idx] - even;
        x = x / D_res;
        printf("%lf\n", x);
        ++idx;
    }

    delete []data;
    return 0;

}