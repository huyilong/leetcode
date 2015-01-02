/*

A DP is an algorithmic technique which is usually based on a recurrent formula and one (or some) 
starting states. A sub-solution of the problem is constructed from previously found ones. 

DP solutions have a polynomial complexity which assures a much faster running time than other 
techniques like backtracking, brute-force etc. 

*/

/*
What does a "state" stand for? 

It's a way to describe a situation, a sub-solution for the problem.

 For example a state would be the solution for sum i, where i≤S. 
 A smaller state than state i would be the solution for any sum j, where j<i. 

 For finding a state i, we need to first find all smaller states j (j<i) . 

 Having found the minimum number of coins which sum up to i, we can easily find the next state 
 - the solution for i+1. 

Set Min[i] equal to Infinity for all of i
Min[0]=0

For i = 1 to S
For j = 0 to N - 1
   If (Vj<=i AND Min[i-Vj]+1<Min[i])
Then Min[i]=Min[i-Vj]+1

Output Min[S]
 */


//given a triangle, find the min path sum from top - down
//we use the DP to solve it from bottom - up

class DP{
public:
	//in java we need to use 2d arraylist where the elements are of Integer type : objects
	//in c++ always use auto instead of Object and size_t instead of just int
	//in c++ always use const and reference for the input parameters
	int go(vector< vector<int> > & triangle){
		//because actually the last row is used as triangle.size() - 1
		//which is the relationship between
		for(int i = triangle.size() - 2; i>=0; --i)
		{
			for(int j=0; j<i+1; ++j)
			{
				//yes, we do not need to create a new state triangle
				//because it is used by bottom-up we could just use the original triangle
				//to calculate the sum ,  that is why the input parameter does not 
				//used const before its reference -> all we need to do is to change it

				//space complexity O(1)
				triangle[i][j] = min (triangle[i+1][j], triangle[i][j+1]) + triangle[i][j];
			}

		}
		//firstly get this problem actually does not fully understand it
		//must repeatedly comprehend and code it 
		//ever seen it or coded it does not mean completely get it
		return triangle[0][0];
	}
};

