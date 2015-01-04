/*
vetor<iny> a({1,2,3,4})
//2d matrix needs two big brakets
vector<vector<int> > b(  { {1,0,1,1,1}, {0,1,1,0,0}, {1,1,1,0,0} }  );
*/

//vertically check 
class Foo{
public:
	string longestCommonPrefix(vector<string> &strs){
		if(strs.empty())
			return ""; // the common prefix is ""

		//every time vertically compare all the same positions of the strings
		//until meet with one conflict 
		for(int i =0; i <strs[0].size(); ++i){
			for(int ii=0; ii<strs.size(); ++ii){
				//every time compare with strs[0] will be enough
				if(strs[ii][i] != strs[0][i])
					//i is still not increased and thus just return the longest prefix substring
					return strs[0].substr(0,i);
			}
		}
	}
};

//every time the string would compare with the str[0] from the head to tail until 
//meet with a conflict
class Bar{
public:
	string longestCommonPrefix(vector<string> &strs){
		if(strs.enmpty())
			return "";
		int right_most = strs[0].size();
		/*
		these are just synonyms.  size() is there to be consistent with other STL containers
		 (like vector, map, etc.) and length() is to be consistent with most peoples' intuitive 
		 notion of character strings. People usually talk about a word, sentence or paragraph's 
		 length, not its size, so length() is there to make things more readable.
		 */

		 //get out the second string from the vector so that it would be compared with the first one
		 for(size_t i=1; i<strs.size(); i++){
		 	for(int j=0; j<=right_most; j++){
		 		//because we trying to find the minmax so that we do not need to 
		 		//every time compare the current with last right_most : we just get the shortest
		 		if(strs[i][j] != strs[0][j])
		 			//update the right_most variable
		 			right_most = j - 1;
		 	}
		 }

		 return strs[0].substr(0, right_most+1);
	}


}