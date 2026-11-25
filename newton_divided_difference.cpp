#include <iostream>
using namespace std;

int main() {
    int n;
    double x[20], y[20][20];

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter values of x: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter values of y: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i][0];
    }

    cout << "\nDivided Difference Table:\n";
    for (int i = 1; i < n; i++) {
        cout << "Order " << i << ": ";
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);
            cout << y[j][i] << " ";
        }
        cout << endl;
    }

    double xp;
    cout << "\nEnter interpolation point x: ";
    cin >> xp;

    double value = y[0][0];
    for (int k = 1; k < n; k++) {
        double p = 1;
        for (int m = 0; m < k; m++) {
            p *= (xp - x[m]);
        }
        value += p * y[0][k];
    }

    cout << "Interpolated value at x = " << xp << " is " << value << endl;
    return 0;
}
