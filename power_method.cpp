#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define SIZE 10

int main() {
    double a[SIZE][SIZE], x[SIZE], xNew[SIZE];
    double lambdaNew = 1.0, lambdaOld = 1.0, error;
    int n, step = 1;

    cout << fixed << setprecision(5);
    cout << "Enter order of matrix: ";
    cin >> n;
    cout << "Enter tolerable error: ";
    cin >> error;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    cout << "Enter initial guess vector:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }

    do {
        lambdaOld = lambdaNew;

        for (int i = 0; i < n; i++) {
            double temp = 0.0;
            for (int j = 0; j < n; j++) {
                temp += a[i][j] * x[j];
            }
            xNew[i] = temp;
        }

        for (int i = 0; i < n; i++) {
            x[i] = xNew[i];
        }

        lambdaNew = fabs(x[0]);
        for (int i = 1; i < n; i++) {
            if (fabs(x[i]) > lambdaNew) {
                lambdaNew = fabs(x[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            x[i] /= lambdaNew;
        }

        cout << "\nStep " << step++ << ":\n";
        cout << "Eigenvalue = " << lambdaNew << "\n";
        cout << "Eigenvector = [ ";
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << "]\n";
    } while (fabs(lambdaNew - lambdaOld) >= error);

    return 0;
}
