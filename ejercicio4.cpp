#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Ingrese n: ";
    cin >> n;

    long long a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        cout << a << " ";

        long long temp = a;
        a = b;
        b = temp + b;
    }

    return 0;
}
