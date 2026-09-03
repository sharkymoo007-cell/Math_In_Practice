#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() 
{
    int N;
    cout << "Enter the size of the matrix (N): ";
    cin >> N;

    // Create an augmented matrix of size N x (N + 1)
    // A[i][0...N-1] holds coefficients, A[i][N] holds constants
    vector<vector<double>> matrix(N, vector<double>(N + 1));

    cout << "\nEnter the augmented matrix row by row:\n";

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j <= N; j++) {cin >> matrix[i][j];}
    }

    // STEP 1: Forward Elimination (convert matrix to Upper Triangular Form)
    for (int i = 0; i < N - 1; i++) 
    {
        // Basic check for zero on the diagonal (pivot element)
        if (matrix[i][i] == 0) 
        {
            cout << "Division by zero detected on pivot! (Requires partial pivoting)\n";
            return 1;
        }

        for (int k = i + 1; k < N; k++) 
        {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= N; j++) {matrix[k][j] -= factor * matrix[i][j];}
        }
    }

    // STEP 2: Back Substitution (solve for variables from bottom to top)
    vector<double> solution(N);
    for (int i = N - 1; i >= 0; i--) 
    {
        solution[i] = matrix[i][N]; // Start with the right-hand side constant

        // Subtract the already calculated variables
        for (int j = i + 1; j < N; j++) {solution[i] -= matrix[i][j] * solution[j];}

        // Divide by the coefficient of the current variable
        solution[i] /= matrix[i][i];
    }

    // STEP 3: Display results
    cout << "\nSolution for the system:\n";
    cout << fixed << setprecision(4);
    for (int i = 0; i < N; i++) {cout << "x[" << i + 1 << "] = " << solution[i] << endl;}

    return 0;
}