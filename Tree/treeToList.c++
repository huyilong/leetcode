class Foo{
public:
	void treeToList(TreeNode *root){
		if(root == nullptr)
			return;

		treeToList(root->left);
		treeToList(root->right);

		if(root->left == nullptr)
			return;//we are trying to each left subtree connected with the beginning of right subtree

		TreeNode *p = root->left;//to the final level and let the last left child become the tail of list
		while(p->right)
			p = p->right;
		//the last node in left tree is the rightmost node leaf of the left subtree

		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
		//then insert the left tree between the root and root->right
	}
};

//iteration's time complexity and space complexity would be the same with recursion
class Bar{
public:
	void treeToList(TreeNode *root){
		if(root==nullptr)
			return;

		stack<TreeNode *> s; //a stack storing pointers for treenode
		s.push(root);

		while(!s.empty()){
			auto p = s.top();
			s.pop();
			//get and remove need two operations for queue and stack
			//auto p = q.front()
			//q.pop();
			//pop() will be different for queue and stack

			if(p->right)
				s.push(p->right);//FILO

			if(p->left)
				s.push(p->left);


			p->left = nullptr; //break connection
			//if ! not while!
			if(!s.empty()){
				//the current node p would be connected with the following nodes in the stack
				p->right = s.top();

			}
		}
	}
};

