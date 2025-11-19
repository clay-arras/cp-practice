// https://leetcode.com/problems/design-tic-tac-toe

class TicTacToe {
public:
    int rows[3];
    int cols[3];

    TicTacToe(int n) {
        fill(rows, rows+3, 0);
        fill(cols, cols+3, 0);
    }
    
    int move(int row, int col, int player) {
        rows[row] += (player == 1 ? 1 : -1);
        cols[col] += (player == 1 ? 1 : -1);


        if (abs(cols[col]) == 3) 
            return cols[col] > 0 ? 1 : 2;
        if (abs(rows[row]) == 3) 
            return rows[row] > 0 ? 1 : 2;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */