//given an unsorted array [100,4,200,1,3,2]
//return the length 4 of longest consecutive sequence
//if we could use sorting at first we could O(nlogn)
//but if we need O(n), we must use hashmap

class Foo{
public:
	int longestConSeq(vector<int> const &num){
		unordered_map<int, bool> used;

		for(auto i: num)
			used[i] = false;

		int longest = 0;//declare out of the looping and therefore it is updated and compared in loop

		for(auto i : num){

			//this will save tons of time 
			//because if we find 2 in 12345
			//and we already saved the longest up to 5
			//when we met with 1,3,4,5 later on we do not need to count again 
			if(used[i]) continue;
			//if it is already used then continue
			//i.e. there are possible that here are dups or saving time for searching
			//we are trying to select each char and find its left and right

			int length = 1;
			//using the current visited place
			used[i] = true;

			//find its right j = i+1 
			//we need this number j to complete the right consecutive sequence
			for(int j = i+1; used.find(j) != used.end(); ++j){
				used[j] = true;
				//if we successfully find 
				++length;
			}

			//we need to find its left neighbor in the hashtable if there is one
			//here used.find(sth) != used.end() does not have any meaning
			//the used.end() is actually an iterator with null state
			for(int j = i-1;  used.find(j) != used.end(); ++j){
				used[j] = true;
				++length;
			}

			//do not use if to compare
			//just use max(longest, length)
			longest = max(longest, length);
		}

		return longest;
	}
}