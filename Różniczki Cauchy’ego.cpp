#include <iostream>

using namespace std;

double Cauchy(double x, double y)
{
    double f; // w zależności jaką funkcję chcmey wyliczyć to ją odkomentujemy
    f = x*x + y; 
    //f = x + y;
    return f;
}

double Euler(double h, double x0, double y0, const int n)
{
    double* X = new double [n + 1];
    double* Y = new double[n + 1];
    X[0] = x0;
    Y[0] = y0;
    double f;
    cout << "x0 = " << x0 << endl;
    cout << "y0 = " << y0 << endl;
    cout << "f(x, y) = " << Cauchy(X[0], Y[0]) << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        X[i + 1] = X[i] + h;

        f = Cauchy(X[i], Y[i]);

        Y[i + 1] = Y[i] + (h * f);

        cout << "x" << i + 1 << " = " << X[i + 1] << endl;
        cout << "y(" << X[i + 1] << ") = " << Y[i + 1] << endl;
        cout << "f(x, y) = " << Cauchy(X[i + 1], Y[i + 1]) << endl;
        cout << endl;
    }
    return 0;
}

double RK2(double h, double x0, double y0, const int n)
{
    double* X = new double[n + 1];
    double* Y = new double[n + 1];
    X[0] = x0;
    Y[0] = y0;
    double f;
    double K[2];
    cout << "x0 = " << x0 << endl;
    cout << "y0 = " << y0 << endl;
    cout << "f(x, y) = " << Cauchy(X[0], Y[0]) << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        X[i + 1] = X[i] + h;

        f = Cauchy(X[i], Y[i]);
        K[0] = f;
        f = Cauchy(X[i] + h, Y[i] + K[0]*h);
        K[1] = f;
        Y[i + 1] = Y[i] + ((K[0] + K[1])*h)/2;

        cout << "x" << i + 1 << " = " << X[i + 1] << endl;
        cout << "y(" << X[i + 1] << ") = " << Y[i + 1] << endl;
        cout << "f(x, y) = " << Cauchy(X[i + 1], Y[i + 1]) << endl;
        cout << endl;
    }
    return 0;
}

double RK4(double h, double x0, double y0, const int n)
{
    double* X = new double[n + 1];
    double* Y = new double[n + 1];
    X[0] = x0;
    Y[0] = y0;
    double f;
    double K[4];
    cout << "x0 = " << x0 << endl;
    cout << "y0 = " << y0 << endl;
    cout << "f(x, y) = " << Cauchy(X[0], Y[0]) << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        X[i + 1] = X[i] + h;

        f = Cauchy(X[i], Y[i]);
        K[0] = f;

        f = Cauchy(X[i] + h/2, Y[i] + (K[0] * h)/2);
        K[1] = f;

        f = Cauchy(X[i] + h / 2, Y[i] + (K[1] * h) / 2);
        K[2] = f;

        f = Cauchy(X[i] + h, Y[i] + K[2] * h);
        K[3] = f;

        Y[i + 1] = Y[i] + ((K[0] + (2*K[1]) + (2*K[2]) + K[3]) * h) / 6;

        cout << "x" << i + 1 << " = " << X[i + 1] << endl;
        cout << "y(" << X[i + 1] << ") = " << Y[i + 1] << endl;
        cout << "f(x, y) = " << Cauchy(X[i+1], Y[i+1]) << endl;
        cout << endl;
    }
    return 0;
}

int main()
{
    double y0 = 0.1; // warunek początkowy
    cout << "Warunek poczatkowy y = " << y0 << endl;
    double x0 = 0.0;
    double a = 0.0;
    double x = 1.0;
    double N = 10.0;
    const int n = 10; // ilość powtórzeń
    double h;

    h = (x - a) / N;

    cout << "h = " << h << endl;
    cout << endl;


    Euler(h, x0, y0, n);

    cout << "-----------------------------------------------------------------------" << endl;

    RK2(h, x0, y0, n);

    cout << "-----------------------------------------------------------------------" << endl;

    RK4(h, x0, y0, n);

    return 0;
}

