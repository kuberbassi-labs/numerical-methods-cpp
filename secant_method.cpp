#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x * x * x - 2 * x - 5;
}

int main() {
    double x0, x1, x2, f0, f1, f2, e;
    int step = 1, maxIter;

    cout << setprecision(6) << fixed;
    cout << "Enter first guess: ";
    cin >> x0;
    cout << "Enter second guess: ";
    cin >> x1;
    cout << "Enter tolerable error: ";
    cin >> e;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    do {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1) {
            cout << "Mathematical error: division by zero.\n";
            return 1;
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        cout << "Iteration " << step << ":\tx = " << x2 << "\tf(x) = " << f2 << endl;

        x0 = x1;
        x1 = x2;
        step++;

        if (step > maxIter) {
            cout << "Did not converge within given iterations.\n";
            return 1;
        }
    } while (fabs(f2) > e);

    cout << "\nRoot: " << x2 << endl;
    return 0;
}
