//divide and conquer
//precondition: the given array is sorted!!!

//height balanced BST!!! not a random one!!!

class Foo{
public:
	TreeNode* arrayToBST(vector<int> &num){
		return arrayToBST(num.begin(), num.end());
	}

	template<typename InputIt>
	TreeNode* arrayToBST(InputIt first, InputIt last){
		const auto length = distance(first, last);

		if(length == 0)
			return nullptr;
		if(length == 1)
			return new TreeNode(*first);
		//only have one node left 
		//just create it and return 
		//this is the base condition

		auto mid = first + length/2;
		//divide and conquer
		//this is a sorted array!!!!

		TreeNode *root = new TreeNode(*mid);
		//to ensure that the height of BST is minimum
		//and also balanced height
		root->left = arrayToBST(first, mid);
		root->right = arrayToBST(mid+1, last);

		return root;


	}
}