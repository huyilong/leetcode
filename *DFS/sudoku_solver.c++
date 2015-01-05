class Foo{
public:
	bool sudokuSolver(vector<vector<char> > &board){
		for(int i=0; i<9; ++i){
			for(int j=0; j<9; ++j){

				//if there is an empty position
				//then k is used to try thoroughly from 1-9 until find a viable piece
				//where at first there are many choices but will less and less to find one
				if(board[i][j] == '.'){
					for(int k=0; k<9; ++k){
						board[i][j] = '1' + k;//dynamically place the piece on the board
						if(isValid(board, i, j) && sudokuSolver(board))
							//everytime place one piece and then recursively call sudokuSolver(board)
							//for placing next one on the board and scanning
							return true;
						board[i][j] = '.';//reset the pieces which is not suitable
						//actually the next round will cover the last one
						//this is mainly used to take care of the last round
						//i.e. for 9 it is not correct then we must place '.'
					}
					return false;
				}
			}
		}
		return true

	}
}