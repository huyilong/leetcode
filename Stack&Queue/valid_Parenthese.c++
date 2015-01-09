//given a string only containing () {} [] chars
//determine if the input a series of valid parenthese

class Foo{
public:
	bool isValid(string const& input){
		string left = " ([{ ";
		string right = " )]} ";
	
		stack<char> s;

		//get out each char in input one by one from left to right
		for(auto check : input){
			//for the string it is also a container
			//and thus we do not need to use i to visit 
			//we just need to get one char each time and use auto char : string_name

			if(left.find(check) != string::npos)
			{
				//npos is the maximum value for size_t
				//because size_t is an unsigned integer
				//actually npos is -1 but for the unsigned it becomes the largest number
				s.push(check);
			}
			else{
				//the current position in input is not left parenthese
				//whenever we meet with this condition we need to find out a left parenthese
				//in the previous stack's top to match it
				if(s.empty() || s.top() != left[ right.find(check) ])
					return false;
				else
					s.pop();
			}
		}

		//the final criteria for judging the success is to see 
		//if all the elements are popped up in stack
		return s.empty();
	}
}