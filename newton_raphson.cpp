#include <iostream>
#include <cmath>
using namespace std;

#define EPSILON 0.001

double func(double x) {
    return x * x * x - 2 * x - 5;
}

double derivFunc(double x) {
    return 3 * x * x - 2;
}

void newtonRaphson(double x) {
    double h = func(x) / derivFunc(x);
    while (fabs(h) >= EPSILON) {
        h = func(x) / derivFunc(x);
        x = x - h;
    }
    cout << "Root: " << x << endl;
}

int main() {
    double x0;
    cout << "Enter initial guess: ";
    cin >> x0;

    newtonRaphson(x0);
    return 0;
}
