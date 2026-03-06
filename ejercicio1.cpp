#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string secret_pin = "0427"; 

    for (int i = 0; i < 10000; i++) {
        ostringstream oss;
        oss << setw(4) << setfill('0') << i;
        string guess = oss.str();

        if (guess == secret_pin) {
            cout << "PIN encontrado: " << guess << "\n";
            cout << "Intentos: " << (i + 1) << "\n";
            break;
        }
    }

    return 0;
}
