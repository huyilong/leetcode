//ASCII has 128 in original 
//where 0 is 48, A is 65, a is 97
//however, later on it is expanded to 256 where there are more tokens

//this is very similar to the problem in CC, which is also checking for the
//repeated char in two strings
//create a array where the index is from 0 - 256

class Foo{
public:
	//find the minWindow length in S that contains all the char in T 
	//the char could be unordered and littered with non-T char 
	//because the window must be continuous -> might contain irrevalent
	string minWindow(string haystack, string needle){
		if(haystack.empty())
			return "";
		//if not found return empty string
		if(haystack.size() < needle.size())
			return "";
		//if haystack is even smaller than target, just directly cannot found

		const int ASCII_SIZE = 256;
		int appeared_count[ASCII_SIZE];
		int expected_count[ASCII_SIZE];

		//initialize appeared with 0
		fill(appeared_count, appeared_count+ASCII_SIZE, 0);
		//here appeared_count is v.begin() :: &arr[0]

		//initialize the expected with target 1 and else 0
		fill(expected_count, expected_couny+ASCII_SIZE, 0);
		for(size_t i=0; i<needle.size(); ++i){
			//this is wrong
			//expected_count[ needle[i] ]  = 1;

			expected_count[ needle[i] ] ++;
			//because it is possible that there are dups
			//so the value is not just whether appear or not
			//it is the detailed times

			//for those appeared 
			//we directly convert the char to ASCII as index in the 256 arr and set the 
			//value to 1
		}

		int minWidth = INT_MAX, min_start = 0;
		//the window we desired, its length and its starting point
		int win_start = 0;
		int win_end = 0;
		int appeared = 0;//appeared is designed to stop when contain a whole needle

		//moveforward the tail ptr
		for(win_end=0; win_end<haystack.size(); win_end++){
			if(expected_count[ heystack[win_end] ] == 1)//find a possible char in haystack
			{
				//now the appeared arr also increased its element to times each time found
				appeared_count[ heystack[win_end] ] ++;
				//appeared times in the current window in haystack 
				//if(appeared_count[ heystack[win_end] ] <= 1)

				if(appeared_count[ heystack[win_end] ] <= expected_count)
					appeared ++;
			}

			//this is always happening
			if(appeared == needle.size()){
				//completely match the needle we will go into this part
				while(appeared_count[ heystack[win_start] ] > expected_count[heystack[win_start]]
						|| expected_count[heystack[win_start]] == 0)
				{
					//now we truncate the string by move forward the head ptr
					//the redundant and non-relevant will be dropped
					appeared_count[ heystack[win_start] ] --;
					win_start++;
				}

				//this is also contained in the appeared == needle.size() block
				//update the outside variable
				if(minWidth > (win_end - win_start +1)){
					minWidth = win_end - win_start + 1;
					min_start = win_start;

					//update the win_start to the current window size start
				}
			}
		}

		if(minWidth == INT_MAX)
			//IT IS NEVER FOUND AND UPDATED
			return "";
		else
			return heystack.substr(min_start, minWidth);
	}
}