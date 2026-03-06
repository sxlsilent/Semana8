#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int amount = 100;
    vector<int> coins = {1, 5, 10, 25};

    sort(coins.rbegin(), coins.rend());

    vector<int> result;

    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }

    cout << "Monedas usadas: ";
    for (int c : result)
        cout << c << " ";

    cout << "\nCantidad total: " << result.size() << endl;

    return 0;
}
