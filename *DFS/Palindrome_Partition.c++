/*
They're not the same function, no.  std::fill fills a range, given a start and end iterator.

 std::fill_n fills a certain number of elements, given a start iterator and a quantity.  

 fill_n is useful for output iterators, when there's no way for you to get an end iterator, 
 such as with std::ostream_iterator:

std::fill( std::ostream_iterator<int>(std::cout), ???, x);
                                                  ^^^
                                           what do I put here?

std::fill_n( std::ostream_iterator<int>(std::cout), 25, x);

bool p[s.size()][s.size()];//dp need a larger matrix than the former one
fill_n (&p[0][0], n*n, false);// &p[0][0] is the initial iterator of the container
*/

class Foo{
public:
	vector<vector<string>> partition(string s){
		vector <vector<string>> result;
		vector <string> sub_result; //one possibility

		dfs(s,0,sub_result, result);//because the recursion is void and thus just return result

		return result;
	}

	//whenever met with a s[start] , dfs all the possibilities with starting from s[start]	
	void dfs(string &s, int start, vector<string> &sub_result, vector<vector<string>> &result){
		if(start == s.size())//touchdown and successfully find a possibility
		{
			result.push_back(s.substr(start, i-start+1));
			//here push in the final result
			return;
		}

		//if not touchdown
		for(int i=start; i<s.size(); ++i){
			if(isPalindrome(s,start, i))//i is a possible ending point
			{
				sub_result.push_back(s.substr(start, i-start+1));
				//for vector it is irreversable 
				//whenever push back once it is here for all the time even bounce back to last level
				//but the parameter would be reversable which each level has different values
				//here we try to push in the sub result
				//this is not the final version and could be popped back later to find new one
				dfs(s, i+1,sub_result, result);
				//i+1 will be used as a new starting point for next calling

				//reset and pop up the final character in current string
				sub_result.pop_back();
			}
		}

	}

	bool isPalindrome(string &s, int start, int end){
		while(start<end){
			if(s[start++] != s[end--])
				return false;
		}
		return true;
	}
};