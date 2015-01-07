//this requires the structure should also be identical
//the time complexity O(n) and space complexity is O(logn)

class Foo{
public:
	bool isSameTree(TreeNode *p, TreeNode *q){
		if(!p && !q)
			return true;

		if(!p || !q)
			return false;
		//&& above and || bottom then we will implement that || is the real world logic
		//i.e. either a or b but cannot be both a and b

		//place the most narrow logic checking in the above
		//after all checking return true

		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

//using iteration with stack
//also we need O(logn)

//sometimes the interviewer will let you use stack rather than recursion
class Bar{
public:
	bool isSameTree(TreeNode *p, TreeNode *q){
		stack <TreeNode *> s;
		//i.e. if we want to store p & q these addresses(pinters)
		//we need to use TreeNode * to receive them
		s.push(p);
		s.push(q);

		while(!s.empty()){
			p = s.top(); 
			s.pop();
			q = s.top();
			s.pop();
			//in queue and stack 
			//get element and remove element are two operations
			//we need to do them seperately

			if(!p&&!q)  continue;
			if(!p || !q)  return false;
			if(p->val != q->val)  return false;

			s.push(p->left);
			s.push(q->left);
			s.push(p->right);
			s.push(q->right);

		}

		return true;


};

