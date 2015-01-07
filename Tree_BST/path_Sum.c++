//given a sum 
//determine all the sum from root to leaf path could be this sum
//return boolean 

class Foo{
public:
	bool hasPathSum(TreeNode *root, int sum){
		if(!root)
			//default value would be false
			return false;
		//because we will finally using || to combine the boolean

		if(root->left == nullptr && root->right == nullptr){
			return sum == root->val;//because at this time sum is already decrease to one node val
		}

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

//version 2: return all the candidates that satisfies the sum

class Bar{
public:
	vector<vector<int>> pathSum(TreeNode *root, int sum){
		vector<vector<int>> result;
		vector<int> intermediate;

		//one for 1d, one for 2d
		pathSum(root, sum, intermediate, result);
		return result;
	}

private:
	void pathSum(TreeNode *root, int gap, vector<int> &intermediate, vector<vector<int>> &result){
		if(!root)
			return;

		intermediate.push_back(root->val);
		//try this node


		if(root->left == nullptr && root->right == nullptr){
			if(gap == root->val)
				result.push_back(intermediate);
			//this 1d possibility is perfect!
		}

		pathSum(root->left, gap - root->val, intermediate, result);
		pathSum(root->right, gap - root->val, intermediate, result);

		intermediate.pop_back();
		//insert/erase
	}
}