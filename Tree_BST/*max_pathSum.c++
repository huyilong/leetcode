//note: the node could begin at any point
//and the path could be zigzag like left -> root -> right

class Foo{
public:
	int maxPathSum(TreeNode *root){
		max_sum = INT_MIN;
		dfs(root);

		return max_sum;
	}

private:
	int max_sum;
	//declare it as a global varible so that we do not need to return between levels in recursion
	int dfs(const TreeNode *root){
		if(!root)
			return 0;
		int l = dfs(root->left);
		int r = dfs(root->right);

		int sum = root->val;

		//before update the sum in the current root
		//we need to judge whether l or r are bigger than 0
		if(l>0)
			sum+ = l;
		if(r>0)
			sum+ = r;
		//because we could both visit the two children of one node
		//we do not use else if here
		max_sum = max( max_sum , sum);
		return max(r,l) > 0 ? max(r,l) + root->val : root->val;
		//whether erase the previous result or add based on it
	}
}