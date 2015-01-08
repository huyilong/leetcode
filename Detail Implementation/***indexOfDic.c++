//S="barfoothefoobarman"
//L=["foo","bar"]
//each word are equal length
//return index(0, 9)
//0 find "barfoo", 9 find "foobar"

class Foo{
public:
	//the return is a vector of all starting indexes in the original string
	vector<int> difficult(string s, vector<string> &dict){
		size_t word_length = dict.front().length();
		//all string in dic have same length
		size_t target_length = word_length * dict.size();
		//dict is a vector like ["foo","bar"]

		vector<int> result;
		unordered_map<string, int> wordCount;

		for(auto const &word : dict){
			++ wordCount[word];
		}

		for(auto i = s.begin(); i<=prev(s.begin(), target_length); ++i){
			unordered_map<string, int> unused(wordCount);
			//copy the map with constructor
			//unused is like the gap in sum problem 
			//each time when we find one we would remove/erase one of the unused element
			for(auto j = i; j!=next(i, target_length); j = word_length + j)
			{
				auto pos = unused.find( string(j,next(j, word_length)) );

				if(pos == unused.end() || pos->second == 0)
					break;
				//for map if not find then using unused.end()
				//just like -1 for indexOf(substring)

				if(--pos->second == 0)
					unused.erase(pos);
			}

			if(unused.size() == 0)//gap becomes 0, terminal signal
				result.push_back( distance(s.begin(), i));
				//we are putting in the indexes of all eligible candicate
		}

		return result;
	}
}