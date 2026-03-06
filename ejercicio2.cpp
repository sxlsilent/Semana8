#include <iostream>
#include <vector>
#include <random>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Cuantos numeros aleatorios quieres generar? ";
    cin >> n;

    if (n <= 0) {
        cout << "n debe ser mayor que 0.\n";
        return 0;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 999);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) arr[i] = dist(gen);

    cout << "\nArreglo original:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nArreglo ordenado (Merge Sort):\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
