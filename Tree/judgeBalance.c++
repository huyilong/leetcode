class Foo{
public:
	bool isBalanced(TreeNode *root){
		return isBalancedHelper(root) >= 0;
	}

	int isBalancedHelper(TreeNode *root){
		if(root == nullptr){
			return 0;
		}

		int left = isBalancedHelper(root->left);
		int right = isBalancedHelper(root->right);

		if(left<0 || right<0 || abs(left-right) > 1)
			return -1;

		return max(left,right) + 1;
		//why use max??
		//actually left and right are the indicators of each subtrees
		//left and right are the height of each subtree
		//and final judge statement is abs(left-right)
	}
}