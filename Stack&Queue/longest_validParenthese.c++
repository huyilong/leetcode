//given a string of "((()))))(("
//return the length of the maximum valid substring
//"(()"
//return length = 2

class Foo{
public:
	int longestValidParenthese(string s){
		int max_len = 0 , last = -1;
		//the variable last will record the index of the last ")" in the string
		//and will skip all the interim non-matching ")"

		stack<int> index_lefts;
		//the stack will store the index of the left parentheses

		for(int i=0; i<s.size(); ++i){
			if(s[i] == "("){
				//string and vector both support the random visiting
				//and thus we could directly use the [] operator
				index_lefts.push(i);
				//we push the "(" into the stack
			}
			else{
				//if we meet with a ")"
				if(index_lefts.empty()){
					//if the current ")" does not have a matching parenthese in the stack
					//then we need to update our last to skip these invalid ")"
					last = i;
				}
				else{
					//if the current ")" has a matching parenthese in the stack
					//then we need to update our max_len
					//to calculate the current valid substring's length
					index_lefts.pop();
					
					//we firstly remove the current matching "("
					//if the removed one just now is the last matching "("
					//then we have caught a latest parenthese substring
					//and we need to update our max_len
					if(index_lefts.empty()){
						//if the left are empty 
						max_len = max( max_len, i-last);
						//we have caught a latest longest valid string
					}
					else{
						//we have other "(" left in the stack
						//but it is possible that the next one is still "(" 
						//so we need to update right now
						max_len = max(max_len, i - index_lefts.top());
						//actually here why we not +1
						//is that the current top() is already the previous one of the left 
						//parenthese we popped in the beginning 
						//and actually this is like index 0 -> the difference is directly distance
					}
				}
			}
		}
	}
}