class Foo{
public:
	int minDepth(const TreeNode *root){
		return minDepth(root, false);
	}

private:
	static int minDepth(const TreeNode *root, bool hasbrother){
		if(!root)
			return hasbrother ? INT_MAX : 0;

		return 1 + min(minDepth(root->left, root->right!=nullptr), 
									minDepth(root->right, root->left!=nullptr));
	}
};

//using stack
//space complexity O(logn)

class Bar{
public:
	int minDepth(const TreeNode *root){
		if(!root)
			return 0;

		int result = MIN_MAX;
		//for the following update


		stack< pair<TreeNode *, int> > s;
		s.push(make_pair(root, 1));

		while(!s.empty()){
			auto node = s.top().first;
			auto depth = s.top().second;
			s.pop();

			if(node->left == nullptr && node->right == nullptr)
				result = min(result, depth);
			//for every node in the tree
			//we check if it is the leaf node
			//and whenever it is a leaf node we will update result
			//by using result = min(result, current_depth)
			//if current_depth is bigger, it will have no impact over result

			if(node->left && result>depth)//prune
				s.push(make_pair(node->left, depth+1));

			//not every node is candidate 
			//only that will not exceed the current depth

			if(node->right && result>depth)
				s.push(make_pair(node->right, depth+1));
		}

		return result;
};

