//the candidates could be used more than once
class Foo{
public:
	vector<vector<int>> combinationSum(vector<int> &nums, int target){
		sort(nums.begin(),nums.end());
		//actually here sort does not have too much value
		//but for not repetition in II it is important
		//so that we only need a previous variable to avoid repetition
		vector<vector<int> > result;
		vector<int> sub_result;
		dfs(nums, target, 0 ,sub_result, result);
		return result;
	}

private:
	//gap is the target - cureent sum, which is the distance before getting the final sum
	//start is the starting point of the candidates group
	//which start is working as the index to choose different nums
	void dfs(vector<int> &nums, int gap, int start, vector<int> & sub_result, vector<vectro<int>> &result){
		if(gap == 0){
			result.push_back(sub_result);
			return;
		}

		for(size_t i=start; i<nums.size(); ++i){
			if(gap < nums[i])
				return;//illegal, if add this number the result will overflow
		}

		sub_result.push_back(nums[i]);

		dfs(nums, gap-nums[i] , i, sub_result, result);
		//directly use the current i as the next starting point to search
		//and the gap - nums[i] as the new gap 

		sub_result.pop_back();
	}
};

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
	void dfs(vector<int> &nums, int gap, int start, vector<int> & sub_result, vector<vectro<int>> &result){
		if(gap == 0){
			result.push_back(sub_result);
			return;
		}

		//the above coding is same as the last program
		int previous = -1;//avoid repetition of the same use of the same number
		for(size_t i=start; i<nums.size(); ++i){
			if(previous == num[i])
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

};

