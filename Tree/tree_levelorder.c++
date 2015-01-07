/*
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x) , left(nullptr), right(nullptr){}
};
*/

//in/pre/in means that the position of middle node printed out

//list could be easily changed to array in java
//   Array.aslist( listname )
//before the . is the object you want to reach
//actually like Integer.parseInt(char/string)


//recursion and iteration both have a time complexity of O(n)
//but iteration has a space complexity of O(1) while recursion has O(n)
class Foo{
public:
	//we need to return the different level at the end
	vector<vector<int>> levelOrder(TreeNode *root){
		vector<vector<int>> result;
		go(root, 1, result);
		//reverse(result.begin(), result.end());
		//if we want to return and print out the level traversal from bottom to up
		return result;
	}

	void go(TreeNode *root, size_t level, vector<vector<int>> &result){
		if(!root)
			return;

		if(level > result.size())
			result.push_back(vector<int>());
		//attention!!!! : we did not return here!
		//therefore the final result will have a level traversal from top to bottom

		//each time run into the next level we need to push a new 1d array into the final result
		//although it is empty

		result[level - 1].push_back(root->val);//level is always 1 more bigger than the index of result

		go(root->left, level+1, result);
		go(root->right, level+1, result);
	}
};

class Bar{
public:
	vector<vector<int>> levelOrder(TreeNode *root){
		vector<vector<int>> result;
		if(root == nullptr)  
			return;

		queue<TreeNode* >  current, next;

		vector<int> level; // elements in each level

		current.push(root);
		while(!current.empty()){
			while(!current.empty()){

				TreeNode* node = current.front();//for the queue we could use front

				//using front() to get the oldest one or print
				//using pop() to remove the oldest one
				current.pop();
				/*
				 do {
    					std::cin >> myint;
   					    myqueue.push (myint);
  					} while (myint);

  				std::cout << "myqueue contains: ";
  				while (!myqueue.empty())
  				{
 				   std::cout << ' ' << myqueue.front();
 				   //the front is trying to visit the oldest element in the queue
 				   myqueue.pop();
 				   //pop() will remove the oldest element in the queue
 				   //which is counter to the rule in stack
 				 }
 				 */

 				 level.push_back(node->val);
 				 if(node ->left != nullptr)
 				 	next.push(node->left);

 				 if(node->right != nullptr)
 				 	next.push(node->right);
			}

			result.push_back(level);

			level.clear();//remove all the elements in the current level 1d vector
			//for the following use because it is already stored in 2d result
			//otherwise we need to create n new level 1d vector to store each level
			//which is not effecient

			swap(next, current);
		}

		//reverse(result.begin(), result.end());
		//if we want to return and print out the level traversal from bottom to up
		return result;

}


/*

//using level and each time from the root and minus 1
//then minus level times we actually reach the levelth level
void printGivenLevel(struct node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->data);
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}
*/