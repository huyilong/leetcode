// scramble of the string could be established by choose any non-leaf node and swap its two children
#include <iostream>
#include <string>
#include <iterator>

using namespace stdl
class Foo{

public:
	//GUI interface called by the user and initiate the recursive in private
	bool go(strng s1, string s2){
		return go( s1.begin(), s1.end(), s2.begin() );
	}

private:
	//following interface called with actual input in public function
	//also need the same name to override
	//Note: auto cannot used in the prototype of function, i.e. cannot use auto in def of func
	typedef string::iterator It;

	bool go( It f1, It e1, It f2)
	{
		//every time recursive need to update the new length between f1 and e1
		// firstly the length is the whole length of the string and then be truncated
		auto length = distance(f1, e1);
		// move e2 to the complementary position related to string1
		auto e2 = advance(f2, length);

		//base case  -> the last stack and we know the anwser then bounce back to the 
		//preceding stacks until bounce back to the main func to return the final result
		if(length == 1)   
			return *f1 == *f2;

		for(int i=1; i<length; ++i)
		{
			if(( go(f1,f1+i,f2) && go(f1+i,e1,f2+i) )|| (go(f1,f1+i,e2-i) && go(f1+i,e1,f2))))
			return true;
		}

		return false;
	}
}