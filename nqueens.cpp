#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> solutions;
vector<int> board;
vector<bool> col, diag1, diag2;

void search(int row) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (!col[c] && !diag1[row + c] && !diag2[row - c + n - 1]) {
            board[row] = c;
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;
            search(row + 1);
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
        }
    }
}

int main() {
    cout << "Please enter n: ";
    cin >> n;

    col.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);
    board.assign(n, -1);

    search(0);

    cout << "There are " << solutions.size() << " solutions.\n\n";

    for (int idx = 0; idx < solutions.size(); ++idx) {
        cout << "Solution #" << idx + 1 << ":\n";
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (solutions[idx][r] == c) {
                    cout << "1 ";
                } else {
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
