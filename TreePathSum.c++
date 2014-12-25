 class Foo{
 public:
 	bool hasSum(Node * root, int sum)
 	{
 		if(root == nullptr)   return false;  ///it is an empty tree

 		if(root -> left ==nullptr && root ->right == nullptr)
 			 return sum == root ->val;

 		//recursive to call itself
 		return hasSum(root->left, sum - root->val) || hasSum(root->right, sum- root->val);
 	}
 };