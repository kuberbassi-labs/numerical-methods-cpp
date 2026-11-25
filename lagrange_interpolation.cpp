#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[20], y[20];
    cout << "Enter values of x and y:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    double xp;
    cout << "Enter interpolation point x: ";
    cin >> xp;

    double yp = 0;
    for (int i = 0; i < n; i++) {
        double p = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }

    cout << "Interpolated value at x = " << xp << " is " << yp << endl;
    return 0;
}
