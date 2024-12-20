#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(r, vector<int>(c, 0));
    }

    void inputMatrix() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void displayMatrix() const {
        for (const auto& row : mat) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions do not allow multiplication!");
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible. Columns of first matrix must equal rows of second matrix." << endl;
        return 1;
    }

    Matrix mat1(r1, c1), mat2(r2, c2);

    cout << "Input first matrix:" << endl;
    mat1.inputMatrix();

    cout << "Input second matrix:" << endl;
    mat2.inputMatrix();

    try {
        Matrix result = mat1 * mat2;
        cout << "Resultant Matrix after multiplication:" << endl;
        result.displayMatrix();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


