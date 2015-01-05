class Foo{
public:
	bool findWordInMatrx(vector< vector<char>> &board, string word){
		const int m = board.size();
		const int n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		for(int i = 0; i<m; ++i){
			for (int j=0; j<n; ++j){
				if(dfs(board, word, 0, i, j, visited))
					return true;
			}
		}
		return false;
	}

private:
	static bool dfs(const vector<vector<char>> &board, const string &word, int index, int x, int y
		vector<vector<bool>> &visited)
		//the matrix visited[][] is not const and is &, thus should be reset after
		//each recursion, we need to reuse it for the next position on the board

	if(index == word.size())//base condition
		return true;//legal touchdown, bounce back

	if(x<0 || y<0 || x > board.size()-1 || y > board[0].size()-1)
		return false;//illegal, terminate

	if(visited[i][j])
		return false;//prune

	if(board[i][j] != word[index])
		return false;//prune, not equal and thus need not go down to compare next position of word

	visited[x][y] = true; //actually does not have any operation meaning
	//but this is necessary to avoid repetition for next round of comparison

	bool result = dfs(board, word, index+1, x-1 , y, visited) ||
					dfs(board, word, index+1, x+1 , y, visited) ||
						dfs(board, word, index+1, x , y+1, visited) ||
  							dfs(board, word, index+1, x-1 , y, visited);
  	//important note::  x-1 is go for up, x+1 is go for down, y+1 is go for right, y-1 is go for left
  	//because board[x+1][y] is actually going for the next row!!! not column!!
  	//hence it is different from our normal sense
  	//vector first index is for choosing rows, but in real our first x is choosing columns

  	//reset the visited board for following check
  	visited[x][y] = false;
};
