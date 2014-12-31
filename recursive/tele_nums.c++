/*
Backtracking is a general algorithm for finding all (or some) solutions to some computational 
problems, notably constraint satisfaction problems, that incrementally builds candidates to the 
solutions, and abandons each partial candidate c ("backtracks") as soon as it determines that c 
cannot possibly be completed to a valid solution.[1][2][3]

The classic textbook example of the use of backtracking is the eight queens puzzle, that asks for 
all arrangements of eight chess queens on a standard chessboard so that no queen attacks any other.
 In the common backtracking approach, the partial candidates are arrangements of k queens in the 
 first k rows of the board, all in different rows and columns. Any partial solution that contains 
 two mutually attacking queens can be abandoned, since it cannot possibly be completed to a valid 
 solution.
 */

 //problem: given a digit string, return all possible letter combinations that the number could represent
 //the output coud be unordered, i.e. it is a combination problem rather than a list

 class Foo{
 public:
 	//we have to fill the index[0] with non-sense letter as we people will input 1-9 to type letters
 	const vector<string> board{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

 	vector<string> go(const string &input_digits)
 	{
 		//here we just need to output a single string with all possible outputs
 		//different the number combination, which is required to output each result per line
 		//in that case, we need to construct a 2d vector to save each record
 		vector<string> result;

 		dfs(input_digits, 0, "", result);

 		return result;
 	}

 	void dfs(const string &input_digits, int offset, string path, vector<string> &result)
 	{
 		//if you click the button twice, only two letters could be possibly output
 		if(offset == input_digits.size()){
 			result.push_back(path);
 			return;
 		}

 		char current_num = input_digits[offset];
 		//convert the char to the int index to further map into the board as indexing
 		int according_place = current_num - '0';
 		//mapping into the board to find the according letter set according to the input digit
 		auto possible_letter_set = board[according_place];

 		for(auto possible_token : possible_letter_set)
 		{
 			dfs(input_digits, offset+1, path+possible_token, result);
 		}
 	}
 };