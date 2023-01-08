// https://leetcode.com/problems/sudoku-solver/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fillUp(board);
    }

    bool isValid(vector<vector<char>> &board, int &row, int &col, char &val){
        for (int i = 0; i < 9; ++i)
        {
            if (board[row][i] == val) return false;
            if (board[i][col] == val) return false;
            if (board[3*(row/3)+i/3][3 *(col/3)+i%3] == val) return false;
        }
        return true;
    }

    bool fillUp(vector<vector<char>> &board){

        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                if (board[row][col] == '.') {
                    // We find an empty spot to fill.
                    // Possible values (0-9)
                    // check for each value and create branches for each possibility.

                    for (char val = '1'; val <= '9'; ++val)
                    {
                        if (isValid(board, row, col, val)) {
                            board[row][col] = val;
                            if (fillUp(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

int main () {
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << ((9 * i) / 3 + j / 3) << "  ";
        }
        cout << endl;
    }
    
    return 0;
}