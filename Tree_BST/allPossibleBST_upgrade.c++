//not degrade the performance
//not compromise the performance
class Foo{
public:
	vector<TreeNode*> createAllBST(int n){
		//n is the number of elements starting from 1,2,3,4...n
		if(n==0)
			return go(1,0);

		return go(1,n);
	}

private:
	vector<TreeNode *> go(int start, int end){
		vector<TreeNode *> subTree;
		if(start > end){
			subTree.push_back(nullptr);
			//using nullptr to denote the gao between two possible subtrees?
			return subTree;
			//because subtree is not a parameter but our inner variable
			//we need to return this rather than just return;
		}

		for(int k= start; start<=end; ++start){
			vector<TreeNode *> leftSubs = go(start, k -1);
			vector<TreeNode *> rightSubs = go(k+1, end);
			for(auto i :leftSubs){
				for(auto j : rightSubs){
					TreeNode *new_node = new TreeNode(k);//each time just insert one node with val k
					new_node->left = i;
					new_node->right = j;
					subTree.push_back(new_node);
				}
			}
		}
		
		return subTree;
	}

}