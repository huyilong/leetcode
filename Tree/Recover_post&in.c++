class Foo{
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
		return buildTree(inorder.begin(), prev(inorder.end()), postorder.begin(), prev(postorder.end()));

	}

	template<typename InputIt>
	TreeNode *buildTree(InputIt in_first, InputIt in_last, InputIt post_first, InputIt post_last){
		if(in_first == in_last)
			return nullptr;
		if(post_first == post_last)
			return nullptr;


		auto root = new TreeNode(*prev(post_last));
		//the root is in the last element of postorder and the first element of preorder

		auto rootpos_inorder = find(in_first, in_last, *prev(post_last));
		auto left_size = distance(in_first, rootpos_inorder);
		//for the distance we need to use next() to move forward the final pos
		auto post_left_last = next(post_first, left_size);

		root->left = buildTree(in_first, rootpos_inorder, post_first, post_left_last);

		root->right = buildTree(next(rootpos_inorder), in_last, post_left_last, prev(post_last));

		return root;
	}
}