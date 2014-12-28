#include <unordered_map>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>  //std::copy
#include <iterator>

using namespace std;
//the problem requires a time complexity as O(n) therefore we cannot firstly sort the sequence
// if we firstly sort it and then check the constinuity the complexity will be O(n*logn)
//{1,133,244,2,4,5,3,333}  return 5 :: i.e. {1,2,3,4,5}
class ConsecutiveSeq{
public:
	//always using const & reference to the object passed in
	int longest(vector<int> const& num)
	{
		unordered_map<int, bool> visited;
		for(auto i : num )//auto self-defined name : the name of the container
		{
			visited[i] = false;
		}
		int longest = 0;
		for(auto i : num)
		{
			if(visited[i])  continue;  // it is possible that the container has repeated value
			// if the value has already been used in previous calculation -> do not waste time
			//also it is used in {1,2,3,4,5} for 1 it will visit 2,3,4,5 then we will not visit
			//2,3,4,5 to calculate afterwards

			int length = 1; //local length for each iteration
			visited[i] = true; //flip the visited state

			//because the index of the key in hashmap is the value stored in the original array/vector
			//then we directly find its neighbors from it to the left and to the right until disconnected
			for(int j = i+1; visited.find(j) != visited.end() ; ++j)
			{
				//if we find a neighboring j then flip its state
				visited[j] = true;
				++length; //update the local longest version
			}

			//really not wrong??
			//instead of using visited.find(j) != visited.begin()???
			//actually there visited.end() is just used as NULL, not particularly the direction
			for(int j = i-1; visited.find(j) != visited.end() ; --j)
			{
				visited[j] = true;
				++length;
			}

			longest = max(longest, length);
		}
		return longest;
	}
};

int main(int argc, char* argv[])
{
	vector<int> unsorted_list;
	unsorted_list.push_back(100);
	unsorted_list.push_back(4);
	unsorted_list.push_back(200);
	unsorted_list.push_back(1);
	unsorted_list.push_back(3);
	unsorted_list.push_back(2);
	//the following statements is wrong
	//because the ostream_iterator is a template and thus needs a type explicitly
	//copy(unsorted_list.begin(), unsorted_list.end(), ostream_iterator(cout, " "));
	copy(unsorted_list.begin(), unsorted_list.end(), ostream_iterator<int>(cout, " "));

	ConsecutiveSeq find_longest_consecutive_sequence;
	int result = find_longest_consecutive_sequence.longest(unsorted_list);
	//or declared the method within the class with static
	//then you can directly use the method without instantiate the class with an object
	//just use the scoping operator before the method is adequate
	// such as ConsecutiveSeq::longest(unsorted_list);
	cout<<"the longest ConsecutiveSeq of {100,4,200,1,3,2} is "<< result <<endl;

	return 0;
}

