//no two queens would be neighboring each other
//i.e. reverse diagnol/diagnl/row/column
//@version 1: output all the boards
class Foo{
public:
	vector<vector<string>> solveQueens(int n){
		this->columns = vector<int>(n, 0);//place n zeros in the column
		this->principal_diagonals = vector<int>(2*n, 0);// why 2*n? should be n?
		this->counter_diagonals = vetcor<int> (2*n,0);

		vector<vector<string>> result;
		vector<int> ith_row_queen_column(n,0);
		dfs(0, ith_row_queen_column, result);
		return result;
	}

private:
	//used to prune
	vector<int> columns;// which rows are already placed queens
	vector<int> principal_diagonals; //which principal diagonals are already placed queens
	vector<int> counter_diagonals;

	void dfs(int row, vector<int> &ith_row_queen_column, vector<vector<string>> &result){

		const int N = ith_row_queen_column.size();
		if(row == N){
			//terminal condition and base condition
			vector<string> solution;
			for(int i=0; i<N; ++i){
				//initialize this row with all dots empty
				string s(N,'.');
				for(int j=0; j<N;++j){
					if(j == ith_row_queen_column[i])
						s[j] = 'Q';
					//pick up the following checked queens in one row and place it
				}
				solution.push_back(s); //each time push one row into the solution
			}
			result.push_back(solution);
			return;
		}


		for(int j=0; j<N; ++j){
			const bool ok = 
			        columns[j] ==0 && principal_diagonals[row+j] == 0 && counter_diagonals[row-j+N] == 0;
			if(ok){
				//when legal we recurse 
				//ok is just used for pruning

				//mark "place" queen signal on the row
				//each time we actully using this 1d hashtable to choose place queen
				//this is the most important statement
				ith_row_queen_column[row] = j;

				//update the prunning variables for next round of following prunning time saving
				columns[j] = principal_diagonals[row+j] = counter_diagonals[row-j+N] = 1;
				dfs(row+1, ith_row_queen_column, result);
				//each time updating row's number by passing a new value to call next recursion

				//reset after the calling 
				columns[j] = principal_diagonals[row+j] = counter_diagonals[row-j+N] = 0;

			}
		}
	}
};



///version 2: just print out the possible result numbers
class Bar{
public:
	int solutionNum(int n){
		this->count = 0;
		//the following three vectors are just used for prunning 
		this->columns = vector<int>(n, 0);//place n zeros in the column
		this->principal_diagonals = vector<int>(2*n, 0);// why 2*n? should be n?
		this->counter_diagonals = vetcor<int> (2*n,0);

		vector<int> ith_row_queen_column(n, 0);
		dfs(0, ith_row_queen_column);

		return this->count;
	}

private:
	int count;
	vector<int> columns;// which rows are already placed queens
	vector<int> principal_diagonals; //which principal diagonals are already placed queens
	vector<int> counter_diagonals;

	void dfs(int row, vector<int> & ith_row_queen_column){
		const int N = ith_row_queen_column.size();
		if(row == N){
			//base condition
			//rather than using a loop to print out a row with queen on it
			//we just need to increase our solution number this time
			this->count ++;
			return;
		}

		for(j=0; j<N; ++j){
			//one column after one column checking
			//each time for one row to place
			const bool ok = 
			        columns[j] ==0 && principal_diagonals[row+j] == 0 && counter_diagonals[row-j+N] == 0;
			if(ok){
				//when legal we recurse 
				//ok is just used for pruning

				//mark "place" queen signal on the row
				//each time we actully using this 1d hashtable to choose place queen
				//this is the most important statement
				ith_row_queen_column[row] = j;

				//update the prunning variables for next round of following prunning time saving
				columns[j] = principal_diagonals[row+j] = counter_diagonals[row-j+N] = 1;


				//this time we do not need to pass result anymore because we do not need
				//to store the board state to print it out later
				dfs(row+1, ith_row_queen_column);
				//each time updating row's number by passing a new value to call next recursion

				//reset after the calling 
				columns[j] = principal_diagonals[row+j] = counter_diagonals[row-j+N] = 0;
		}
	}

};



