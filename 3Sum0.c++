#define SAVE_TIME 2
#include <iostream>
#include <vector>
#include <algorithm>
/*
#ifndef _INCL_GUARD
#define _INCL_GUARD
#endif
*/
using namespace std;
//尽量养成习惯 因为在java里面就必须保证class的名字和整个file的名字一样才能编译
//但是这里不行  因为不能把class的name以数字开头！！会报错！！！
class Sum0{
public:
	//input is 1D vector then the output will be a 2D vector
	static vector< vector<int> > go(vector<int> & num)
	{
		vector< vector<int> > result;
		if(num.size() < 3 )  return result;//corner condition

		sort(num.begin(),num.end());
		//because the elements stored in the container is bulit-in type 
		//therefore we do not need to override the < operator or self define class as callable object
		const int target = 0;

		auto last = num.end();
		//operation over the iterator of the vector
		//error:: cannot split up the for statement into two seperate rows even if it is too long
		for(auto a =num.begin(); a<prev(last, SAVE_TIME); a = upper_bound(a,prev(last), SAVE_TIME))
		//avoid all hard-coding
		{
			for(auto b= next(a) ; b<prev(last); b = upper_bound(b,prev(last),*b))
			{
				const int c = target - *a - *b;// because a and b are iterators, i.e. addresses
				//calling STL fundtion to save labour and time
				//binary search's time complexity is O(log n)
				if(binary_search(next(b),last,c))
					result.push_back(vector<int> {*a, *b, c});
				//note:: for pair/tuple/vector we cannot use "=" to initialize
				//except for char * ptr = "hello" is legal and same with char[20] = "hello"
				//for vector/tuple/pair we need the directly constructor with the definition of them
			}
		}
		return result;
	}
};

int main(int argc, char** argv)
{
	//do not need troublesome push_back anymore
	//or we can use fill/etc algorithm to use particular pattern to fill the vector 
	vector<int> test {-1, 0, 1, 2, -1, -4 };
	copy(test.begin(),test.end(), ostream_iterator<int>(cout," "));
	//calling the static method within the class without instantiate it with an object
	//just directly use the class name before the function as the scoping operator is enough
	vector< vector<int> > printout;

	printout = Sum0::go(test);

	//debug:: check out the dimensions of the 2d matrix
	cout<<printout.size()<<endl;
	cout<<printout[0].size()<<endl;
	
	for(int i =0 ; i < printout.size(); ++i)
	{
		for (int j=0; j<printout[0].size(); ++j)
		{
			cout<<printout[i][j]<<" ";
		}
		cout<<endl;
	}


}