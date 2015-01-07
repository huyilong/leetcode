//left subtree could be less or equal to the node
//and right must be greater than the node
//every subtree should also be BST
class Foo{
public:
	bool isValidBST(TreeNode *root){
		return isValidBST(root, INT_MIN, INT_MAX);
		//initilize the sandwich could be anything, thus the sandwich should be infinite
		//for the root node of the whole tree
	}

	bool isValidBST(TreeNode *root, int lower, int upper){
		if(root == nullptr)
			return true;
		//touch down and return true

		return root->val > lower && root->val < upper
				&& isValidBST(root->left, lower, root->val)
				&& isValidBST(root->right, root->val, upper);
				//a series of boolean operation before returning
	}
}