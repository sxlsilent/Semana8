#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool backtrack(int row, int n,
               vector<int>& board,
               unordered_set<int>& cols,
               unordered_set<int>& diag1,
               unordered_set<int>& diag2) {
    if (row == n) return true;

    for (int col = 0; col < n; col++) {
        int d1 = row - col;
        int d2 = row + col;

        if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) continue;

        board[row] = col;
        cols.insert(col);
        diag1.insert(d1);
        diag2.insert(d2);

        if (backtrack(row + 1, n, board, cols, diag1, diag2)) return true;

        board[row] = -1;
        cols.erase(col);
        diag1.erase(d1);
        diag2.erase(d2);
    }

    return false;
}

void printBoard(const vector<int>& board) {
    int n = (int)board.size();
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << (board[r] == c ? "Q " : ". ");
        }
        cout << "\n";
    }
}

int main() {
    int n = 8;
    vector<int> board(n, -1);

    unordered_set<int> cols, diag1, diag2;

    bool ok = backtrack(0, n, board, cols, diag1, diag2);

    if (ok) {
        cout << "Solucion (fila -> columna): ";
        for (int r = 0; r < n; r++) cout << board[r] << " ";
        cout << "\n\n";
        printBoard(board);
    } else {
        cout << "No hay solucion.\n";
    }

    return 0;
}
