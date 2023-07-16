/*
 Q2. Given a matrix write a C program to print the spiral representation of it. Use variables, top, bottom, left, and right, to keep track of the boundaries of the matrix as it spirals inwards. It starts by printing the top row, then the rightmost column, then the bottom row, and finally the leftmost column. After each row or column is printed, the corresponding boundary variable is updated, and the process is repeated until all elements in the matrix have been printed.
 
 Sample Input 1:
 4 4 // Size of the matrix
 1 2 3 4 // matrix
 5 6 7 8
 9 10 11 12
 13 14 15 16
 
 Sample Output 1:
 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row*col;
        
        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        
        while(count < total) {
            
            //print starting row
            for(int index = startingCol; count < total && index<=endingCol; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; count < total && index<=endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; count < total && index>=startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for(int index = endingRow; count < total && index>=startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};

int main() {
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Create a test matrix
    vector<vector<int>> matrix;
    int n , m;
    cin>>n>>m;
    
    for(int i = 0 ; i < n ; i++){
        vector<int>temp;
        for(int j = 0 ; j < m ; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    
    // Call the spiralOrder function and store the result
    vector<int> result = solution.spiralOrder(matrix);
    
    // Print the result
    cout << "Spiral Order: ";
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

