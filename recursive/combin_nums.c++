/*
回溯法（英语：backtracking）是暴力搜寻法中的一种。

回溯法采用试错的思想，它尝试分步的去解决一个问题。在分步解决问题的过程中，
当它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候，它将取消上一步甚至是上几步的计算，
再通过其它的可能的分步解答再次尝试寻找问题的答案。回溯法通常用最简单的递归方法来实现，
在反复重复上述的步骤后可能出现两种情况：

找到一个可能存在的正确的答案
在尝试了所有可能的分步方法后宣告该问题没有答案
在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算。
*/

/*

// iota example
#include <iostream>     // std::cout
#include <numeric>      // std::iota

int main () {
  int numbers[10];

  std::iota (numbers,numbers+10,100);

  std::cout << "numbers:";
  for (int& i:numbers) std::cout << ' ' << i;
  std::cout << '\n';

  return 0;
}


//atoi   convert a c-type string into a number
#include <iostream>      
#include <cstdlib>     

int main ()
{
  int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);

  i = atoi (buffer);

  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
  return 0;
}

*/


class Foo{
public:
	//vector in c++ has multiple possible methods to fill in
	//vector<int> cc(5)   here 5 is the size
	//vector<int> cc{1,2,3,4,5}   here we insert the elements
	//iota(cc.bigin(),cc.end(),1);   from 1 to fill the vector we must know the size at first

	//vector<bool>  cc(5, false);  here 5 elements are all false
	//fill_n(cc.begin(), 3, true);  here the first 3 elements are true and the last 2 are false
 	vector < vector<int> > go(int size, int window){
 		vector< vector<int> > result;
 		vector<int>  path;

 		dfs(size, window, 1, 0, path, result);

 		return result;
 	}

 private:
 	//start is the starting point of number, offset is the size of number already being selected
 	static void dfs(int size, int window, int start, int offset, vector<int> &path, vector<vector<int>> &result){
 		if(offset == window)//from 4 select 2 and we touchdown, record this successful path
 			result.push_back( path );

 		for(int i=start; i<=size; ++i)
 		{
 			//for the element as long as it is different from the preceding 
 			//then it is eligible so we do not need if condition to seive out the candidate
 			path.push_back(i);
 			//here we repeatedly calling the next recursion with different pattern
 			//so that we update our conditions and avoid repetitions
 			dfs(size, window, start+1, offset+1, path, result);

 			//attention:must pop_back so that we could use the single path without 
 			//create multiple path in a while loop to push_back different results;
 			//i.e. after we push_back the current path into result 
 			//even if we pop_back the path for the following use, the result has already
 			//recorded the previous record, which is space effecient

 			path.pop_back();
 		}
 	}
};