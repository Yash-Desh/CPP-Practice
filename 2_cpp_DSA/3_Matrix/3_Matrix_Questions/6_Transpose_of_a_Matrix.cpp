// Author : Yash Deshpande
// Date : 08-07-2023

#include <bits/stdc++.h>
using namespace std;

// In-place transpose for a SQUARE matrix (rows == cols).
void transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// Transpose for a RECTANGULAR (M x N) matrix. Returns a new N x M matrix,
// since an in-place swap only works when dimensions are equal.
// NVIDIA TensorRT Role
vector<vector<int>> transposeRectangular(const vector<vector<int>> &matrix)
{
    if (matrix.empty())
        return {};

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> result(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// Helper to print a matrix.
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Square matrix : in-place transpose
    vector<vector<int>> square = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    cout << "Square matrix (original):" << endl;
    printMatrix(square);

    transpose(square);
    cout << "\nSquare matrix (transposed in-place):" << endl;
    printMatrix(square);

    // Rectangular matrix : returns a new N x M matrix
    vector<vector<int>> rect = {{1, 2, 3, 4},
                                {5, 6, 7, 8}};
    cout << "\nRectangular matrix (original 2x4):" << endl;
    printMatrix(rect);

    vector<vector<int>> rectT = transposeRectangular(rect);
    cout << "\nRectangular matrix (transposed 4x2):" << endl;
    printMatrix(rectT);

    return 0;
}