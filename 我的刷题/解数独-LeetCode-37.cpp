class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> row(9,vector<bool>(10,false));
		vector<vector<bool>> col(9,vector<bool>(10,false));
		vector<vector<bool>> block(9,vector<bool>(10,false));
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0';
					row[i][num] = true;
					col[j][num] = true;
					
					block[i / 3 * 3 + j / 3][num] = true;
				}
			}
		}
		dfs(board, row, col, block, 0, 0);
		
	}
	bool dfs(vector<vector<char>>& board,
			vector<vector<bool>>& row,
			vector<vector<bool>>& col,
			vector<vector<bool>>& block,
			int a, 
			int b){
		
		while (board[a][b] != '.') {
			if (++b >= 9) {
				++a;
				b = 0;
			}
			if(a >= 9) {
				return true;
			}
		}
		
		for (int i = 1; i <= 9; i++){
			int blockIndex = a / 3 * 3 + b / 3;
			if (!row[a][i] && !col[b][i] && !block[blockIndex][i]) {
				
				board[a][b] = '0' + i;
				row[a][i] = true;
				col[b][i] = true;
				block[blockIndex][i] = true;
				
				if (dfs(board, row, col, block, a, b)) {
					return true;
				} else {
					row[a][i] = false;
					col[b][i] = false;
					block[blockIndex][i] = false;
					board[a][b] = '.';
				}
			}
		}
		return false;
	}
	
};