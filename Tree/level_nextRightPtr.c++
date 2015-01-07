//this is a follow up for populating next right pointers in each code
//and this time the tree is any binary tree but not necessarily BST
//if it does not have a sibling or neighbor then node->right = nullptr;
//i.e. apart from node->left and node->right
//we also have node->next here for its right sibling
class Foo{
public:
	void go(TreeNode *root){
		vector<vector<TreeNode *>> result;
		//be careful of the syntax!!!
		//the result element would be the pointer to the nodes
		bfs(root, 1, result);

		for(auto level: result){
			//we could not use ptr_iter < level.end() here!!
			//because we actually left out the last node in each level for specail operation
			//out side of this loop but before the next round of the next outer loop
			for(auto ptr_iter = level.begin(); ptr_iter != prev(level.end()); ++ptr_iter)
			{
				//for each node on each level except the last one
				//we will make its next point to its sibling
				(*ptr_iter) -> next = * next(ptr_iter);
			}

			//for the last one in the level
			//before go into the next round of outer looping
			(*ptr_iter) -> next = nullptr;
			//or use (* prev(level.end())) -> next = nullptr
		}

	}

	void bfs(TreeNode *root, size_t level, vector<vector<TreeNode *>> &result){
		if(!root)
			return;

		if(level > result.size())//level is always one more than the index of the result
			result.push_back(vector<TreeNode *> ());
		//we will firstly each time push a new empty 1d vector into the result
		//from top to bottom
		//here we not return!!!

		result[level-1].push_back(root);

		bfs(root->left. level+1, result);
		bfs(root->right. level+1, result);

	}
};