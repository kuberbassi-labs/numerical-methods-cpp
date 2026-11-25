#include <iostream>
#include <cmath>
using namespace std;

double func(double x, double y) {
    return 3 * x * x + y * y;
}

double rungeKutta(double x0, double y0, double x, double h) {
    int n = static_cast<int>(round((x - x0) / h));
    double y = y0;

    for (int i = 1; i <= n; i++) {
        double k1 = h * func(x0, y);
        double k2 = h * func(x0 + 0.5 * h, y + 0.5 * k1);
        double k3 = h * func(x0 + 0.5 * h, y + 0.5 * k2);
        double k4 = h * func(x0 + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x0 += h;
    }

    return y;
}

int main() {
    double x0, y0, x, h;

    cout << "Enter initial x (x0): ";
    cin >> x0;
    cout << "Enter initial y (y0): ";
    cin >> y0;
    cout << "Enter target x: ";
    cin >> x;
    cout << "Enter step size (h): ";
    cin >> h;

    cout << "Value of y at x = " << x << " is " << rungeKutta(x0, y0, x, h) << endl;
    return 0;
}
