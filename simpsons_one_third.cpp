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

    if (subInterval % 2 != 0) {
        cout << "Subintervals must be even. Incrementing by 1.\n";
        subInterval++;
    }

    double stepSize = (upper - lower) / subInterval;
    double integration = f(lower) + f(upper);

    for (int i = 1; i < subInterval; i++) {
        double k = lower + i * stepSize;
        if (i % 2 == 0) {
            integration += 2 * f(k);
        } else {
            integration += 4 * f(k);
        }
    }

    integration = integration * stepSize / 3.0;
    cout << "Value of integration: " << integration << endl;
    return 0;
}
