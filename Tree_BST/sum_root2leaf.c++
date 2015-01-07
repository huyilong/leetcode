//each root2leaf path represent a number
//add up all the path number to get the final sum

class Foo{
public:
	int sumNumbers(TreeNode *root){
		return dfs(root, 0);
	}

private:
	//we will return the final number
	int dfs(TreeNode *root, int sum){
		if(!root)
			return 0;

		//we must need to point out the basic operation
		//in the bottom level, i.e. leaf root
		//both left and right children are nullptr
		if(root->left == nullptr && root->right == nullptr){
			return sum*10 + root->val;
		}//last base case

		return dfs(root->left, sum*10 + root->val) + dfs(root->right, sum*10 + root->val);
		//every possible root2leaf path would be added up by calling this
	}
};