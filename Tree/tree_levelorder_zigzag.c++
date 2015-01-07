//we need a flag to indicate each time we should print left to right or reverse
//each level we flip this variable to pass to next level recursion

class Foo{
	vector<vector<int>> levelOrder_zigzag(TreeNode *root){
		vector<vector<int>> result;
		go(root, 1, result, true);
		//here we add one more variable in the recursion
		//i.e. the 4th variable which denotes the print order
		//true: left->right
		//false: right->left

		//reverse(result.begin(), result.end());
		//if we want to return and print out the level traversal from bottom to up
		return result;
	}

	void go(TreeNode *root, size_t level, vector<vector<int>> &result, bool left_to_right){
		if(!root)
			return;

		if(level > result.size())
			result.push_back(vector<int>());
		//we did not return here for printing up to bottom

		if(left_to_right)
			result[level-1] . push_back(root->val);
		else//store the level order from right to left
			result[level-1].insert(result[level-1].begin(), root->level);
		//although vector does not support directly push_front
		//we still could use insert with the begin() address to push_front

		go(root->left, level+1, result, !left_to_right);

		go(root->right, level+1, result, !left_to_right);
	}
}