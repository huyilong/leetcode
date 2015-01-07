//the path could be started at any point in the tree
//but the path could not be zigzag
//i.e. it could left -> middle -> right pattern
//i.e. each level we could only use one number

void findSum(TreeNode node, int sum){
	int depth = depth(node);
	int[] path = new int[depth];
	findSum(node, sum, path, 0);
}

void findSum(TreeNode node. int sum, int[] path, int level){
	if(node == null)
		return;


	path[level] = node.data;
	//we try each node on each level
	//we will remove this one if it is not eligible
	//and also for the following checking

	int check = 0;
	for(int i = level; i>=0; --i){
		check+ = path[i];//we backtracking to add the sum
		//which will avoid that all of our path begins at the root node
		if(check == sum){


			//find one, print one -> do not store in 2d vector or arraylist
			//this method is better
			print(path, i, level)
			//level actually is the ending point
			//and i is the beginning point by backtracking
		}
	}

	findSum(node.left, sum, path, level+1);
	findSum(node.right, sum, path, level+1);

	//after the calling and all the operation
	//before next calling
	path[level] = Integer.MIN_VALUE;
}

int depth(TreeNode node){
	if(!node)
		return 0;
	else{
		return 1 + Math.max(depth(node.left), depth(node.right));
	}
}

void print(int[] path, int start, int end){
	for(int i = start; i<=end; ++i){
		System.out.print(path[i] + " ");
	}
	System.out.println();
}
