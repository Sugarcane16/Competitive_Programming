/*
1. calculate A^k where A is a square matrix
A = 3 12 4
    5 9 15
    0 2 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3;

struct Matrix {
    long long m[N][N];
};

// Make a zero 3x3 matrix
Matrix zeroMatrix() {
    Matrix Z;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z.m[i][j] = 0;
        }
    }
    return Z;
}

// Make identity 3x3 matrix
Matrix identityMatrix() {
    Matrix I = zeroMatrix();
    for (int i = 0; i < N; i++) I.m[i][i] = 1;
    return I;
}

// Multiply two 3×3 matrices
Matrix multiply(Matrix A, Matrix B) {
    Matrix C = zeroMatrix();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return C;
}

// Fast exponentiation of matrix A^k
Matrix power(Matrix A, long long k) {
    Matrix result = identityMatrix();
    while (k > 0) {
        if (k & 1) result = multiply(result, A);
        A = multiply(A, A);
        k >>= 1;
    }
    return result;
}

/*
3. How to find a path of 4 edges via matrix by putting an adjacency matrix to the fourth power
with a certain formula (min-plus matrix multiplication)
*/

const int INF = 1000000000;

// Special min-plus multiplication:
// C[i][j] = min over k ( A[i][k] + B[k][j] )
vector<vector<int>> minPlusMultiply(const vector<vector<int>>& A,
                                    const vector<vector<int>>& B) {
    int n = (int)A.size();
    vector<vector<int>> C(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] >= INF) continue; // small speedup
            for (int j = 0; j < n; j++) {
                if (B[k][j] >= INF) continue;
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}

int main() {
    // Part 1
    Matrix A;
    long long initA[N][N] = {
        {3, 12, 4},
        {5, 9, 15},
        {0, 2, 4}
    };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A.m[i][j] = initA[i][j];
        }
    }

    long long k;
    cin >> k;

    Matrix ans = power(A, k);

    // Output result of A^k
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans.m[i][j] << " ";
        }
        cout << endl;
    }

    /*
    2. explain why the value of X^n can be calculated in O(log n) time so that the value of f(n) can also be calc'd in O(log n) time
    The value of X^n can be computed in O(log n) time using fast exponentiation,
    which repeatedly squares X and reduces the exponent by half at each step,
    requiring only O(log n) multiplications.
    Since f(n) depends on X^n, once X^n is computed in O(log n) time,
    f(n) can also be evaluated in O(log n) time.
    */

    // Part 3
    int n = 6;
    vector<vector<int>> M(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) M[i][i] = 0;

    // edges:
    // 1->4 (4)
    // 2->1 (2), 2->5 (1), 2->6 (2)
    // 3->2 (4)
    // 4->2 (1)
    // 6->3 (3), 6->5 (2)
    M[0][3] = 4;
    M[1][0] = 2;
    M[1][4] = 1;
    M[1][5] = 2;
    M[2][1] = 4;
    M[3][1] = 1;
    M[5][2] = 3;
    M[5][4] = 2;

    vector<vector<int>> M2 = minPlusMultiply(M, M);
    vector<vector<int>> M4 = minPlusMultiply(M2, M2);

    cout << "\nShortest distances using exactly 4 edges:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M4[i][j] >= INF) cout << "INF ";
            else cout << M4[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
