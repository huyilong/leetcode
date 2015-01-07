//in java if want to search substring or char 
//we could use str.indexOf(substring) which will return the index of the first char in substring
//otherwise it would return -1

//give an integer n, generate a matrix with 1 to n^2 in spiral order
class Foo{
public:
	vector<vector<int>> generate_spiralMatrix(int n){
		vector<<vector<int>> matrix(n, vector<int>(n));
		int begin =0, end =n-1;
		//do not make any difference between beginX and beginY
		//just use begin and end for 1d vector
		int num=1;

		while(begin<end){
			//actually we only need to loop for n/2 times
			//because each time we add 4 rows 
			for(int j= begin; j<end; ++j)
				matrix[begin][j] = num++;

			for(int i =begin; i<end; ++i)
				matrix[i][end] = num++;

			for(int j= end; j>begin; --j)
				matrix[end][j] = num++;

			for(int i=end; i>begin; --i)
				matrix[i][begin] = num++;

			++begin;
			--end;
		}

		//for the middle element
		if(begin==end)
			matrix[begin][begin] = num;

		return matrix;//return the final 2D matrix
	}
}