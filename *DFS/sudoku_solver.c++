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
		return true;
	}

private:
	bool isValid(const vector<vector<char>> &board, int x, int y){
		int i,j;
		for(i=0; i<9; ++i)//up and down vertically
			//remember that the real world index x is the y in vector for first index
			if(i!=x && board[i][y] == board[x][y])
				return false;//find another place has the same number piece
			//then this place could not be viable for the current piece
		for(j=0; j<9; ++j)
			if(j!=y && board[x][j] == board[x][y])
				return false;

		for(i = 3*(x/3); i<3*(x/3 +1); ++i)
			for(j= 3*(j/3); j<3*(j/3 +1); ++j)
				if(i!=x & j!=y && board[i][j] == board[x][y])
					return false; //checking for the 9-cell board

		//after all the checking on the board
		return true;
			
	}

};