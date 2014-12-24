class Workspace{
public:
	bool isBST(TreeNode* root){
		return isBST(root, INT_MIN, INT_MAX);
	}

	//overloading the function itself so as to recursion
	bool isBST(TreeNode* root,int lower, int upper)
	{
		if(!root)  return true; // root==nullptr
		return root->val > lower && root->val<upper
		&&isBST(root->left, lower, root->value) //  root->value is used as the upper for left subtree
		&&isBST(root->right, root->value , upper);// root->value is used as the lower for right subtree
	}

}obj;

//the obj is the object of this class 
// it is same as the statement::    Workspace obj;