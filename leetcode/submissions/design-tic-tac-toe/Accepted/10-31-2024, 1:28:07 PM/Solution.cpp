// https://leetcode.com/problems/design-tic-tac-toe

class TicTacToe {
public:
    int N;
    vector<int> rows, cols, diag;

    TicTacToe(int n) {
        rows = vector<int> (n, 0);
        cols = vector<int> (n, 0);
        diag = vector<int> (2, 0);
        N = n;
    }
    
    int move(int row, int col, int player) {
        rows[row] += (player == 1 ? 1 : -1);
        cols[col] += (player == 1 ? 1 : -1);

        if (row == col)
            diag[0] += (player == 1 ? 1 : -1);
        if (row == N-col-1)
            diag[1] += (player == 1 ? 1 : -1);

        if (abs(cols[col]) == N) 
            return cols[col] > 0 ? 1 : 2;
        if (abs(rows[row]) == N) 
            return rows[row] > 0 ? 1 : 2;
        if (abs(diag[0]) == N) 
            return diag[0] > 0 ? 1 : 2;
        if (abs(diag[1]) == N) 
            return diag[1] > 0 ? 1 : 2;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */