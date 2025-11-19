// https://leetcode.com/problems/design-tic-tac-toe

class TicTacToe {
public:
    int N;
    vector<int> rows, cols, diag;

    TicTacToe(int n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diag = vector<int>(2, 0);
        N = n;
    }

    int move(int row, int col, int player) {
        int currentPlayer = (player == 1 ? 1 : -1);
        rows[row] += currentPlayer;
        cols[col] += currentPlayer;

        if (row == col)
            diag[0] += currentPlayer;
        if (row == N - col - 1)
            diag[1] += currentPlayer;

        if (abs(cols[col]) == N || (abs(rows[row]) == N) ||
            (abs(diag[0]) == N) || (abs(diag[1]) == N)) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */