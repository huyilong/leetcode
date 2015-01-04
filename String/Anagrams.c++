//given an array of strings and return all groups of strings that are anagrams
//just mix of all the character of a string but
//the type and number of each character will remain unchanged -> sort at first and if equal

class Foo{
public:
	vector<string> anagrams(vector<string> &strs){
		//find the anagrams in the input strs?
		//and return them as a group : vector<string>
		unordered_map<string, vector<string>> groups;
		//each string will mapped to a group of its anagrams/snippets
		for(const auto &s : strs){
			string key =s;
			sort(key.begin(), key.end());//sort all the string elements ordered
			//after sorting, key now becomes a ordered key alphatically
			//bca -> abc now
			//but remember: key is sorted as common key
			//but s is still the unsorted original string used as value to insert
			groups[key]. push_back(s);
			//insert the sorted string into the hashmap/unodered_map in c++
		}
		//different values will be sorted as the same key to be saved in the same position
		//abc -> (cba),(bca).... they sorted to be saved as key and in the same key position

		//now we have to seiving 
		vector<string> result;
		//it is now an iterator for an unordered_map
		//it->second.size()
		for(auto it = groups.cbegin(); it != groups.cend(); ++it){
			//cbegin() and cend() are iterators pointing to const content 
			if(it->second.size()>1){
				//hava anagrams
				//using insert to do all the push_back in one round
				result.insert(result.end(), it->second.begin(), it->second.end());
			}
		}

		return result;
	}
}