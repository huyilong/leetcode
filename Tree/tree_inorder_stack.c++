class Foo{
	//inorder traversal always use stack
	//morris only use two assistant pointers
	//and thus it has a space complexity of O(1)
	//but using stack will result in a space usage of O(n)
public:
	vector<int> inorder(TreeNode *root){
		vector<int> result;
		//since it is a pointer pointing to another pointer
		//we do not need to use & since the pointer name itself is an address
		const TreeNode *p = root;
		stack<const TreeNode *> s;

		while(!s.empty() || p!=nullptr){
			//using or! either the stack has space or the pointer is not null
			if(p != nullptr){
				s.push(p);
				p = p->left;
			}else{

				p = s.top();
				s.pop();//this is poping out the ealiest one, which is reverse against queue
				//top() is the ealiest one
				//queue.front() is the oldest one
				result.push_back(p->val);
				p = p->right;
			}
		}

		return result;

	}
}