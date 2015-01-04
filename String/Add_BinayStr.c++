//given two binary strings (stored in normal order)
//return their sum (also a binary string)
//a='11'
//b=' 1' (padding with zeros in the front? )

//change you mind: like judge whether the tree is contained in another tree
//find the in-order and pre/post-order or two trees and stored in strings
//then judge if both the traversals of one trees is the substrings of the other strings
//it is the excellent solution: i.e. firstly convert the problem to a easier and differen angle

//sum='100'

class Foo{
public:
	//this time is different from the atoi() method
	//we pass in c++ string rather than c string, which is an array of char[]
	string addBinary(string a, string b){
		string result;
		//firstly decide the final length of the result
		//however, the carry could be carried to the first bit then we can handle additionally
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());//we need to use the iterators(addresses) as the parameters
		reverse(b.begin(), b.end());
		//reverse them all for the adding up from right to left

		int carry = 0;
		for(size_t i = 0; i<n; ++i){
			const int ai = i < a.size() ? a[i] - '0' : 0;
			//padding with zeros or just convert it because it has a bit in this position
			const int bi = i < b.size() ? b[i] - '0' : 0;
			//because these two strings are not necessarily equal in length
			const int val = (ai + bi + carry) % 2;
			//using % with base will result in a val 
			carry = (ai + bi + carry) / 2;

			//this is very important that to insert at the beginning each time
			//also int + '0' will result in tha according char with according ASCII
			result.insert(result.begin(), val + '0');
		}

		if(carry == 1)//it overflows by 1 bit 
		{
			result.insert(result.begin(), '1');
		}
		//for c++ string there are many useful APIs like reverse(), insert() and iterators, etc

		return result;
	}

}