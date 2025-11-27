// Position   :
// Round      : 
// Interviewer: 
// Date       : 

#include <bits/stdc++.h>
using namespace std;

// Recursively print elements of matrix in Morton (Z-order)
// mat  : 2D matrix
// r0,c0: top-left corner of current sub-matrix
// rows, cols: size of current sub-matrix
void printMorton(const vector<vector<int>>& mat,
                 int r0, int c0,
                 int rows, int cols)
{
    // Empty region
    if (rows <= 0 || cols <= 0)
        return;

    // Base case: single element
    if (rows == 1 && cols == 1) {
        cout << mat[r0][c0] << " ";
        return;
    }

    // Split into quadrants
    int rMid = rows / 2;
    int cMid = cols / 2;

    // 1. Top-left
    printMorton(mat, r0,         c0,         rMid,         cMid);

    // 2. Top-right
    printMorton(mat, r0,         c0 + cMid,  rMid,         cols - cMid);

    // 3. Bottom-left
    printMorton(mat, r0 + rMid,  c0,         rows - rMid,  cMid);

    // 4. Bottom-right
    printMorton(mat, r0 + rMid,  c0 + cMid,  rows - rMid,  cols - cMid);
}

int main() {
    // Example: 4x4 matrix
    vector<vector<int>> mat = {
        {  1,  2,  3,  4 },
        {  5,  6,  7,  8 },
        {  9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    cout << "Morton (Z-order) traversal:\n";
    printMorton(mat, 0, 0, (int)mat.size(), (int)mat[0].size());
    cout << "\n";

    return 0;
}
