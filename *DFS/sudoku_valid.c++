//one dimension array could be used as a hashmap 
//any row,column,3*3board could not contain multiple 1-9

class Foo{
public:
	bool isValid(vector<vector<char>> &board){
		bool used[9];
		//using the letter itself as the hash key

		for(int i=0; i<9; ++i){

			fill(used, used+9, false);
			//for 2d matrix
			//we could use
			//vector< vector<bool> > visited(m, vector<bool> (n,false));
			//or vector < vector<int> > matrix( { {1,2,3}, {2,3,4}, {3,4,5} });

			for(int j=0; j<9; ++j)//check the rows
			{
				//chekc will be encapsulated in another function
				if(!check( board[i][j], used ) ) 
					return false; // prune
			}

			fill(used, used+9, false);
			//reset the hashtable
			//fill(it1, it2, sth)

			for(int j = 0; j<3; ++j) // check the columns
			{
				if(!check( board[j][i], used ))
					return false;
			}
		}


		for(int r=0; r<3; ++r){
			for(int c=0; c<3; ++c){

				//every time will reset the hashtable
				fill(used, used+9, false);

				for(int i = r*3; i< r*3+3; ++i)
					for(int j = c*3; j<c*3+3; ++j){

						if( !check (board[i][j],used) )
							return false;
					}
			}
		}

		return true;//after all rounds of the checking stated above

	}


	bool check(char ch, bool used[9]){
		//bool check(char ch, bool *used)
		if(ch == '.') return true;//'.' denotes empty, which is legal

		if(used[ch - '1'])  return false;

		//put all the error checks before the final legal return true
		//this is after all rounds of checking
		used[ch - '1'] = true; // note:the index begins with 0 so we -'1'
		return true;
	}
};

