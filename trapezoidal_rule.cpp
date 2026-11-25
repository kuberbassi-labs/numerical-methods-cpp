#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    double lower, upper;
    int subInterval;

    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of subintervals: ";
    cin >> subInterval;

    double stepSize = (upper - lower) / subInterval;
    double integration = f(lower) + f(upper);

    for (int i = 1; i < subInterval; i++) {
        double k = lower + i * stepSize;
        integration += 2 * f(k);
    }

    integration = integration * stepSize / 2.0;
    cout << "Value of integration: " << integration << endl;
    return 0;
}
