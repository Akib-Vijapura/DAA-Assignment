/*
 Q1. A wildlife photographer snaps a photo and discovers it has been 90 degrees rotated. He wants to rotate it to its original position. Write a C program to assist him in rotating the image by 90 degrees clockwise using the given pixel matrix.
 
 Sample Input:
 4 // Size of the Matrix
 1 2 3 4 // Matrix
 5 6 7 8
 1 2 3 4
 5 6 7 8
 
 Sample Output:
 5 1 5 1
 6 2 6 2
 7 3 7 3
 8 4 8 4

 */

#include <iostream>
#include <vector>

class MatrixRotator {
public:
    void rotateMatrix(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                std::swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};

int main() {
    
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    MatrixRotator rotator;
    rotator.rotateMatrix(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

