//tip: we always use auto to receive some algorithm's return value
//like auto position = find(it1, it2, data);
//but advance or prev will not return anything
//we could only use individually like advance(it,3);

class Foo{
public:
	TreeNode *recover(vector<int> &preorder, vector<int> &inorder){
		return buildTree(preorder.begin(), prev(preorder.end()), inorder.begin(), prev(inorder.end()));
	}

	template<typename InputIt>
	//because different elements type stored in the vector
	//will result in differnet iterator -> we need to use template here
	TreeNode *buildTree(InputIt pre_first, InputIt pre_last, InputIt in_first, InputIt in_last){
		if(pre_first == pre_last)
			return nullptr;
		if(in_first == in_last)
			return nullptr;

		auto root = new TreeNode(*pre_first);
		//we begin to construct a new tree from the root

		auto rootpos_inorder = find(in_first, in_last, *pre_first);
		auto left_subtree_size = distance(in_first, rootpos_inorder);
		

		root->left = buildTree(next(pre_first), next(pre_first, left_subtree_size + 1,//+1 to jump over the root
								in_first, next(in_first, left_subtree_size)));

		root->right = buildTree(next(pre_first, left_subtree_size + 1), pre_last,
								next(rootpos_inorder), in_last);

		return root;
		//do not forget to return root 
		//and the root->left = statement above
	}
}