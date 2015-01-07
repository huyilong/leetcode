//the candidates could only be used once
#include <iostream>
#include <vector>
using namespace std;
class Bar{
public:
	vector<vector<int>> combinationSum(vector<int> &nums, int target){
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> sub_result;
		dfs(nums, target, 0 ,sub_result, result);
		return result;
	}

private:
	void dfs(vector<int> &nums, int gap, int start, vector<int> & sub_result, vector<vector<int>> &result){
		if(gap == 0){
			result.push_back(sub_result);
			return;
		}

		//the above coding is same as the last program
		int previous = -1;//avoid repetition of the same use of the same number
		//??how does this work to avoid multiple use of same element?
		for(size_t i=start; i<nums.size(); ++i){
			//try each candidate in the nums group
			if(previous == nums[i])
				continue;
			//avoid repetition???  

			if(gap<nums[i])
				return;

			//update the previous to current new used position
			previous = nums[i];

			sub_result.push_back(nums[i]);
			dfs(nums, gap-nums[i], i+1, sub_result, result);

			sub_result.pop_back();//resume the environment
		}
	}

};

int main(){
	vector<vector<int>> printout;
	vector<int> input({ 10,1,2,7,6,1,5}); //have multiple ones???
	//avoid multiple ones in final result? or multiple usage of single element but allow repetition elements
	Bar test;
	printout = test.combinationSum(input, 8);

	for(auto sub_result : printout){
		//hence each sub_result is a 1d vector<int>
		copy(sub_result.begin(), sub_result.end(), ostream_iterator<int>(cout," "));
		cout<<endl;
	}

	/*
	1 1 6 
	1 2 5 
	1 7 
	2 6
	*/ 
}
