#include <iostream>
#include <vector>
using namespace std;

class Foo{
public:
	vector<string> Parenthese_generator(int n){
		//left parenthese must be <= n
		//right parenthese must be <= left
		vector<string> result;
		if(n>0)
			generate(n, "", 0, 0, result);
		return result;
	}

	//note: this is void because we pass in the result as a parameter and therefore
	//it could directly alter the vector if only we do not use pop_back in this snippet
	void generate(int n, string s , int l, int r, vector<string> &result){
		if(l==n)//base case
		{
			//because we will firstly insert in all the left parenthese
			//and then bounce back to call other recursions
			//therefore we need to if(l==n)
			result.push_back(   s.append(n-r, ')')  ); 
			
			cout<<"hah"<<endl;
			copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));

			//n-r is the position, different level would have multiple choices

			//this is real operation
			//and only add ) in the final result
			//other result is updated by passing in the parameters

			//this if snippet is only for the ( is touchdown
			//and then right parenthese would be begining insert

			//in which time l==n is always satisfied??? this is wrong!!
			//this snippet is only for one operation, i.e. the base case!!!

			//i.e. left is one time push_back with first call of this 
			//but right is one by one inserted
			return;
			//bounce back
		}

		generate(n, s+'(', l+1, r, result);
			//every level execute this to jump to next level until l = n

		if(l>r){
			generate(n, s+')', l, r+1, result);
		}
	}
};


int main(int argc, char **argv){
	Foo test;
	vector<string> result;
	//Foo *test = new Foo
	//test -> Parenthese_generator()
	result = test.Parenthese_generator(4);
	copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));

}

