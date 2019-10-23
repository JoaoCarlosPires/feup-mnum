#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {

    vector<vector<float>> matrix = {{9.0, 1.0, 5.0, 25.0}, {1.0, 4.0, 6.0, 16.0}, {2.0, 9.0, 7.0, 29.0}};
    cout << "Number of lines: " << matrix.size() << endl;
    cout << "Number of columns: " << matrix[0].size() << endl;
    cout << "\nMatrix:\n" << endl;

    for (int d = 0; d < matrix.size(); d++) {
        float aux = matrix[d][d];
        for (int c = 0; c < matrix[0].size(); c++) {
            matrix[d][c] = matrix[d][c] / aux;
        }
        for (int line = d+1; line < matrix.size(); line++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                matrix[line][col] = matrix[line][col] - matrix[d][col] * matrix[line][d];
            }
        }
    }
    for (int d = 0; d < matrix.size(); d++) {
        for (int c = 0; c < matrix[0].size(); c++) {
            if (c == 0) {cout << "|\t"; }
            if (c == (matrix[0].size()-1)) {cout << setprecision(3) << matrix[d][c]<< "\t"; cout << "|"; continue;}
            cout << setprecision(3) << matrix[d][c] << "\t\t";
            
        }
        cout << "\n";
    }

    return 0;
}