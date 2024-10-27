#include<iostream>
#include<vector>
using namespace std;

//--------------task1--------------------

//Fibonacci series using recursion
long long fib_recursion(int n){
    if(n==0 or n==1)
        return n;
    return fib_recursion(n-1) + fib_recursion(n-2);
}

//Fibonacci series using divide and conquer (matrix multiplication)
// Helper function to multiply two matrices
vector<vector<int>> multiply_matrices(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    vector<vector<int>> result(2, vector<int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// Function to calculate power of a matrix
 vector<vector<int>> matrix_power(vector<vector<int>> base, int n) {
    vector<vector<int>> result = {{1, 0}, {0, 1}}; // Identity matrix
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply_matrices(result, base);
        }
        base = multiply_matrices(base, base);
        n /= 2;
    }
    return result;
}

// Function to calculate nth Fibonacci number using matrix exponentiation
int fibonacci_matrix(int n) {
    if (n == 0)
        return 0;
    vector<std::vector<int>> base = {{1, 1}, {1, 0}};
    vector<std::vector<int>> result = matrix_power(base, n - 1);
    return result[0][0];
}


// Fibonacci series using dynamic programming
long long fib_dynamic_programming(int n){
    if(n == 0 or n == 1)
        return n;

    std::vector<long long> fib(n+1, 0);

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i<= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

int main(){

}
