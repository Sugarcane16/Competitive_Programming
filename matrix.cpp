/*
1. calculate A^k where A is a square matrix
A = 3 12 4
    5 9 15
    0 2 4
*/
#include <iostream>
using namespace std;

const int N = 3;

struct Matrix {
    long long m[N][N];
};

// Multiply two 3×3 matrices
Matrix multiply(Matrix A, Matrix B) {
    Matrix C = {};
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
    Matrix result = {};      // Identity matrix
    for (int i = 0; i < N; i++)
        result.m[i][i] = 1;

    while (k > 0) {
        if (k & 1)
            result = multiply(result, A);
        A = multiply(A, A);
        k >>= 1;
    }
    return result;
}

int main() {
    Matrix A = {{
        {3, 12, 4},
        {5, 9, 15},
        {0, 2, 4}
    }};

    long long k;
    cin >> k;

    Matrix ans = power(A, k);

    // Output result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans.m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
2. explain why the value of f(n) can be calculated in O(log n) time
3. How to find a path of 4 edges via matrix
*/