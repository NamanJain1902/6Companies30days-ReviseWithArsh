class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // rotate the matrix in-place
        
        // given a square matrix
        int n = matrix.size();
        
        // Step 1: Transpose the given matrix
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Step 2: reverse each row
        for(int i=0; i<n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // rotate the matrix in-place
        
        // given a square matrix
        int n = matrix.size();
        
        // Step 1: reflect by x-axis
        for(int j=0; j<n; ++j) {
            for(int i=0; i<n/2; i++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
        
        // Step 2: Transpose the given matrix
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};