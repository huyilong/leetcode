struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr){}
};

class Foo{
public:
	void populateNext(TreeLinkNode *root){
		populateNext(root, nullptr);
	}

private:
	void populateNext(TreeLinkNode *root, TreeLinkNode *sibling){
		if(!root)
			return;
		else
			root->next = sibling;

		populateNext(root->left, root->right);
		//ok: next time sibling would not be nullptr anymore
		//the root will must right to nullptr

		if(sibling)
			populateNext(root->right, sibling->left);
		else
			//do not have siblings anymore
			//similar to the operation for the root node
			populateNext(root->right, nullptr);
	}
}