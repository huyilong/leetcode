/*
void go(TreeNode *root){
		vector<vector<TreeNode *>> result;
		bfs(root, 1, result);

		for(auto level: result){
			
			for(auto ptr_iter = level.begin(); ptr_iter != prev(level.end()); ++ptr_iter)
			{
				
				(*ptr_iter) -> next = * next(ptr_iter);
			}

			(*ptr_iter) -> next = nullptr;
			//or use (* prev(level.end())) -> next = nullptr
		}
	}

	+

	recurisive bfs()
*/

class Foo{
public:
	void populate_SiblingPtr(TreeNode *root){
		vetor<vector<int>> result;
		if(root == nullptr)
			return;

		vector<TreeNode *> next, current;
		//two queues to swap later on for level traversal
		current.push_back(root);
		//initialize for the initial operation
		while(!current.empty()){
			while(!current.empty()){
				TreeNode *FIFO = current.front();
				current.erase(current.begin());

				//here we need different operation
				if(!current.empty()){
					FIFO -> next = current.front();
				}else{
					FIFO -> next = nullptr;
				}

				if(FIFO -> left != nullptr){
					next.push_back(FIFO -> left);
				}
				if(FIFO -> right != nullptr){
					next.push_back(FIFO -> right);
				}
			}
			swap(next, current);
		}
	}
}