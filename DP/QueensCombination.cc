#include<bits/stdc++.h>
using namespace std;


class Queens{

private:
    // private data members
    int n;
    vector<vector<char>> board;
    // private member functions
    bool isValid(int row, int col); // for n-queens problem
    // if(isValid(board, n, row, col)) {
    // }
public:
    // constructors
    Queens(){}
    Queens(int _n) : n(_n) {
        board.resize(n, vector<char>(n, '.'));
    }
    ~Queens(){}

    // public member functions
    void print();
    void queensCombination1(int row = 0, int col = 0, int nq = 0);
    void nQueensTogether(int row = 0, int col = 0, int nq = 0);
    void queensCombinationAs1D(int cell_id, int nq);
};

// return_type Class_name Score_resolution_operator funtion_name
void Queens::print() {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}
bool Queens::isValid(int row, int col) {
    for(int i=0; i<n; ++i) {
        if(board[i][col] != '.') return false;
        if(board[row][i] != '.') return false;
    }
    /// lower v
    for(int i=row, j=col; i<n and j<n; ++i, ++j) {
        if(board[i][j] != '.') return false;
    }
    for(int i=row, j=col; i<n and j>=0; ++i, --j) {
        if(board[i][j] != '.') return false;
    }
    // upper v
    for(int i=row, j=col; i>=0 and j<n; --i, ++j) {
        if(board[i][j] != '.') return false;
    }
    for(int i=row, j=col; i>=0 and j>=0; --i, --j) {
        if(board[i][j] != '.') return false;
    }
    return true;
}
void Queens::queensCombination1(int row, int col, int nq) {
    if(row == this->n) {
        if(nq == n){
            this->print();
            cout << endl;
        }
        return;
    }

    // to fill remaining cols of current row.
    for(int i=col + 1; i<n; i++) {
        board[row][i] = 'Q';
        queensCombination1(row + 1, i + 1, nq + 1);
        board[row][i] = '.';
    }

    // to fill remaining rows after current row.
    for(int i=row + 1; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(isValid(i, j)) {
                board[i][j] = 'Q';
                queensCombination1(i, j, nq + 1);
                board[i][j] = '.';
            }
        }
    }

}

void Queens::queensCombinationAs1D(int lcno, int nq) {

    if(lcno == n*n-1) {
    if(nq == n){ this->print(); cout << endl; } return;
    }

    for(int cell=lcno+1; cell<(n*n); ++cell){
        int row = cell / this->n;
        int col = cell % this->n;
        int ncell = n * row + col;

        if(isValid(row, col)) {
            board[row][col] = to_string(cell)[0];
            queensCombinationAs1D(ncell, nq+1);
            board[row][col] = '.';
        }
    }
}

void Queens::nQueensTogether(int row, int col, int nq) {
    if(row == this->n) {
        if(nq == n) { this->print(); cout << endl; }
        return;
    }
    for(int i=row; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(isValid(i, j)) {
                board[i][j] = 'Q';
                queensCombination1(i+1, j, nq + 1);
                board[i][j] = '.';
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    Queens king(n);

    king.queensCombinationAs1D(-1, 0);
}
