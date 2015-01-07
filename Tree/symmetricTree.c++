class Foo{
public:
	bool isSymmetric(TreeNode *root){
		return root ? isSymmetric(root->left, root->right) : true;
		//if nullptr then directly return true
	}

	bool isSymmetric(TreeNode *left, TreeNode *right){
		if(!left && !right)
			return true;
		//this is always the terminal case
		//no matter for checking equal or isSymmetric
		//if operate to the last level i.e. left and right children are null
		//then we finally reach the success

		if(!left || !right)
			return false;
		//however, if we reach the place not synchronizedly
		//or in symmetric tree if have node must have a mirror

		return left->val == right->val && isSymmetric(left->left, right->right);
		//this is simulating the two trees within one tree
		//compared with the identical cheking between two trees
	}
};

//using iteration
class Bar{
public: 
	bool isSymmetric(TreeNode *root){
		if(!root)
			return true;

		stack<TreeNode *> s;
		s.push(root->left);
		s.push(root->right);
		//initialize the stack original state

		while(!s.empty()){
			auto p = s.top();
			s.pop();
			auto q = s.top();
			s.pop();

			if(!p && !q)
				continue; // this brach is ok, continue for other levels in recursions
			if(!p || !q)
				return false; // find one pair not ok, directly return result
			if(p->val != q->val)
				return false;

			s.push(p->left);
			s.push(q->right);

			s.push(p->riht);
			s.push(q->left);
			//be careful about the order!!!!
		}

		return true;
};

