#include <iostream>
using namespace std;

#define EP 0.01

double solution(double x) {
    return x * x * x - 2 * x - 5;
}

void bisection(double a, double b) {
    if (solution(a) * solution(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs.\n";
        return;
    }

    double c = a;
    while ((b - a) >= EP) {
        c = (a + b) / 2;
        if (solution(c) == 0.0) {
            break;
        } else if (solution(c) * solution(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    cout << "Root: " << c << endl;
}

int main() {
    double a, b;
    cout << "Enter lower limit: ";
    cin >> a;
    cout << "Enter upper limit: ";
    cin >> b;

    bisection(a, b);
    return 0;
}
